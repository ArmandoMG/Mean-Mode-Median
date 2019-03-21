//encuentra moda,media, y mediana
#include<iostream>
#include<stdlib.h>

using namespace std;

void MMM(int *arr,int elem);
void swap(int *a, int *b);
int partition(int arr[], int low, int elem);
void quickSort(int arr[], int low, int high);
void printArray(int *arr, int elem);
void askArray(int *arr, int elem);

int main(){
	int elem, *array=NULL;
	
	cout<<"Number Of Elements in the Array: "; cin>>elem;
	array = new int[elem];
	askArray(array, elem);
	printArray(array, elem);
	quickSort(array, 0, elem);
	cout<<"\nSorted Array: "<<endl;
	printArray(array, elem);
	cout<<"Meausurements: "<<endl;
	MMM(array, elem);
	
	cout<<"\n"<<endl;
	system("PAUSE");
	return 0;
}
void MMM(int *arr,int elem){
	int contMayor = 0 , cont = 0 , half = 0;
	float mean = 0, mode = 0, median = 0;
	
	for(int i = 0; i<elem; i++){
		//1-mean 
		mean+=*(arr+i);
		//mode
		if(*(arr+i) == *(arr+i+1)){
			cont++;
		}else{
			cont++;
			if(cont > contMayor){
				contMayor = cont;
				mode = *(arr+i);
			}
			cont = 0;
		}
	}
	//2-mean
	mean /= elem;
	//median
	if(elem % 2 == 0){
		half = elem / 2;
		median = (*(arr+half) + *(arr+half-1)) / 2.0;
	}else{
		half = (elem-1) / 2;
		median = *(arr+half);
	}
	
	cout<<"\nMean of the Elements: "<<mean<<endl;
	cout<<"Mode of the Elements: "<<mode<<endl;
	cout<<"Median of the Elements: "<<median<<endl;
}
void swap(int *a, int *b){
	int aux=*a;
	*a=*b;
	*b=aux;
}
int partition(int arr[], int low, int high){//you could say that 'partition' is the helper function of quicksort
	
	int i=low-1;
	int pivot=arr[high];
	
	for(int j = low; j<=high-1; j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}
void quickSort(int arr[], int low, int high){
	if(low<high){
		int newPivot=partition(arr, low, high);
		
		quickSort(arr, low, newPivot-1);
		quickSort(arr, newPivot+1, high);
	}
}
void printArray(int *arr, int elem){
		for(int i = 0; i<elem; i++){
			cout<<*(arr+i)<<" ";
		}
	
}
void askArray(int *arr, int elem){
		for(int i = 0; i<elem; i++){
			cout<<"Elemento ["<<i<<"]: "; cin>>*(arr+i);
		}
}

