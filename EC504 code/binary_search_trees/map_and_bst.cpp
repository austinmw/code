#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

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

struct Tree{
   Node * root;

   Tree(){
   	 root = nullptr;
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
    return;
  }
  //cout << "not empty" << pN -> key << endl;
  // insert pN->key into the Tree T

 Node *x, *y;

 // find location for z
 x=T.root; 
 y=nullptr;
 while (x != nullptr){
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

	vector<string> v(NumVals);
	vector<string> f(NumFind);
   
    //cout << v.size() << f.size();

    for (int ii=0; ii < NumVals; ii++)
    	cin >> v[ii];

    for (int ii=0; ii < NumFind; ii++)
    	cin >> f[ii];

   
    // Find the 3 nearest values in v to each value in f.


    Tree T;
    // for x in v: is python
    for (auto x : v){
      Node* pn = new Node(x);
      //cout << "try " << pn->key << endl;
      insert(T,pn);
    }

  inorderwalk(T.root);

  //printvector(v);
  //printvector(f);

  for (auto keytofind : f) {

     Node * pn=tree_search(T.root,keytofind);

     if (pn != nullptr){
       cout << "Found " << keytofind <<endl;
       cout << "predecessor" <<endl;
       printnode(tree_predecessor(pn));
       cout << "value" <<endl;
       printnode(pn);
       cout <<"successor" << endl;
       printnode(tree_successor(pn));

     }

  }

  // Next steps:
  // -implement same features using map
  // -randomize test strings (100,000 v 100)
  // -use python to generate data and time.
  //
	return 0;
}