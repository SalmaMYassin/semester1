#include<iostream>

using namespace std;

int counter = 0;

void display(int *arr, int size){
	cout << "Sorted: ";             /*********************/
	for (int i = 0; i<size; i++){   /*    A function to  */
		cout << arr[i] << " ";      /* display the array */
	}                               /*      elements     */
	cout << endl;					/*********************/
	
	cout << "Counts through the whole sorting prosses: " << counter;
	cout << endl;
}

void Swap(int &arr1, int &arr2){

	int temp;

	temp = arr1;
	arr1 = arr2;
	arr2 = temp;

	counter++;
}

int partition(int *arr, int firstIndex, int lastIndex){

	int i;

	i = firstIndex - 1;
	int	pivot = arr[lastIndex];

	for (int j = firstIndex; j < lastIndex; j++){
		if (arr[j] <= pivot){
			i++;
			Swap(arr[i], arr[j]);
		}
	}

	Swap(arr[i + 1], arr[lastIndex]);
	return i + 1;
}

void quickSort(int *arr, int firstIndex, int lastIndex){
	if (firstIndex < lastIndex){

		int p = partition(arr, firstIndex, lastIndex);

		quickSort(arr, firstIndex, p - 1);
		quickSort(arr, p + 1, lastIndex);
	}
}


int main(){

	int *Arr;
	int size;
	cout << "Enter size of Array:";
	cin >> size;
	Arr = new int[size];

	for (int i = 0; i < size; i++){

		cout << "Enter number:";
		cin >> Arr[i];
	}


	quickSort(Arr, 0, size - 1);
	display(Arr, size);


	return 0;

}
