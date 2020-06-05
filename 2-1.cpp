//() В массиве А(N,М) найти строку, для которой количество перемен знаков максимально и поменять её с первой строкой.
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h> 

using namespace std;
int** array_generator(int dim1, int dim2) {
	int** ptrary = new int* [dim1];
	for (int i = 0; i < dim1; i++) {
		ptrary[i] = new int[dim2];
	}
	return ptrary;
}

void array_destroyer(int** ary, int dim1) {
	for (int i = 0; i < dim1; i++) {
		delete[] ary[i];
	}
	delete[] ary;
	cout << "\n" << "successful delete array";
}

void array_randomInit(int** arr, int dim1, int dim2) {
	for (int i = 0; i < dim1; i++) {
		for (int j = 0; j < dim2; j++) {
			arr[i][j] = rand() % 21 - 10;
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}
}

void array_init(int** arr, int dim1, int dim2) {
	for (int i = 0; i < dim1; i++) {
		for (int j = 0; j < dim2; j++) {
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
		cout << "\n";
	}
}


void array_print(int** arr, int dim1, int dim2) {
	cout << "\n";
	for (int i = 0; i < dim1; i++) {
		for (int j = 0; j < dim2; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}
}
void array_quantityChanges(int** arr, int dim1, int dim2) {
	int quantity = 0;
	int maxQuantity = 0;
	int numberStr = 0;
	for (int i = 0; i < dim1; i++) {
		for (int j = 0; j < dim2 - 1; j++) {
			if ((arr[i][j] >= 0 && arr[i][j + 1] < 0) || (arr[i][j] < 0 && arr[i][j + 1] >= 0))quantity++; 
		}
		if (quantity > maxQuantity) {//find maxQuantity
			maxQuantity = quantity;
			numberStr = i; //Str with maxQuntity
			// cout<<"Find Str = "<<numberStr<<" quantity = "<<quantity<<", ";//check
		}
		quantity = 0;

	}
	int tmp;
	cout << "\n" << "swap: ";
	for (int i = 0; i < dim2; i++) { //swap 1 str and str with maxQuantity
		tmp = arr[0][i];
		arr[0][i] = arr[numberStr][i];
		arr[numberStr][i] = tmp;
	}
}

int main() {

	int** matrix;
	int DIM1 = 0, DIM2 = 0;
	cin >> DIM1;
	cin >> DIM2;

	matrix = array_generator(DIM1, DIM2);


	array_randomInit(matrix, DIM1, DIM2);

	//array_init(matrix, DIM1, DIM2);
	//array_print(matrix,DIM1, DIM2);

	array_quantityChanges(matrix, DIM1, DIM2);

	array_print(matrix, DIM1, DIM2);

	array_destroyer(matrix, DIM1);
	return 0;
}


