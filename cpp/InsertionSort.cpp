#include <iostream>
#include <random>}
#include <ctime>
std::mt19937 Rand(time(0));
void insertionSort(int* arr, int n){
	for(int i = 0; i < n; i++){
		int j = i - 1;
		int key = *(arr + i);
		while(j >= 0 && key < *(arr + j)){
			*(arr + j + 1) = *(arr + j);
			j--;			
		}
		*(arr + j + 1) = key;
	}
}
int main(){
	std::cout<<"#### Insertion Sort ####\n";
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
	
	insertionSort(arr, n);
	
	std::cout<<'\n';
	std::cout<<"Applying InsertionSort\n";
	std::cout<<"The ordered array is"<<'\n';
    for(int i = 0; i < n; i++){
    	//std::cout<<arr[i]%100<<" ";
		std::cout<<*(arr + i)<<" ";
	}
	
	delete[] arr;
	return 0;
}