#include <iostream>
#include <functional>

template <class Type>
void quickSort(
	
	Type* array, 
	int size, 
	bool isReverse=false, 
	std::function<bool (const Type&, const Type&)> comparing = std::greater<Type>()

) {

	int i = 0;
	int j = size;
	Type object = array[size >> 1];

	while (i <= j) {

		if (not isReverse) {

			for (; comparing(array[i], object); i++);
			for (; comparing(object, array[j]); j--);

		} else {

			for (; comparing(object, array[i]); i++);
			for (; comparing(array[j], object); j--);

		}

		if (i <= j) {

			std::swap(array[i], array[j]);
			i++;
			j--;
		}
	}

	if (j > 0) {
		quickSort(array, j, isReverse, comparing);
	}

	if (size > i) {
		quickSort(array + i, size-i, isReverse, comparing);
	}
}

/*int main() {

	int arr[8] = {0, 4, 7, 5, 3, 1, 2, 6};

	quickSort<int>(arr, 7, false, grt);
	for (int i = 0; i < 8; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;


	char carr[8] = {'b', 'e', 'd', 'a', 'h', 'f', 'c', 'g'};
	quickSort<char>(carr, 7, false, cgrt);
	for (int i = 0; i < 8; i++) {
		std::cout << carr[i] << ' ';
	}
	std::cout << std::endl;


	return 0;
}*/