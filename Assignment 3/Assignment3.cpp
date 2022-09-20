//============================================================================
// Name        : Assignment3.cpp
// Description : Threaded BST
//============================================================================

/* Problem Statement:
 Create an inordered threaded binary tree and perform inorder and preorder traversals.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
class TBST;
class Node{
	int data;
	Node *left, *right;
	int lflag, rflag;
public:
	Node(){
		data=lflag=rflag=0;
		left=right=NULL;
	}
	friend TBST;
};
class TBST{
	Node *root;
	Node *head;
public:
	TBST(){
		root=NULL;
		head=NULL;
	}
	void createTree(){
		char ans='y';
		do{
		int d;
		Node *nn=new Node;
		cout<<"Enter data for node: ";cin>>d;
		nn->data=d;
		if(root==NULL){
			head=new Node;
			root=nn;
			nn->left=head;
			nn->lflag=1;
			nn->right=head;
			nn->rflag=1;
			head->left=root;
		}
		else{
			Node *curr=root;
			int flag=0;
			do{
				if(curr->data>nn->data){
					if(curr->lflag==1){
						nn->left=curr->left;
						nn->lflag=1;
						nn->right=curr;
						nn->rflag=1;
						curr->left=nn;
						curr->lflag=0;
						cout<<"Node successfully added!"<<endl;
						flag=1;
					}
					else{
						curr=curr->left;
					}
				}
				else{
					if(curr->rflag==1){
						nn->right=curr->right;
						nn->rflag=1;
						nn->left=curr;
						nn->lflag=1;
						curr->right=nn;
						curr->rflag=0;
						cout<<"Node successfully added!"<<endl;
						flag=1;
						}
					else{
						curr=curr->right;
					}
				}
			}while(flag==0);
		}
		cout<<"Do you want to add another node? (y/n) ";cin>>ans;
	}while(ans=='y');
	}

	Node *getRoot(){
		return root;
	}
	Node* findSuccessor(Node *curr){
		if(curr->rflag==1)
			return curr->right;
		else{
			Node *t=curr->right;
			while(t->lflag==0){
				t=t->left;
			}
			return t;
		}
	}
	void inorder(){
		Node *curr=root;
		while(curr->lflag==0){
			curr=curr->left;
		}
		while(curr->right!=head){
			cout<<curr->data<<"    ";
			curr=findSuccessor(*&curr);
		}
		cout<<curr->data<<endl;
	}
	void preorder(){
		Node *curr=root;int flag=0;
		cout<<curr->data<<"    ";
		while(curr!=head){
			while(curr->lflag==0 && flag==0){
				curr=curr->left;
				cout<<curr->data<<"    ";
			}
			if(curr->rflag==0){
				curr=curr->right;
				cout<<curr->data<<"    ";
				flag=0;
			}
			else{
				curr=curr->right;
				flag=1;
			}
		}
	}

};
int main() {
	TBST t1;
	cout<<"-------------Threaded BST--------------\n"<<endl;
	t1.createTree();
	int cho;
	while(true){
		cout<<"\n------------Menu-----------\n1.Inorder traversal\n2.Preorder Traversal\n3.Add node\n4.Exit\nEnter your choice: ";cin>>cho;
		switch(cho){
		case 1:
			cout<<"\nInorder traversal is: ";
			t1.inorder();
			break;
		case 2:
			cout<<"\nPreorder traversal is: ";
			t1.preorder();
			break;
		case 3:
			t1.createTree();
			break;
		case 4:
			cout<<"\nThank You!";
			exit(0);
		}
	}
	return 0;
}
