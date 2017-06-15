/*  Sample input:
	6
	3
	5
	4
	7
	2
	1
*/

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>


using namespace std;	
class Node{
	public:
		int data;
		Node *left,*right;
		Node(int d){
			data=d;
			left=right=NULL;
		}
};


class Solution{
	public:
  		Node* insert(Node* root, int data){
			if(root==NULL){
				return new Node(data);
			}
			else{
				Node* cur;
				if(data<=root->data){
					cur=insert(root->left,data);
					root->left=cur;
				}
				else{
				   cur=insert(root->right,data);
				   root->right=cur;
				 }           
		   return root;
		   }
		}
		
	// level order traversal	
	void levelOrder(Node * root){
		//Write your code here
		queue<Node> q;
		int levels = 0;
		if(root == NULL) {
		    return;
		}
		q.push(*root);
		while(!q.empty()){
			levels = q.size();
			while(levels>0) {
				Node n = q.front();
				q.pop();
				printf("%d ", n.data);
				if(n.left != NULL)
					q.push(*n.left);
				if(n.right != NULL)
					q.push(*n.right);
				levels--;				
			}
			//printf(" ");
		}
	}
		
			
};


int main(){
	Solution myTree;
	Node* root=NULL;
	int T,data;
	cin>>T;
	while(T-->0){
		cin>>data;
		root= myTree.insert(root,data);
	}
	myTree.levelOrder(root);
	return 0;
}