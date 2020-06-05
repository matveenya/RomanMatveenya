#include <iostream>
#include <math.h>
#include <ctime>
#include <set>
using namespace std;


class Arrays {
public:
	void giveMemory(int*& arr, const int count) {
		arr = (int*)malloc(count * sizeof(int));
		if (arr == NULL)exit(1);
	}
	void inputArray(int* arr, const int count) {
		for (int i = 0; i < count; i++) {
			cout << "arr[" << i << "] - ";
			cin >> arr[i];
		}

	}
	void inputRandomArray(int* arr, const int count) {
		for (int i = 0; i < count; i++) {
			arr[i] = rand() % 10;
		}

	}




	void freeArray(int*& arr) {
		free(arr);
		cout << "\n";
		cout << "Free Array";

	}
	int allSumArray(int* arr, int count) {
		int sum = 0;
		for (int i = 0; i < count; i++) {
			sum += arr[i];
		}
		return sum;
	}

	int sumArray(int* arr, int beg, int end) {
		int sum = 0;
		for (int i = beg; i <= end; i++) {
			sum += arr[i];
		}
		return sum;


	}
	void showArray(int* arr, const int count) {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
	}

	void sortArray(int* arr, const int count) {
		int temp;
		for (int i = 0; i < count - 1; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		cout << "Sort Array";
		cout << "\n";
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "\n";
	}

	int findMax(int* arr, int beg, int end) {
		int sum = 0;
		for (int i = beg; i <= end; i++) {
			sum += arr[i];
		}
		return sum;


	}
	void repeatingElements(int* arr, const int count) {
		set<int> mySet; 
		for (int i = 0; i < count; i++) {
			for (int j = i + 1; j < count; j++) {
				if (arr[i] == arr[j]) {
					mySet.insert(arr[j]);
				}
			}
		}
		cout << "numberRepeatingElements = " << mySet.size();
	}
};




int main() {
	int* arr;
	int sum_array, sum = 0;
	int number, begin, end = 0;
	srand(time(NULL));

	cout << "Enter Number of elmemts in the Array - ";
	cin >> number;
	if (number == 0)exit(1);
	Arrays arrays;
	arrays.giveMemory(arr, number);
	arrays.inputRandomArray(arr, number);
	sum_array = arrays.allSumArray(arr, number);

	cout << "Sum = " << sum_array;
	cout << "\n";
	cout << "Begin El-t(include) from sum = ";
	cin >> begin;
	cout << "End EL-t(include) from sum = ";
	cin >> end;
	sum = arrays.sumArray(arr, begin, end);
	cout << "Sum = " << sum;
	cout << "\n";

	arrays.showArray(arr, number);

	cout << "\n";
	arrays.sortArray(arr, number);

	arrays.repeatingElements(arr, number);


	arrays.freeArray(arr);


}