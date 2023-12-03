#include <iostream>
#include <algorithm>
#include <climits> // ϳ��������� ��� INT_MAX
#include <Windows.h>
const int ROWS = 15;
const int COLS = 2;
// ������� ��� ���������� ����� �� ����������
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
	// ����������� ������ ����� � ��������� ����� ��������
	for (int i = 0; i < ROWS - 1; ++i) {
		int currentSum = array[i][0] + array[i][1] + array[i + 1][0] + array[i +
			1][1];
		if (currentSum < minSum) {
			minSum = currentSum;
			minRow1 = i;
			minRow2 = i + 1;
		}
	}
	// ���������� ����� � ��������� ����� ��������
	if (minRow1 != -1 && minRow2 != -1) {
		sortRow(array[minRow1]);
		sortRow(array[minRow2]);
	}
	// ��������� ����������
	std::cout << "����� � ��������� ����� ��������: " << minRow1
		<< " �� " << minRow2 << std::endl;
	// ��������� ������������ �����
	for (int i = 0; i < ROWS; ++i) {
		std::cout << "����� " << i << ": " << array[i][0] << " " << array[i][1]
			<< std::endl;
	}
	return 0;
}