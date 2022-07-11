/*

THIS COVERS QUESTION NUMBER 1,2,4 OF THE ASSIGNMENT. 

*/


#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<vector>

using namespace std;


void min_heapify(int *arr,int index,int heapsize){
	
	int parent_val;
	int k;
	parent_val = arr[index]; //Saving parent value in case to swap. 
	k = 2*index; // starting assuming k to be left child. 
	
	
	while(k<=heapsize){
		
		if((k<heapsize) && (arr[k+1]<arr[k])){  //arr[k+1]>arr[k])
			
			k=k+1; //update index value to make it right child in case the right child is less than left child		
		}
		
		if(parent_val<arr[k]){   //parent_val>arr[k]
			
			
			break; // our work here is done if the parent is less than its child. 
		}
		else if(parent_val>=arr[k]){  //parent_val<=arr[k]
			
			arr[k/2] = arr[k]; //inserting child's value in parent
			k = 2 * k;
			
		}
		
	}
	
	arr[k/2] = parent_val;
	return;
}


void build_minheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(a,i,n);  // Starting from the last parent and tracking back. to check for all sub-heaps and heapifying them
    }
}


void initialize(int *arr){
	
	for (int i = 0;i<100;i++){
		
		arr[i] = -40000; // initialized all array to a negative value to get actual size. 
	}
	
}

int get_size(int *arr){  // gets the size of array.
	
	int count = 0;
	for(int i = 1;i<100;i++){
		if(arr[i]>=0){ count++; }
		else{ break;}
		
	}
	
	return count;
	
}

void insert_value(int *a, int size){
	
	int j = size;
	
	while(a[j/2]>=a[j]){
		
		swap(a[j/2],a[j]);
		j = j/2;	
	}
	
}

void insert(int *a,int val){
	
	int size = get_size(a);
	a[size+1] = val;  
	insert_value(a,get_size(a));
	
}



int delete_value(int *a,int size){
	int d_val = a[1];
	cout<<"a[1]=="<<a[1]<<endl;
	a[1] = a[size];
	cout<<"a[1]_again=="<<a[1]<<endl;
	a[size] = -4000;
	
	int new_size = get_size(a);
	
	build_minheap(a,new_size);

return d_val;
	
}


void heapsort(int *a){

int size = get_size(a);
while(size>0){
	
	int val = delete_value(a,size);
	a[size] = val;
	size--;
	
}

}



int main(){
	
	srand(12);
	int number_of_inputs;
	cout<<"Enter Number of Nodes:";
	cin>>number_of_inputs;
	//Declaring an array of 100 elements and initializing it all to -40000
	
	int input_array[100];
	initialize(input_array);
	
	
	//Entering Random Data for 20 elements
	for(int i = 1;i<=number_of_inputs;i++){
		
		input_array[i] = rand()%100;
		
	}
		
	// Printing Original Array and Its size information.
	int size = get_size(input_array);
	cout<<"The Original is: \n";
	cout<<"Size of Original Data is is: "<<size<<endl;
	
	cout<<"Original Data is: ";

	for(int j =1;j<=size;j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	
	// Implementing Min Heapify function. 
	
	cout<<"\n\n1. Implement a MinHeapify( ) method to convert the CBT into Min Heap.\n\n";
	
	build_minheap(input_array,size);

	cout<<"\nMin Heap is: ";	
	for(int j =1;j<=size;j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	// Implementing Insert function 
	
	int vaal = rand()%100; // Generating a random value 
	
	insert(input_array,vaal);

	cout<<"\n\n2. Implement an Insert( ) function for Min Heap\n\n";
	cout<<"\nAfter Inserting "<<vaal<<", we will get: ";
	
	int new_size = get_size(input_array);
	
	for(int j =1;j<=new_size;j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	cout<<"\n\n4. Implement a HeapSort( ) function to sort Min heap\n\n";
	heapsort(input_array);
		
	
		
	
	cout<<"\nHeap Sorted Values:";
	for(int j =1;j<=get_size(input_array);j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	
	return 0;
}


