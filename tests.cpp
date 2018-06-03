#include "sort.cpp"
#include <gtest/gtest.h>

bool greater(int a, int b) {
	return a < b;
}

bool less(int a, int b) {
	return a > b;
}

bool chargreater(char a, char b) {
	return a < b;
}

bool strsizegrt(std::string a, std::string b) {
	return a.length() < b.length();
}


TEST(SortingTest, SortIntegers) {
	
	int arr[8] = {0, 4, 7, 5, 3, 1, 2, 6};
	int sarr[8] = {0, 1, 2, 3, 4, 5, 6, 7};

	quickSort<int>(arr, 7, false, greater);

	for (int i = 0; i < 8; i++) {
		ASSERT_EQ(arr[i], sarr[i]);
	}
}

TEST(SortingTest, SortIntegersBackward) {
	
	int arr[8] = {0, 4, 7, 5, 3, 1, 2, 6};
	int sarr[8] = {7, 6, 5, 4, 3, 2, 1, 0};

	quickSort<int>(arr, 7, true, greater);

	for (int i = 0; i < 8; i++) {
		ASSERT_EQ(arr[i], sarr[i]);
	}
}

TEST(SortingTest, SortIntegersBackwardByLessFunction) {
	
	int arr[8] = {0, 4, 7, 5, 3, 1, 2, 6};
	int sarr[8] = {7, 6, 5, 4, 3, 2, 1, 0};

	quickSort<int>(arr, 7, false, less);

	for (int i = 0; i < 8; i++) {
		ASSERT_EQ(arr[i], sarr[i]);
	}
}

TEST(SortingTest, SortChars) {

	char arr[8] = {'E', 'G', 'D', 'A', 'C', 'B', 'F', 'H'};
	char sarr[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

	quickSort<char>(arr, 7, false, chargreater);
	
	for (int i = 0; i < 8; i++) {
		ASSERT_EQ(arr[i], sarr[i]);
	}
}

TEST(SortingTest, SortCharsBackward) {

	char arr[8] = {'E', 'G', 'D', 'A', 'C', 'B', 'F', 'H'};
	char sarr[8] = {'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};

	quickSort<char>(arr, 7, true, chargreater);
	
	for (int i = 0; i < 8; i++) {
		ASSERT_EQ(arr[i], sarr[i]);
	}
}

TEST(SortingTest, SortStringBySize) {

	std::string arr[8] = {
		"ccc",
		"ggggggg",
		"eeeee",
		"bb",
		"hhhhhhhh",
		"dddd",
		"a",
		"ffffff"
	};

	std::string sarr[8] = {
		"a",
		"bb",
		"ccc",
		"dddd",
		"eeeee",
		"ffffff",
		"ggggggg",
		"hhhhhhhh"
	};

	quickSort<std::string>(arr, 7, false, strsizegrt);
	
	for (int i = 0; i < 8; i++) {
		ASSERT_EQ(arr[i], sarr[i]);
	}
}

TEST(SortingTest, SortStringByDefaultComparator) {

	std::string arr[8] = {
		"ccc",
		"ggggggg",
		"eeeee",
		"bb",
		"hhhhhhhh",
		"dddd",
		"a",
		"ffffff"
	};

	std::string sarr[8] = {
		"a",
		"bb",
		"ccc",
		"dddd",
		"eeeee",
		"ffffff",
		"ggggggg",
		"hhhhhhhh"
	};

	quickSort<std::string>(arr, 7, true);
	
	for (int i = 0; i < 8; i++) {
		ASSERT_EQ(arr[i], sarr[i]);
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}