#include<iostream>
#include <vector>

void insertionSortSquareBrakets(std::vector<int> & arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			std::swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void insertionSortAtOperator(std::vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i;
		while (j > 0 && arr.at(j) < arr.at(j - 1)) {
			std::swap(arr.at(j), arr.at(j - 1));
			j--;
		}
	}
}


void insertionSortIterator(std::vector<int>& arr) {
	std::vector<int>::iterator current = arr.begin() + 1;
	std::vector<int>::iterator temp;
	for (current; current < arr.end(); current.operator++()) {
		temp = current;
		while (temp > arr.begin() && *(temp - 1) > *temp) {
			std::swap(*temp, *(temp - 1));
			temp.operator--();
		}
	}
}


void printVector(const std::vector<int>& arr) {
	std::vector<int>::const_iterator element = arr.begin();
		for (element; element < arr.end(); element.operator++()) {
			std::cout << *element << " ";
	}
		std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	std::vector<int> arr1 = {12, 4, -5, 1, 0};
	std::vector<int> arr2 = arr1;
	std::vector<int> arr3 = arr1;
	insertionSortSquareBrakets(arr1);
	insertionSortAtOperator(arr2);
	insertionSortIterator(arr3);
	printVector(arr1);
	printVector(arr2);
	printVector(arr3);
	return 0;
}