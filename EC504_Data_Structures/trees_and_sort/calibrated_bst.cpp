#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>

using namespace std;

typedef string NodeKey;

typedef string NodeData;

class Node{
  public:
  	Node * right, * left, *parent;
  	NodeKey key;
  	NodeData data;

    Node(NodeKey);
    Node(NodeKey,NodeData);
};

Node::Node(NodeKey k){

  key=k;
  left = right = parent = nullptr;

}

Node::Node(NodeKey k,NodeData d){
  key=k;
  data=d;

  left = right = parent = nullptr;

}

const int MAXDEPTH = 1000;
struct Tree{
   Node * root;
   
   int maxdepth;
   array<int,MAXDEPTH> nodecount;

   Tree(){
   	 root = nullptr;
     maxdepth=-1;
     for (int ii=0; ii < MAXDEPTH; ii++)
        nodecount[ii] = 0;
   }
};


void printnode(Node *p){
  if (p != nullptr){
    cout << "k: " << p->key ;
    if (!(p->data).empty())
       cout << ", d: " << p->data;
    cout <<endl;
  }

}

void inorderwalk(Node * p){
  if (p!=nullptr){
    //cout << p->left << endl;
    inorderwalk( p->left);

    printnode(p);

    
    inorderwalk( p->right);
  }


}

void inorderwalk_tree(Tree T){
  inorderwalk(T.root);
}

void insert(Tree& T,Node* z){ // 

  if (T.root == nullptr) {
    //cout <<"inserting " << pN->key << endl;
    T.root = z;
    T.maxdepth=0;
    T.nodecount[0]=1;
    return;
  }
  //cout << "not empty" << pN -> key << endl;
  // insert pN->key into the Tree T

 Node *x, *y;

 // find location for z
 x=T.root; 
 y=nullptr;
 int depth=0;
 while (x != nullptr){
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
 
 // record depth
 T.nodecount[depth]++;
 if (depth>T.maxdepth)
    T.maxdepth = depth;
}


Node * tree_maximum(Node * x){
  while (x->right != nullptr){
    x = x->right;
  }
  return x;
}

Node * tree_minimum(Node * x){
  while (x->left != nullptr){
    x = x->left;
  }
  return x;
}

Node * tree_successor(Node *x){
 if (x->right != nullptr)
   return tree_minimum(x->right);

 Node *y =x->parent;
 while ((y != nullptr) and (x == y->right)){
    x = y;
    y = y->parent;
 }
 return y;

}

Node * tree_predecessor(Node *x){
 if (x->left != nullptr)
   return tree_maximum(x->left);

 Node *y =x->parent;
 while ((y != nullptr) and (x == y->left)){
    x = y;
    y = y->parent;
 }
 return y;
}




Node * tree_search(Node *x,NodeKey k){

  while ( (x != nullptr) and (x->key != k)){
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
      //cout << "try " << pn->key << endl;
      insert(T,pn);
    }


  if (testing) {
     cout << "walking the tree" << endl;
     inorderwalk(T.root);
   }

  //printvector(v);
  //printvector(f);

  for (auto keytofind : f) {

     Node * pn=tree_search(T.root,keytofind);

     if (pn != nullptr){
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