#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
#include<algorithm>

std::vector<int> readVectorFromFile(std::string fileName) {
	std::ifstream file("input.txt");
	if (!file.is_open()) {
		std::cout << "Can not open the file" << std::endl;
		std::vector<int> vec;
		return vec;
	}
	std::vector<int> vec{ std::istream_iterator<int>(file), std::istream_iterator<int>() };
	file.close();
	return vec;
}

std::vector<int> fillFromCin() {
	int num;
	std::vector<int> vec;
	while (std::cin >> num && num != 0) {
		vec.push_back(num);
	}
	return vec;
}

//std::vector<int> fillRandom(double* array, int size) {
//
//}

void insertionSortSquareBrakets(std::vector<int> & arr) {
	if (arr.size() > 1) {
		for (int i = 1; i < arr.size(); i++) {
			int j = i;
			while (j > 0 && arr[j] < arr[j - 1]) {
				std::swap(arr[j], arr[j - 1]);
				j--;
			}
		}
	}
}

void insertionSortAtOperator(std::vector<int>& arr) {
	if (arr.size() > 1) {
		for (int i = 1; i < arr.size(); i++) {
			int j = i;
			while (j > 0 && arr.at(j) < arr.at(j - 1)) {
				std::swap(arr.at(j), arr.at(j - 1));
				j--;
			}
		}
	}
}


void insertionSortIterator(std::vector<int>& arr) {
	if (arr.size() > 1) {
		std::vector<int>::iterator current = arr.begin() + 1;
		std::vector<int>::iterator temp;
		for (current; current != arr.end(); ++current) {
			temp = current;
			while (temp != arr.begin() && *(temp - 1) > *temp) {
				std::swap(*temp, *(temp - 1));
				--temp;
			}
		}
	}
}


void printVector(const std::vector<int>& arr) {
	std::vector<int>::const_iterator element = arr.begin();
		for (element; element != arr.end(); element.operator++()) {
			std::cout << *element << " ";
	}
		std::cout << std::endl;
}


int main(int argc, char* argv[]) {
	std::string inputFile = "input.txt";
	std::vector<int> arr1 = {12, 4, -5, 1, 0};
	std::vector<int> arr2 = arr1;
	std::vector<int> arr3 = readVectorFromFile(inputFile);
	std::vector<int> arr4 = arr1;
	std::vector<int> arr5;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;

	start = std::chrono::steady_clock::now();
	insertionSortSquareBrakets(arr1);
	end = std::chrono::steady_clock::now();
	printVector(arr1);
	std::cout << "Insertion sort with brakets access: " << (end-start).count() << " s." << std::endl;

	start = std::chrono::steady_clock::now();
	insertionSortAtOperator(arr2);
	end = std::chrono::steady_clock::now();
	printVector(arr2);
	std::cout << "Insertion sort with at access: " << (end - start).count() << " s." << std::endl;

	start = std::chrono::steady_clock::now();
	insertionSortIterator(arr3);
	end = std::chrono::steady_clock::now();
	printVector(arr3);
	std::cout << "Insertion sort with iterator access: " << (end - start).count() << " s." << std::endl;

	start = std::chrono::steady_clock::now();
	std::sort(arr4.begin(), arr4.end());
	end = std::chrono::steady_clock::now();
	printVector(arr4);
	std::cout << "Built-in std::sort : " << (end - start).count() << " s." << std::endl;

	arr5 = fillFromCin();
	printVector(arr5);

	return 0;
}