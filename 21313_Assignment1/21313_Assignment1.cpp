//============================================================================
// Name        : DSALAssignment1.cpp
// Author      : Sahil Kale
// Description : Binary Tree using DLL
//============================================================================

/* Problem Statement:
Beginning with an empty binary tree, construct binary tree by inserting the values in
the order given. After constructing a binary tree perform following operations on it-
1. Perform inorder, preorder and post order traversal (Implement both recursive
and non-recursive methods)
2. Change a tree so that the roles of the left and right pointers are swapped at
every node
3. Find the height of tree
4. Copy this tree to another [operator=]
5. Count number of leaves, number of internal nodes.
6. Erase all nodes in a binary tree.
*/

#include <iostream>
#include <stdlib.h>
#include "myStack.h"
#define max 20
using namespace std;

class BinaryTree;
class Node{
	int data;
	Node *left,*right;
public:
	Node(){
		data=0;
		left=right=NULL;
	}
	friend BinaryTree;
};
class BinaryTree{
	Node *root;
public:
	BinaryTree(){
		root=NULL;
	}
	void createTree(){
		char a;
		do{
		Node *p=new Node; int d;
		cout<<"Enter data for node: "; cin>>d;
		p->data=d;
		if(root==NULL){
			root=p;
		}
		else{
			Node *q=root; bool flag=false; char ans;
			do{
				cout<<"Node exists! Do you want to insert node to the left or right? (L/R): "; cin>>ans;
				if(ans=='L'){
					if(q->left==NULL){
						q->left=p;
						flag=true;
						cout<<"Node successfully added!"<<endl;
					}
					else{
						q=q->left;
					}
				}
				else{
					if(q->right==NULL){
						q->right=p;
						flag=true;
						cout<<"Node successfully added!"<<endl;
					}
					else{
						q=q->right;
					}
				}
			}while(flag==false);
		}
		cout<<"\nDo you want to add another node? (y/n)"; cin>>a;
	}while(a=='y');
	}

	Node* getRoot(){
		return this->root;
	}
	int height(Node *r){
		if(r==NULL){
			return -1;
		}
		else{
			int left=height(r->left);
			int right=height(r->right);
			if(left>right){
				return left+1;
			}
			else return right+1;
		}
	}
	void inorder(Node *r){
		if(r){
			inorder(r->left);
			cout<<r->data<<"	";
			inorder(r->right);
		}
	}
	void preorder(Node *r){
			if(r){
				cout<<r->data<<"	";
				preorder(r->left);
				preorder(r->right);
			}
		}
	void postorder(Node *r){
			if(r){
				postorder(r->left);
				postorder(r->right);
				cout<<r->data<<"	";
			}
		}
	void iterInorder(){
		Node *p=root;
		int finish=0;
		Stack<Node*> s1;
		do{
			while(p!=NULL){
				s1.push(p);
				p=p->left;
			}
			if(!s1.isEmpty()){
				p=s1.pop();
				cout<<p->data<<"	";
				p=p->right;
			}
			else finish=1;
		}while(finish==0);
	}
	void iterPreorder(){
		Stack<Node*> s1;
		s1.push(root);
		while(!s1.isEmpty()){
			Node *current=s1.pop();
			cout<<current->data<<"      ";
			if(current->right!=NULL) s1.push(current->right);
			if(current->left!=NULL) s1.push(current->left);
		}
	}
	void iterPostorder(){
		if(root==NULL) return;
		Node *p=root;
		Stack<Node*> s1;
		do{
			while(p){
				if(p->right){
					s1.push(p->right);
				}
				s1.push(p);
				p=p->left;
			}
			p=s1.pop();
			if(p->right!=NULL && s1.showTop()==p->right){
				s1.pop();
				s1.push(p);
				p=p->right;
			}
			else{
				cout<<p->data<<"      ";
				p=NULL;
			}
		}while(!s1.isEmpty());
	}
	Node* mirror(Node *r){
		Node *p=NULL;
		if(r!=NULL){
			p=new Node;
			p->data=r->data;
			p->left=mirror(r->right);
			p->right=mirror(r->left);
		}
		return p;
	}
	int leafCount(Node *r){
		if(r==NULL)
			return 0;
		if(r->left == NULL && r->right == NULL)
		        return 1;
		else
		    return leafCount(r->left)+leafCount(r->right);
	}
	void operator=(BinaryTree b1){
		this->root=b1.copy_tree(b1.root);
	}
	Node* copy_tree(Node *p)
	{
	    if (p == NULL)
	    {
	        return NULL;
	    }
	    else
	    {
	        Node *temp;
	        temp = new Node;
	        temp->data = p->data;
	        temp->left = copy_tree(p->left);
	        temp->right = copy_tree(p->right);
	        return temp;
	    }
	}
	void eraseTree(Node *r){
		if(r==NULL)
			return;
		eraseTree(r->left);
		eraseTree(r->right);
		delete r;
	}
};
int main() {
	BinaryTree b1,b2;
	cout<<"Create binary tree!\n"<<endl;
	b1.createTree();
	Node *root=b1.getRoot();
	int cho;
	while(true){
		cout<<"\n\n-------------Menu---------------\n1.Recursive traversals\n2.Iterative Traversals\n3.Height of tree\n4.Mirror the tree\n5.Count leaf nodes\n6.Copy tree\n7.Erase tree and exit\nEnter choice: ";cin>>cho;
		switch(cho){
			case 1:
				cout<<"\nInorder traversal is: "<<endl;b1.inorder(root);
				cout<<"\nPreorder traversal is: "<<endl;b1.preorder(root);
				cout<<"\nPostorder traversal is: "<<endl;b1.postorder(root);
				break;
			case 2:
				cout<<"\nInorder traversal is: "<<endl;b1.iterInorder();
				cout<<"\nPreorder traversal is: "<<endl;b1.iterPreorder();
				cout<<"\nPostorder traversal is: "<<endl;b1.iterPostorder();
				break;
			case 3:
				cout<<"\nHeight of tree= "<<b1.height(root);
				break;
			case 4:
				Node *m1;
				m1=b1.mirror(root);
				cout<<"Mirror created successfully! Traversals of mirror are: "<<endl;
				cout<<"\nInorder traversal is: "<<endl;b1.inorder(m1);
				cout<<"\nPreorder traversal is: "<<endl;b1.preorder(m1);
				cout<<"\nPostorder traversal is: "<<endl;b1.postorder(m1);
				break;
			case 5:
				cout<<"\nLeaf count: "<<b1.leafCount(root);
				break;
			case 6:
				b2=b1;
				Node *m2;
				m2=b2.getRoot();
				cout<<"Copy created successfully! Traversals of copy are: "<<endl;
				cout<<"\nInorder traversal is: "<<endl;b2.inorder(m2);
				cout<<"\nPreorder traversal is: "<<endl;b2.preorder(m2);
				cout<<"\nPostorder traversal is: "<<endl;b2.postorder(m2);
				break;
			case 7:
				b1.eraseTree(root);
				cout<<"Tree erased succesfully! Thank You!";
				exit(0);
		}
	}
	return 0;
}
