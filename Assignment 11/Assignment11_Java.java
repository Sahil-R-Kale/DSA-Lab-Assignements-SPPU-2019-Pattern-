package myPackage;

import java.util.*;
public class HeapSort {
	int arr[]=new int[100];
	int sorted[]=new int[100];
	int ele;
	HeapSort(){
		ele=0;
	}
	HeapSort(int x){
		ele=x;
		for(int i=0;i<x;i++) {
			arr[i]=0;
			sorted[i]=0;
		}
	}
	void takeInput() {
		Scanner s=new Scanner(System.in);
		for(int i=0;i<ele;i++) {
			System.out.println("Enter element "+i+" : ");
			arr[i]=s.nextInt();
		}
		s.close();
	}
	void display() {
		System.out.println("\nSorted Array is: ");
		for(int i=0;i<ele;i++) {
			
			System.out.print(sorted[i]+"  ");
		}
	}
	void heapifyAll() {
		for(int i=ele/2-1;i>=0;i--)
			heapifyIndiv(arr, ele, i);
	}
	void heapifyIndiv(int arr[], int n, int root){
		int mini=root;
		int l=2*root+1;
		int r=2*root+2;
		if(l<n && arr[l]<arr[mini]){
			mini=l;
		}
		if(r<n && arr[r]<arr[mini]){
			mini=r;
		}
		if(mini!=root){
			int temp=arr[root];
			arr[root]=arr[mini];
			arr[mini]=temp;
			heapifyIndiv(arr,n,mini);
		}
	}
	void heapSort(){
		heapifyAll();
		int j=0;
		for(int i=ele-1;i>=0;i--){
			sorted[j++]=arr[0];
			int temp=arr[0];
			arr[0]=arr[i];
			arr[i]=temp;
			heapifyIndiv(arr,i,0);
		}
	}
	public static void main(String[] args) {
	System.out.println("------------Heap Sort Program--------------");
	Scanner sc=new Scanner(System.in);
	System.out.println("\nEnter no of elements in array: ");
	int sz=sc.nextInt();
	HeapSort h= new HeapSort(sz);
	h.takeInput();
	h.heapSort();
	h.display();

	System.out.println("\nThank You!");
	sc.close();
	}

}

