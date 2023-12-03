#include <iostream>
#include <algorithm>
#include <climits> // Підключення для INT_MAX
#include <Windows.h>
const int ROWS = 15;
const int COLS = 2;
// Функція для сортування рядка за зростанням
void sortRow(int row[]) {
	std::sort(row, row + COLS);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int array[ROWS][COLS] = {
	{3, 9},
	{5, 2},
	{8, 1},
	{4, 7},
	{6, 5},
	{9, 4},
	{2, 8},
	{7, 3},
	{1, 6},
	{0, 0},
	{11, 10},
	{13, 12},
	{15, 14},
	{17, 16},
	{19, 18}
	};
	int minSum = INT_MAX;
	int minRow1 = -1, minRow2 = -1;
	// Знаходження номерів рядків з мінімальною сумою елементів
	for (int i = 0; i < ROWS - 1; ++i) {
		int currentSum = array[i][0] + array[i][1] + array[i + 1][0] + array[i +
			1][1];
		if (currentSum < minSum) {
			minSum = currentSum;
			minRow1 = i;
			minRow2 = i + 1;
		}
	}
	// Сортування рядків з мінімальною сумою елементів
	if (minRow1 != -1 && minRow2 != -1) {
		sortRow(array[minRow1]);
		sortRow(array[minRow2]);
	}
	// Виведення результатів
	std::cout << "Рядки з мінімальною сумою елементів: " << minRow1
		<< " та " << minRow2 << std::endl;
	// Виведення відсортованих рядків
	for (int i = 0; i < ROWS; ++i) {
		std::cout << "Рядок " << i << ": " << array[i][0] << " " << array[i][1]
			<< std::endl;
	}
	return 0;
}