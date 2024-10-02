#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
std::mt19937 Rand(time(0));

int partition(int *arr, int start, int end){
	int pivot = arr[end];
	int i = start - 1;
	for(int j = start; j <= end - 1; j++){
		if(arr[j] < pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	i++;
	int temp = arr[i];
	arr[i] = arr[end];
	arr[end] = temp;
	return i;
}
void quickSort(int* arr,int start, int end){
    if(start >= end) return;
     
    int pivot = partition(arr, start, end);
	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);
}
int main(){
	std::cout<<"#### Quick Sort ####\n";
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
	
	quickSort(arr, 0, n - 1);
	
	std::cout<<'\n';
	std::cout<<"Applying Quicksort\n";
	std::cout<<"The ordered array is"<<'\n';
    for(int i = 0; i < n; i++){
    	//std::cout<<arr[i]%100<<" ";
		std::cout<<*(arr + i)<<" ";
	}
	
	delete[] arr;
	return 0;
}
