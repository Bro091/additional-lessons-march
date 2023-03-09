#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Вывод массива в консоль

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
// Заполнение массива случ. числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	static int add = 0;
	srand(time(NULL) + add); 
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
	add++;
}

void formula(double a, double b) {
	if (a)
		std::cout << "x = " << -b / a << std::endl;
	else
		std::cout << " Ошибка ввода! \n";
}
void formula(double a, double b, double c) {
	double D = b * b - 4 * a * c;
	if (a)
		if (D < 0)
			std::cout << " Корней нет! \n";
		else
			if (D == 0)
				std::cout << "x = " << -b / (2 * a) << std::endl;
			else {
				std::cout << "x1 = " << (-b - sqrt(D)) / (2 * a) << std::endl;
				std::cout << "x2 = " << (-b + sqrt(D)) / (2 * a) << std::endl;

			}

	else
		formula(b, c);

}

template <typename T>
void revers_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		arr[i] *= (-1);
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Сложение массивая
	/*const int size = 10;
	int arr1[size];
	int arr2[size];
	fill_arr(arr1, size, 1, 11);
	std::cout << "Массив 1:\n";
	print_arr(arr1, size);
	fill_arr(arr2, size, 1, 11);
	std::cout << "Массив 2:\n";
	print_arr(arr2, size);

	// для итого что бы массивы были заполнены разными числами, нужно либоо ввести переменную add либо поменять диапазоны массивов, например первый массивы от 1 до 10, дургой от 0 до 20
	//С доп массивом
	//int sum_arr[size];
	//for (int i = 0; i < size; i++) {
	//	sum_arr[i] = arr1[i] + arr2[i];
	//}
	//std::cout << "Итоговый массив:\n";
	//print_arr(sum_arr,size);

	//cntrlе + shift+ \

	// Без доп массива
	std::cout << "Итоговый массив:\n ";
	for (int i = 0; i < size; i++)
		std::cout << arr1[i] + arr2[i] << ' ';*/

	// Уравнения
	/*std::cout << "2x^2 + 7x - 11 = 0\n";
	formula(2, 7, -11);
	std::cout << "5.5x + 0.1 = 0\n";
	formula(5.5, 0.1);
	std::cout << "0x^2 + 6x + 2 = 0\n";
	formula(0, 6, 2);*/

	// Отражение двумерного массива
	const int rows = 5;
	const int cols = 4;
	int mx[rows][cols];
	std::cout << "Изначальный массив:\n";
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mx[i][j] = rand() % (10 + 1 - (-10)) + (-10);
			std::cout << mx[i][j] << '\t';
		}
		std::cout << '\n';
	}
	
	for (int i = 0; i < rows; i++)
		revers_arr(mx[i], cols);
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) 
			std::cout << mx[i][j] << '\t';
		std::cout << '\n';
	}

	return 0;

}
