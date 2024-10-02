#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
std::mt19937 Rand(time(0));
void selectionSort(int* arr, int n){
	for(int i = 0; i < n; i++){
		//find the smallest from i
		int maxVar = INT_MAX;
		int* ptr = nullptr;
		for(int j = i; j < n; j++){
			if(*(arr + j) < maxVar){
				ptr = (arr + j);
				maxVar = *(arr + j);
			}
		}
    	std::swap(*(arr + i), *ptr);
	}
}
int main(){
	std::cout<<"#### Selection Sort ####\n";
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
	
	selectionSort(arr, n);
	
	std::cout<<'\n';
	std::cout<<"Applying SelectionSort\n";
	std::cout<<"The ordered array is"<<'\n';
    for(int i = 0; i < n; i++){
    	//std::cout<<arr[i]%100<<" ";
		std::cout<<*(arr + i)<<" ";
	}
	
	delete[] arr;
	return 0;
}