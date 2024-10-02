#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
std::mt19937 Rand(time(0));

void merge(int *leftArr, int leftSize, int *rightArr, int rightSize ,int* arr, int arrSize){
	int i = 0, l= 0, r = 0;
	while(l < leftSize && r < rightSize){
		if(*(leftArr + l) < *(rightArr + r)){
			*(arr + i) = *(leftArr + l); 
			l++; i++;	
		}else{
			*(arr + i) = *(rightArr + r); 
			r++; i++;	
		}
	}
	while(l < leftSize){
		*(arr + i) = *(leftArr + l);
		l++; i++;
	}
	while(r < rightSize){
		*(arr + i) = *(rightArr + r);
		r++; i++;
	}
}
void mergeSort(int* arr, int n){
	if(n <= 1) return; //case base
	
	int middle = n/2;
	
	int leftSize = middle;
	int rightSize = n - middle;
	int* leftArray = new int[leftSize];
	int* rightArray = new int [rightSize];
	
	int i = 0; 
	int j = 0;
	for( ; i < n; i++){
		if( i < middle){
			*(leftArray + i) = *(arr + i);		
    	}else{
    		*(rightArray + j) = *(arr + i);
			j++;		
    	}
   	}
   	mergeSort(leftArray, leftSize);
   	mergeSort(rightArray, rightSize);
   	merge(leftArray, leftSize, rightArray, rightSize, arr, n);
               
}
int main(){
	std::cout<<"#### Merge Sort ####\n";
	std::cout<<"_____________________\n\n\n";

    int n;
    std::cout<<"Enter the size of array: ";
    std::cin>>n;
	//int arr[n];
	int* arr = new int[n];
	
	for(int i = 0; i < n; i++){
		//arr[i] = Rand()%100;
		*(arr + i) = Rand()%100;	
	}
	
    std::cout<<"The unordered array is"<<'\n';
    for(int i = 0; i < n; i++){
    	//std::cout<<arr[i]%100<<" ";
		std::cout<<*(arr + i)<<" ";
	}
	
	mergeSort(arr, n);
	
	std::cout<<'\n';
	std::cout<<"Applying MergeSort\n";
	std::cout<<"The ordered array is"<<'\n';
    for(int i = 0; i < n; i++){
    	//std::cout<<arr[i]%100<<" ";
		std::cout<<*(arr + i)<<" ";
	}
	
	delete[] arr;
	return 0;
}
