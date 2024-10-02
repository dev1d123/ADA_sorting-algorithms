#include <bits/stdc++.h>
std::mt19937 Rand(time(0));

void bubbleSort(int* arr, int n){
	for(int i = 0; i < n - 1; i++){
		bool swaped = false;
		for(int j = 0; j < n - 1 - i; j++){
			int& e1 = *(arr + j);
			int& e2 = *(arr + j + 1);
			
			if(e1 > e2){
				//std::swap(e1, e2);
				int temp = e1;
				e1 = e2;
				e2 = temp;
				swaped = true;
			}
		}
		if(!swaped) break;
	}
}
int main(){
	std::cout<<"#### Bubble Sort ####\n";
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
	
	bubbleSort(arr, n);
	std::cout<<'\n';
	std::cout<<"Applying BubbleSort\n";
	std::cout<<"The ordered array is"<<'\n';
    for(int i = 0; i < n; i++){
    	//std::cout<<arr[i]%100<<" ";
		std::cout<<*(arr + i)<<" ";
	}
	
	delete[] arr;
	return 0;
}