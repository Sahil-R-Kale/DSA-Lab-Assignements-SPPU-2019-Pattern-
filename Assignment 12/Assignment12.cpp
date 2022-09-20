//============================================================================
// Name        : Assignment12.cpp
// Author      : Sahil Kale
// Description : File Handling
//============================================================================

/*Problem Statement:
Department maintains a student information. The file contains roll number, name, 
division and address. Allow user to add, delete information of student. Display 
information of particular employee. If record of student does not exist an appropriate 
message is displayed. If it is, then the system displays the student details. Use 
sequential file to main the data.
*/

#include<iostream>
#include<fstream>
using namespace std;
class Student
{	int roll_no,division;
    string name, address;
    public:
    Student(){
    	name=address="";
    	roll_no=division=-1;
    }
    friend class Records;
};
class Records
{
    Student record;
    public:
    void create()
    {
        fstream seqFile;
        seqFile.open("StudentRecords.txt",ios::in|ios::out|ios::binary);
        char ch='y';
        while(ch=='y')
        {
            cout<<" Enter Name : ";
            cin>>record.name;
            cout<<" Enter Roll Number : ";
            cin>>record.roll_no;
            cout<<" Enter Division : ";
            cin>>record.division;
            cout<<" Enter address : ";
            cin>>record.address;
            cout<<endl;
            seqFile.write((char*)&record,sizeof(record));
            cout<<" Do you want to add more records ? (y/n) ";
            cin>>ch;
        }
        seqFile.close();
    }
    void display()
    {
        fstream seqFile;
        seqFile.open("StudentRecords.txt",ios::in|ios::out|ios::binary);
        seqFile.seekg(0,ios::beg);
        cout<<endl;
        cout<<" The file contents are :- "<<endl;
        while(seqFile.read((char*)&record,sizeof(record)))
        {
            if(record.roll_no!=-1)
            {
                cout<<endl;
                cout<<" Name : "<<record.name<<endl;
                cout<<" Roll Number : "<<record.roll_no<<endl;
                cout<<" Division : "<<record.division<<endl;
                cout<<" Address : "<<record.address<<endl;
                cout<<endl;
            }
        }
        seqFile.close();
    }
    void update()
    {
        int pos;
        cout<<"For updation "<<endl;
        fstream seqFile;
        seqFile.open("StudentRecords.txt",ios::in|ios::out|ios::binary);
        seqFile.seekg(0,ios::beg);
        pos=search();
        if(pos==-1)
        {
            cout<<"The record is not present! Try again!"<<endl;
            return ;
        }

        int offset=pos*sizeof(record);
        seqFile.seekp(offset);
        cout<<"Enter new record: "<<endl;
        cout<<" Name : ";
        cin>>record.name;
        cout<<" Roll Number : ";
        cin>>record.roll_no;
        cout<<" Division : ";
        cin>>record.division;
        cout<<" Address : ";
        cin>>record.address;
        seqFile.write((char*)&record,sizeof(record))<<flush;
        seqFile.seekg(0);
        seqFile.close();
        cout<<" The record is Updated !!"<<endl;
    }

    int search()
    {
        fstream seqFile;
        int id,pos;
        cout<<" Enter the Roll Number for searching the record ";
        cin>>id;
        seqFile.open("StudentRecords.txt",ios::ate|ios::in|ios::out|ios::binary);
        seqFile.seekg(0,ios::beg);
        pos=-1;
        int i=0;
        while(seqFile.read((char*)&record,sizeof(record)))
        {
            if(id==record.roll_no)
            {
                pos=i;
                break;
            }
            i++;
        }
        return pos;
    }

    void Delete()
    {
        int pos;
        cout<<" For deletion "<<endl;
        fstream seqFile;
        seqFile.open("StudentRecords.txt",ios::in|ios::out|ios::binary);
        seqFile.seekg(0,ios::beg);
        pos=search();
        if(pos==-1)
        {
            cout<<" The record is not present in the file ."<<endl;
            return ;
        }

        int offset=pos*sizeof(record);
        seqFile.seekp(offset);
        record.name="";
        record.roll_no=-1;
        record.division=-1;
        record.address="";
        seqFile.write((char*)&record,sizeof(record))<<flush;
        seqFile.seekg(0);
        seqFile.close();
        cout<<" The record is Deleted !!"<<endl;
    }
};
int main()
{
    Records list;
    int option;
    cout<<endl;
    do
    {
        cout<<"-----------Menu-----------"<<endl;
        cout<<"1.Create record "<<endl;
        cout<<"2.Display record "<<endl;
        cout<<"3.Update record "<<endl;
        cout<<"4.Delete record "<<endl;
        cout<<"Enter your choice : ";
        cin>>option;
        switch (option)
        {
        case 1:
            list.create();
            break;
        case 2:
            list.display();
            break;
        case 3:
            list.update();
            break;
        case 4:
            list.Delete();
            break;
        }
        cout<<endl;
    } while (option>=1 && option<=4);

    return 0;
}
