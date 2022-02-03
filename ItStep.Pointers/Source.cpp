#include <iostream>
using namespace std;

#pragma region Common methods

int Min(int a, int b) {
	return a < b ? a : b;
}

int Max(int a, int b) {
	return a > b ? a : b;
}

void PrintArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void PrintArray(int** arr, int rows, int columns) {
	for (int i = 0; i < rows; i++)
		PrintArray(arr[i], columns);
	cout << endl;
}

void FillArray(int* arr, int size, int min, int max) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min + 1) + min;
}

void FillArray(int** arr, int rows, int columns, int min, int max) {
	for (int i = 0; i < rows; i++)
		FillArray(arr[i], columns, min, max);
}

bool TryGetPositive(int* value) {
	cin >> *value;
	return *value >= 0;
}

#pragma endregion

#pragma region Task 6

void SumArrayItems(int* arr1, int size1, int* arr2, int size2, int* arr3) {
	int minSize = Min(size1, size2);
	for (int i = 0; i < minSize; i++)
		arr3[i] = arr1[i] + arr2[i];
	for (int i = minSize; i < size1; i++)
		arr3[i] = arr1[i];
	for (int i = minSize; i < size2; i++)
		arr3[i] = arr2[i];
}

void Task6() {
	int size1, size2;
	cin >> size1 >> size2;

	int size3 = Max(size1, size2);

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	int* arr3 = new int[size3];

	FillArray(arr1, size1, 0, 9);
	FillArray(arr2, size2, 0, 9);

	SumArrayItems(arr1, size1, arr2, size2, arr3);

	PrintArray(arr1, size1);
	PrintArray(arr2, size2);
	PrintArray(arr3, size3);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
}

#pragma endregion

#pragma region Task 7

int* ConvertTo1D(int** arr, int rows, int columns, int* size) {
	*size = rows * columns;
	int* resultArray = new int[*size];

	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			resultArray[k++] = arr[i][j];

	return resultArray;
}

void Task7() {
	int N, M;
	cin >> N >> M;

	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[M];

	FillArray(arr, N, M, 1, 20);

	PrintArray(arr, N, M);

	int size;
	int* arr2 = ConvertTo1D(arr, N, M, &size);

	PrintArray(arr2, size);

	for (int i = 0; i < N; i++)
		delete[] arr[i];
	delete[] arr;

	delete[] arr2;
}

#pragma endregion

#pragma region Task 11

void RecreateArrayAndAdd1Item(int** arr, int* size) {
	int* newArr = new int[*size + 1];
	for (int i = 0; i < *size; i++)
		newArr[i] = (*arr)[i];

	(*size)++;
	delete[] * arr;
	*arr = newArr;
}

void Task11() {
	int size = 1;
	int* arr = new int[size];

	cin >> arr[0];
	if (arr[0] < 0)
		return;

	PrintArray(arr, size);

	while (true) {
		int value;
		cin >> value;

		if (value < 0)
			break;

		RecreateArrayAndAdd1Item(&arr, &size);
		arr[size - 1] = value;

		PrintArray(arr, size);
	}

	delete[] arr;
}

void Task11_2() {
	int size = 1;
	int* arr = new int[size];

	if (!TryGetPositive(&arr[0]))
		return;

	PrintArray(arr, size);

	int value;
	while (TryGetPositive(&value)) {
		RecreateArrayAndAdd1Item(&arr, &size);
		arr[size - 1] = value;

		PrintArray(arr, size);
	}

	delete[] arr;
}

#pragma endregion

#pragma region Task 12

int** ConvertTo2D(int* arr, int size, int rows, int columns) {
	if (size != rows * columns)
		return nullptr;

	int** resultArray = new int* [rows];
	for (int i = 0; i < rows; i++)
		resultArray[i] = new int[columns];

	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			resultArray[i][j] = arr[k++];

	return resultArray;
}

void Task12() {
	int size;
	cin >> size;

	int* arr = new int[size];

	FillArray(arr, size, 0, 20);

	PrintArray(arr, size);

	int rows, columns;
	cin >> rows >> columns;

	int** arr2 = ConvertTo2D(arr, size, rows, columns);
	if (arr2 == nullptr) {
		cout << "Invalid sizes" << endl;

		delete[] arr;
		return;
	}

	PrintArray(arr2, rows, columns);

	delete[] arr;

	for (int i = 0; i < rows; i++)
		delete[] arr2[i];
	delete[] arr2;
}

#pragma endregion

#pragma region Task 13

void AddRow(int**& arr, int& rows, int columns) {
	int** newArr = new int* [rows + 1];

	for (int i = 0; i < rows; i++)
		newArr[i] = arr[i];
	newArr[rows++] = new int[columns];

	delete[] arr;
	arr = newArr;
}

void Task13() {
	int rows, columns;
	cin >> rows >> columns;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[columns];

	FillArray(arr, rows, columns, 0, 9);

	PrintArray(arr, rows, columns);

	AddRow(arr, rows, columns);
	FillArray(arr[rows - 1], columns, 0, 9);

	PrintArray(arr, rows, columns);
}

#pragma endregion

void main() {
	srand(time(0));

	//Task6();
	//Task7();
	//Task11();
	//Task11_2();
	//Task12();
	Task13();

	system("pause");
}