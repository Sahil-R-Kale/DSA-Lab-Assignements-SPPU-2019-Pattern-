//============================================================================
// Name        : Assignment4.cpp
// Author      : Sahil Kale 
// Description : Hashing with Linear Probing
//============================================================================

/*Problem Satement:
Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly look up client‘s telephone number. Make use of two 
collision handling techniques and compare them using number of comparisons 
required to find a set of telephone numbers (use linear probing with replacement and 
without replacement)
*/


#include<iostream>
#include<stdlib.h>
using namespace std;

class PhoneBook;
class Node{
	long int telNo;
	string name;
public:
	Node(){
		telNo=0;
		name="";
	}
	friend PhoneBook;
};
class PhoneBook{
	Node data[100];
public:
	void insertWithoutReplace(const string &s, const long int &t){
		int index=hash(s);
		int flag=0;
		for(int i=0;i<99;i++){
			if(data[index].telNo==0){
				data[index].name=s;
				data[index].telNo=t;
				cout<<"\nInserted successfully!"<<endl;
				flag=1;
				break;
			}
			else
				index=(index+1)%100;
		}
		if(flag==0)
			cout<<"\nInsertion failed!"<<endl;
	}
	void insertWithReplace(string &s, long int &t){
			int index=hash(s);
			int flag=0;
			for(int i=0;i<99;i++){
				if(data[index].telNo==0){
					data[index].name=s;
					data[index].telNo=t;
					cout<<"\nInserted successfully!"<<endl;
					flag=1;
					break;
				}
				else
				{
					if(hash(data[index].name)!=index){
						string s1=data[index].name;
						data[index].name=s;
						s=s1;
						long int t1=data[index].telNo;
						data[index].telNo=t;
						t=t1;
					}
					index=(index+1)%100;
				}

			}
			if(flag==0)
				cout<<"\nInsertion failed!"<<endl;
		}
	int hash(const string s){
			int sum=0;
			for(int i=0;s[i]!='\0';i++)
				sum=sum+(s[i]-'0');
			return sum%100;
		}
	void search(const string &s){
		int index=hash(s);
		int comps=0,flag=0;
		for(int i=0;i<99;i++){
			if(data[index].name==s){
				comps+=1;
				cout<<"\nRecord found!"<<endl;
				cout<<"Name: "<<data[index].name<<endl;
				cout<<"Telephone Number: "<<data[index].telNo<<endl;
				cout<<"Number of comparisons done: "<<comps<<endl;
				flag=1;
				break;
			}
			if(data[index].telNo==0)
				{comps+=1;
				break;
				}
			else
				{comps+=1;
				index=(index+1)%100;
				}
		}
		if(flag==0){
			cout<<"\nRecord not found!\nNumber of comparisons done: "<<comps<<endl;
		}
	}
};

int main(){
	PhoneBook p;
	int cho,cho1;long int t;
	string s;
	cout<<"-------------Phone Book Program--------------"<<endl;
	while(true){
		cout<<"\n1.Hashing without replacement\n2.Hashing with replacement\nEnter your choice: ";cin>>cho1;
		if(cho1==1 || cho1==2){
			break;
		}
		else
			cout<<"Invalid choice!Try again!"<<endl;
	}
	while(true){
		cout<<"\n------------Menu------------\n1.Insert record\n2.Search record\n3.Exit\nEnter your choice: ";cin>>cho;
		switch(cho){
			case 1:
				cout<<"\nEnter name to be inserted: ";cin>>s;
				cout<<"Enter number to be inserted: ";cin>>t;
				if(cho1==1)
					p.insertWithoutReplace(s, t);
				else
					p.insertWithReplace(s, t);
				break;
			case 2:
				cout<<"\nEnter name to be searched: ";cin>>s;
				p.search(s);
				break;
			case 3:
				cout<<"\nThank You!";
				exit(0);
		}
	}
}

