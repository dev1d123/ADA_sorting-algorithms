#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
std::mt19937 Rand(time(0));


void siftUp(int *h, int i, int n){
	int leftC = 2*i + 1;
	int rightC = 2*i + 2;
	int maxChild = i;
	if(leftC < n && *(h + leftC) > *(h + maxChild)) maxChild = leftC;
	if(rightC < n && *(h + rightC) > *(h + maxChild)) maxChild = rightC;
	if(maxChild != i){
		std::swap(*(h+i), *(h+maxChild));
		siftUp(h, maxChild, n);
	}
}	


void buildMaxHeap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftUp(arr, i, n); 
    }
}

void heapSort(int* arr, int n){
    buildMaxHeap(arr, n);
	for(int i = n-1; i > 0; i--){
		std::swap(*(arr+0), *(arr+i));
		siftUp(arr, 0, i);
	}	
	cout<<endl;
}
int main(){
	std::cout<<"#### Heap Sort ####\n";
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
	
	heapSort(arr, n);
	
	std::cout<<'\n';
	std::cout<<"Applying HeapSort\n";
	std::cout<<"The ordered array is"<<'\n';
    for(int i = 0; i < n; i++){
    	//std::cout<<arr[i]%100<<" ";
		std::cout<<*(arr + i)<<" ";
	}
	
	delete[] arr;
	return 0;
}

