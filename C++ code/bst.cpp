/* Sample input:
7
3
5
2
1
4
6
7
*/

#include <iostream>
#include <cstddef>
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

	// insert
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

	// get height
	int getHeight(Node* root){
		if(root == NULL){
			return -1;
		}
		int lefth = getHeight(root->left);
		int righth = getHeight(root->right);
		if (lefth > righth) {
			return lefth + 1;
		}
		else
		{
			return righth + 1;    
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
	int height= myTree.getHeight(root);
	cout<<height;
	return 0;
}
	
			   
					
				