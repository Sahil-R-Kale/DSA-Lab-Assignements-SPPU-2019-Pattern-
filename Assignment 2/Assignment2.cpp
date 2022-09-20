//============================================================================
// Name        : Assignment2.cpp
// Description : BST Dictionary
//============================================================================

/*Problem Statement:
A Dictionary stores keywords and its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry. Provide facility to
display whole data sorted in ascending/ Descending order. Also find how many
maximum comparisons may require for finding any keyword. Use Binary Search
Tree for implementation.

*/

#include <iostream>
#include <stdlib.h>
using namespace std;
class BST;
class Node{
	string key,meaning;
	Node *right,*left;
public:
	Node(){
		key=meaning="";
		right=left=NULL;
	}
	friend BST;
};
class BST{
	Node *root;
public:
	BST(){
		root=NULL;
	}
	void createBST(){
		char ans;
		do{
		Node *p=new Node;
		string s1,s2;
		cout<<"Enter key: ";cin>>s1;
		cout<<"Enter meaning: ";cin>>s2;
		p->key=s1;
		p->meaning=s2;
		if(root==NULL)
			root=p;
		else{
			Node *q=root;
			int flag=0;
			do{
				if(p->key<q->key){
					if(q->left==NULL){
						q->left=p;
						flag=1;
					}
					else
						q=q->left;
				}
				else{
					if(q->right==NULL){
						q->right=p;
						flag=1;
					}
					else
						q=q->right;
				}
			}while(flag==0);
			}
		cout<<"Do you wish to continue adding strings? (y/n)";cin>>ans;
		}while(ans=='y');
	}
	Node *getRoot(){
		return root;
	}
	void inorder(Node *r){
		if(r){
			inorder(r->left);
			cout<<r->key<<" : "<<r->meaning<<endl;
			inorder(r->right);
		}
	}
	void preorder(Node *r){
			if(r){
				cout<<r->key<<" : "<<r->meaning<<endl;
				preorder(r->left);
				preorder(r->right);
			}
		}
	void postorder(Node *r){
			if(r){
				postorder(r->left);
				postorder(r->right);
				cout<<r->key<<" : "<<r->meaning<<endl;
			}
		}
	void reverseInorder(Node *r){
		if(r){
			reverseInorder(r->right);
			cout<<r->key<<" : "<<r->meaning<<endl;
			reverseInorder(r->left);
		}
	}
	Node* search(string s1,Node *r){
		int count=0;
		if(r==NULL|| r->key==s1){
			count+=1;
			cout<<"No of comparisons done: "<<count<<endl;
			return r;
		}
		else{
			Node *p;
			if(s1>r->key){
			count+=1;
			p=search(s1,r->right);
			}
			if(s1<r->key){
			count+=1;
			p=search(s1,r->left);
			}
			cout<<"No of comparisons done: "<<count<<endl;
			return p;
		}
	}
	void getMeaning(Node *r){
		if(r==NULL){
			cout<<"Not Found!"<<endl;
		}
		else{
			cout<<"Meaning of given key is: "<<r->meaning<<endl;
		}
	}
	void update(Node *r,string s1){
		if(r==NULL)
			cout<<"Key does not exist!"<<endl;
		else{
			r->meaning=s1;
			cout<<"Updated successfully!"<<endl;
		}
	}
	void printSorted(){
		cout<<"\nAscending order:\n";inorder(root);
		cout<<"\nDescending order:\n";reverseInorder(root);
	}
	void deleteNode(Node *curr,string s1){
		Node *parent=NULL;
		int flag=0;
		while(curr!=NULL){
			if(curr->key==s1){
				flag=1;
				break;
			}
			if(curr->key>s1){
				parent=curr;
				curr=curr->left;
			}
			if(curr->key<s1){
				parent=curr;
				curr=curr->right;
			}
		}
		if(flag==0){
			cout<<"No such key is found!"<<endl;
			return;
		}
		if(curr==root){
			if(curr->left==NULL && curr->right==NULL){
				cout<<"Binary tree has been entirely deleted! Ending program!"<<endl;
				root=NULL;
				exit(0);
			}
			if(curr->left!=NULL && curr->right==NULL){
		    		Node *temp=root;
		    		root=root->left;
		    		delete temp;
		    }
		    if(curr->left==NULL && curr->right!=NULL){
			    Node *temp=root;
		    	root=root->right;
		    	delete temp;
			}
		}
		else{
		if(curr->left==NULL && curr->right==NULL){
			if(curr==parent->left){
				parent->left=NULL;
			}
			if(curr==parent->right){
				parent->right=NULL;
			}
			delete curr;
		}
		if(curr->left!=NULL && curr->right==NULL){
			if(parent->left==curr){
				parent->left=curr->left;
			}
			else{
				parent->right=curr->left;
			}
			delete curr;
		}
		if(curr->left==NULL && curr->right!=NULL){
			if(parent->left==curr){
				parent->left=curr->right;
			}
			else{
				parent->right=curr->right;
			}
			delete curr;
			}
		if(curr->left!=NULL && curr->right!=NULL){
			Node *temp=curr->left;
			while(temp->right!=NULL){
				temp=temp->right;
			}
			string temp2=temp->key;
			string temp3=temp->meaning;
			Node *p=root;
			deleteNode(p,temp->key);
			curr->key=temp2;
			curr->meaning=temp3;
		}
		}
		cout<<"Deleted successfully!"<<endl;
	}
};
int main() {
	BST b1;
	cout<<"--------------Binary Tree--------------\n"<<endl;
	cout<<"Create your tree: "<<endl;
	string s1,s2;
	b1.createBST();
	Node *root=b1.getRoot();
	Node *r;
	int cho;
	while(true){
	cout<<"\n------------Menu-------------\n1.Traversals\n2.Sort\n3.Search\n4.Update\n5.Delete\nEnter your choice: ";cin>>cho;
	switch(cho){
	case 1:
		cout<<"\nInorder traversal is: "<<endl;b1.inorder(root);
		cout<<"\nPostorder traversal is: "<<endl;b1.postorder(root);
		cout<<"\nPreorder traversal is: "<<endl;b1.preorder(root);
		break;
	case 2:
		b1.printSorted();
		break;
	case 3:
		cout<<"Enter key to be searched: ";cin>>s1;
		r=b1.search(s1, root);
		b1.getMeaning(r);
		break;
	case 4:
		cout<<"Enter key to be searched: ";cin>>s1;
		r=b1.search(s1, root);
		cout<<"Enter meaning to update with: ";cin>>s2;
		b1.update(r, s2);
		break;
	case 5:
		cout<<"Enter key to be deleted: ";cin>>s1;
		b1.deleteNode(root, s1);
	}
	}
	return 0;
}
