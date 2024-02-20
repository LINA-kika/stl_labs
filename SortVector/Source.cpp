#include<iostream>
#include <vector>

void insertionSortSquareBrakets(std::vector<int> & arr) {
	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j - 1] > arr[j]) {
				std::swap(arr[j - 1], arr[j]);
			}
		}
	}
}

void insertionSortAtOperator(std::vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (arr.at(j-1) > arr.at(j)) {
				std::swap(arr.at(j-1), arr.at(j));
			}
		}
	}
}

void insertionSortIterator(std::vector<int>& arr) {
	std::vector<int>::iterator current = arr.begin()+1;
	std::vector<int>::iterator temp;
	for (current; current < arr.end(); current.operator++()) {
		for (temp = current; temp > arr.begin(); temp.operator--()) {
			if (*(temp-1) > *temp) {
				std::swap(*temp, *(temp-1));
			}
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