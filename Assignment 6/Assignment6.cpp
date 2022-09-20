//============================================================================
// Name        : Assignment6.cpp
// Description : Adjacency list of graph and BFS DFS traversals
//============================================================================

/* Problem Statement:
Represent a given graph using adjacency list to perform DFS and BFS. Use the map 
of the area around the college as the graph. Identify the prominent landmarks as 
nodes and perform DFS and BFS on that.
*/

#include <iostream>
#include <stdlib.h>
#include"myQueue.h"
#include"myStack.h"
#define max 20

using namespace std;
class Graph;
class Node{
	int data;
	Node *link;
public:
	Node(){
		data=0;
		link=NULL;
	}
	Node(int y){
		data=y;
		link=NULL;
	}
	friend Graph;
};
class Graph{
	int nodeNo;
	Node* adj[max];
public:
	Graph(){
		nodeNo=0;
	}
	Graph(int x){
		nodeNo=x;
		for(int i=0;i<nodeNo;i++){
			adj[i]=NULL;
		}

	}
	void addEdge(int src, int dest){
		Node *ptr=new Node(dest);
		if(adj[src]==NULL)
			adj[src]=ptr;
		else{
			Node *temp=adj[src];
			while(temp->link!=NULL)
				temp=temp->link;
			temp->link=ptr;
		}
		Node *ptr1=new Node(src);
		if(adj[dest]==NULL)
			adj[dest]=ptr1;
		else{
			Node *temp1=adj[dest];
			while(temp1->link!=NULL)
				temp1=temp1->link;
			temp1->link=ptr1;
		}
	}
	void display(){
		for(int i=0;i<nodeNo;i++){
			cout<<"Adjacency list of vertex "<<i<<": ";
			Node *ptr=adj[i];
			while(ptr){
				cout<<ptr->data<<"   ";
				ptr=ptr->link;
			}
			cout<<endl;
		}
	}
	void BFS(int src){
		Queue<int> q;
		cout<<"\nBreadth first search is: ";
		int visited[nodeNo]={};
		visited[src]=1;
		q.enque(src);
		while(!q.isEmpty()){
			src=q.deque();
			cout<<src<<"  ";
			for(Node *i=adj[src];i!=NULL;i=i->link){
				if(visited[i->data]==0){
					visited[i->data]=1;
					q.enque(i->data);
				}
			}
		}
	}
	void DFS(int src){
			Stack<int> s;
			cout<<"\nDepth first search is: ";
			int visited[nodeNo]={};
			visited[src]=1;
			s.push(src);
			while(!s.isEmpty()){
				src=s.pop();
				cout<<src<<"  ";
				for(Node *i=adj[src];i!=NULL;i=i->link){
					if(visited[i->data]==0){
						visited[i->data]=1;
						s.push(i->data);
					}
				}
			}
		}
};
int main() {
	int x,cho,src,dest;
	cout<<"---------Graph----------\n\nEnter number of nodes in graph: ";cin>>x;
	if(x<=0){
		while(x<=0){
		cout<<"Invalid input! Try again!"<<endl;
		cout<<"Enter number of nodes in graph: ";cin>>x;
		}
	}
	cout<<"Graph created successfully!";
	Graph g(x);
	while(true){
		cout<<"\n-----------Menu-----------\n1.Add edge\n2.Display adjacency list\n3.Breadth First Search (BFS)\n4.Depth First Search (DFS)\n5.Exit\nEnter your choice: ";
		cin>>cho;
		switch(cho){
		case 1:
			cout<<"\nEnter source vertex (0-"<<x-1<<"): ";cin>>src;
			cout<<"Enter destination vertex (0-"<<x-1<<"): ";cin>>dest;
			if(src<x && dest<x){
				g.addEdge(src, dest);
				cout<<"Edge added successfully!"<<endl;
			}
			else
				cout<<"Invalid input!Try again"<<endl;
			break;
		case 2:
			g.display();
			break;
		case 3:
			cout<<"\nEnter source vertex (0-"<<x-1<<"): ";cin>>src;
			if(src>=0 && src<x)
				g.BFS(src);
			else
				cout<<"Invalid input!Try again"<<endl;
			break;
		case 4:
			cout<<"\nEnter source vertex (0-"<<x-1<<"): ";cin>>src;
			if(src>=0 && src<x)
				g.DFS(src);
			else
				cout<<"Invalid input!Try again"<<endl;
			break;
		case 5:
			cout<<"Thank You!";
			exit(0);
			break;
		}
	}
	return 0;
}

