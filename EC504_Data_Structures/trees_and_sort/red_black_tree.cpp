#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>

using namespace std;

typedef string NodeKey;

typedef string NodeData;

enum ColorType
{
	red,black
};

class Node{
  public:
  	Node * right, * left, *parent;
  	NodeKey key;
  	NodeData data;
  	ColorType color;

    Node();
    Node(NodeKey);
    Node(NodeKey,NodeData);
};

Node::Node(){
	left = right = parent = nullptr;
}

// Sentinel.
Node nil;

Node::Node(NodeKey k){

  key=k;
  left = right = parent = &nil;

}

Node::Node(NodeKey k,NodeData d){
  key=k;
  data=d;

  left = right = parent = &nil;

}




const int MAXDEPTH = 1000;
struct Tree{
   Node * root;

   int maxdepth;
   array<int,MAXDEPTH> nodecount;

   Tree(){
   	 root = &nil;
     maxdepth=-1;
     for (int ii=0; ii < MAXDEPTH; ii++)
        nodecount[ii] = 0;
   }
};


void printnode(Node *p,bool color=false){
  if (p != &nil){
    cout << "k: " << p->key ;
    if (!(p->data).empty())
       cout << ", d: " << p->data;
    if (color){
        cout << ", c: " << ((p->color == red) ? "red" : "black");
    }
    cout << ", l:" << p->left->data;
    cout << ", r:" << p->right->data; 
    cout << ", p:" << p->parent->data;
    cout <<endl;
  }

}

void inorderwalk(Node * p){
  if (p != &nil){
    //cout << p->left << endl;
    inorderwalk( p->left);

    printnode(p,true);

    
    inorderwalk( p->right);
  }


}

void inorderwalk_tree(Tree T){
  inorderwalk(T.root);
}

// left_rotate(T,x)
//         /                      /
//        x                      y
//     a    y      -- >        x   c 
//         b c                a b
//

void left_rotate(Tree &T,Node* x){
 Node* y=x->right;  

// move b in place       //           
 x->right = y->left;     //     /       y
 if (y->left != &nil)    //    x         c
    y->left->parent =x;  //   a b
 
 // attach y to tree: set y's parent and y's parent child
 y->parent = x-> parent;
                                //              /
 if (x->parent == &nil)         //             y 
   T.root = y;                  //    x         c
 else if (x == x->parent->left) //   a b
   x->parent->left = y;         //
 else
  x->parent->right = y;


// attach x to y
y->left=x; 
x->parent=y; 


}
// right_rotate(T,y)
//     \ or /                  \ or /
//        x                      y
//     a    y      <---        x   c 
//         b c                a b
//

void right_rotate(Tree &T,Node* y){
 Node* x = y->left;
 
 // move b in place
 // turn x's right into y's left  //             /
 y->left = x ->right;             //            y   
 if (x->right != &nil)            //    x      b c     
 	x->right->parent =y;          //   a
 


 // attach x to tree; set x's parent and x's parent's child
                                 //        YP
 x->parent = y-> parent;         //       /
                                 //      x       y    
 if (x->parent == &nil)          //     a       b c
   T.root = x;
 else if (y == x->parent->right)
   x->parent->right = x;
 else
  x->parent->left = x;

// attach y to x
x->right=y;
y->parent=x;

}


void  rb_insert_fixup(Tree & T,Node *z){
   Node * y;
   while (z->parent->color == red){
   	if (z->parent == z->parent->parent->left){
       y = z->parent->parent->right;
       if (y->color == red){
       	z->parent->color =black;
       	y->color = black;
       	z->parent->parent->color = red;
       	z = z->parent->parent;
       }
       else{//
         if (z == z->parent->right){
            z = z->parent;
            left_rotate(T,z);
          }
         z->parent->color= black;
         z->parent->parent->color = red;
         right_rotate(T,z->parent->parent);
       } 
   	}
   	else {
       y = z->parent->parent->left;
       if (y->color == red){
       	z->parent->color =black;
       	y->color = black;
       	z->parent->parent->color = red;
       	z = z->parent->parent;
       }
       else{
         if (z == z->parent->left){
            z = z->parent;
            right_rotate(T,z);
          }
         z->parent->color= black;
         z->parent->parent->color = red;
         left_rotate(T,z->parent->parent);
       } 
 
   	}


   }
  T.root->color=black;
}


void rb_insert(Tree& T,Node* z){ // 

  if (T.root == &nil) {
    //cout <<"inserting " << pN->key << endl;
    T.root = z;
    T.maxdepth=0;
    T.nodecount[0]=1;
    z->color = black;
    return;
  }
  //cout << "not empty" << pN -> key << endl;
  // insert pN->key into the Tree T

 Node *x, *y;

 // find location for z
 x=T.root; 
 y=nullptr;
 int depth=0;
 while (x != &nil){
   depth++;
   y=x;
   if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
 }

 // insert into tree
 z->parent = y;
 if (z->key < y->key)
   y->left = z;
 else
   y->right = z;
 
 z->color = red;
 rb_insert_fixup(T,z);

 // record depth ?? check.
 T.nodecount[depth]++;
 if (depth>T.maxdepth)
    T.maxdepth = depth;
}


Node * tree_maximum(Node * x){
  while (x->right != &nil){
    x = x->right;
  }
  return x;
}

Node * tree_minimum(Node * x){
  while (x->left != &nil){
    x = x->left;
  }
  return x;
}

Node * tree_successor(Node *x){
 if (x->right != &nil)
   return tree_minimum(x->right);

 Node *y =x->parent;
 while ((y != &nil) and (x == y->right)){
    x = y;
    y = y->parent;
 }
 return y;

}

Node * tree_predecessor(Node *x){
 if (x->left != &nil)
   return tree_maximum(x->left);

 Node *y =x->parent;
 while ((y != &nil) and (x == y->left)){
    x = y;
    y = y->parent;
 }
 return y;
}




Node * tree_search(Node *x,NodeKey k){

  while ( (x != &nil) and (x->key != k)){
      if (k < x->key)
           x = x->left;
      else
           x = x->right;
  }

  return x;
}



void printvector(const vector<string> v)
{
	for (auto x: v){
		cout << x << " ";
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
  nil.data="NIL";
  
  int NumVals=stoi(argv[1]);
  int NumFind=stoi(argv[2]);

  bool testing = (argc > 3) ? true : false;

  vector<NodeKey> k(NumVals);
  vector<NodeData> d(NumVals);

	vector<NodeKey> f(NumFind);
   
    //cout << v.size() << f.size();

    for (int ii=0; ii < NumVals; ii++){
    	cin >> k[ii] >> d[ii];

    }

    for (int ii=0; ii < NumFind; ii++)
    	cin >> f[ii];

   
    // Find the 3 nearest values in v to each value in f.


    Tree T;
    // for x in v: is python
    for (int ii=0; ii < NumVals ; ii++){
      Node* pn = new Node(k[ii],d[ii]);
      rb_insert(T,pn);
      if (testing) {
        cout << "walking the tree after adding" << pn -> key << endl;
        inorderwalk(T.root);
   }

    }


  if (testing) {
     cout << "walking the tree" << endl;
     inorderwalk(T.root);
   }

  //printvector(v);
  //printvector(f);

  for (auto keytofind : f) {

     Node * pn=tree_search(T.root,keytofind);

     if (pn != &nil){
       if (testing){
       cout << "Found " << keytofind <<endl;
       cout << "predecessor" <<endl;
       printnode(tree_predecessor(pn));
       cout << "value" <<endl;
       printnode(pn);
       cout <<"successor" << endl;
       printnode(tree_successor(pn));
      }
      else {
        Node * pre = tree_predecessor(pn);
        Node * suc = tree_successor(pn);
        cout << (pre ? pre->data : "-end-") << " " << pn->data << " " << (suc ? suc->data : "-end-") << endl;
      }
     }

  }


  ofstream treestats;
  treestats.open("treestats.txt");
  for (int ii=0; ii <= T.maxdepth; ii++){
    treestats << ii << " " << T.nodecount[ii] << endl;
  }
  treestats.close();
	return 0;
}