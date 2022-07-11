/*

THIS COVERS QUESTION NUMBER 3 OF THE ASSIGNMENT. 

*/

#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<vector>

using namespace std;

void max_heapify(int *arr,int index,int heapsize){
	
	int parent_val;
	int k;
	parent_val = arr[index]; //Saving parent value in case to swap. 
	k = 2*index; // starting assuming k to be left child. 
	
	
	while(k<=heapsize){
		
		if((k<heapsize) && (arr[k+1]>arr[k])){  //arr[k+1]<arr[k])
			
			k=k+1; //update index value to make it right child in case the right child is less than left child		
		}
		
		if(parent_val>arr[k]){   //parent_val<arr[k]
			
			
			break; // our work here is done if the parent is less than its child. 
		}
		else if(parent_val<=arr[k]){  //parent_val>=arr[k]
			
			arr[k/2] = arr[k]; //inserting child's value in parent
			k = 2 * k;
			
		}
		
	}
	
	arr[k/2] = parent_val;
	return;
}


void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a,i,n);
    }
}


void initialize(int *arr){
	
	for (int i = 0;i<100;i++){
		
		arr[i] = -40000;
	}
	
}

int get_size(int *arr){
	
	int count = 0;
	for(int i = 1;i<100;i++){
		
		if(arr[i]>=0){ count++;}
		else{break;}	
	}
	
	return count;
	
}


void insert_value(int *a){
	int size = get_size(a);	
	while(a[size/2]<=a[size]){
		swap(a[size/2],a[size]);
		size = size/2;	
	}
	
}
void insert(int *a,int val){
	
	int size = get_size(a);
	a[size+1] = val;
	insert_value(a);
	
}




void delete_value(int *a,int size){
	
	a[1] = a[size];
	int j = 1;
	a[size] = -40000;
	
	int new_size = get_size(a);
	
	build_maxheap(a,new_size);

	
}




int main(){
	
	int number_of_inputs = 10;
	
	cout<<"Enter Number of Nodes: ";
	cin>>number_of_inputs;
	
	srand(12);
	int input_array[100];
	initialize(input_array);
	
	for(int i = 1;i<=number_of_inputs;i++){
		
		input_array[i] = rand()%100;
		
	}
	
	int size = get_size(input_array);
	cout<<"The Original is: \n";
	cout<<"Size of Original Data is is: "<<size<<endl;
	
	cout<<"Original Data is: ";

	for(int j =1;j<=size;j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	
	
	build_maxheap(input_array,size);

	cout<<"\n\nMax Heap is: \n\n";	
	for(int j =1;j<=size;j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	int vaal = rand()%100;
	insert(input_array,vaal);
	
	int new_size = get_size(input_array);	
	
	cout<<"\n\nAfter Inserting "<<vaal<<", we will get: \n\n";
	
	
	
	for(int j =1;j<=new_size;j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	
	delete_value(input_array,new_size);
	
	new_size = get_size(input_array);
	
	cout<<"\n\n3. Implement a delete( ) function for the Max Heap\n\n";
	cout<<"After Deleting head, we will get: ";
	
	
	
	for(int j =1;j<=new_size;j++){
		
		cout<<input_array[j]<<", ";
		
	}
	
	return 0;
}


