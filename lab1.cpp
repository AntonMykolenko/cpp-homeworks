#include <iostream>
#include <cmath>
using namespace std;
int task1(int N);
int* task2(int N);
float task3(int N);
double task4(int N);
int task5(int N);
int task6(int N);
int task7(int N);
int task7(float N);
int task7(int N, int m);
int main()
{
	char m;
	int N; int* arr;
	do
	{
		cout << "\n1:  the number of digits in the number N;\n" <<
			"2:  organize an array whose elements are the digits of the number N; \n" <<
			"3:  the arithmetic mean of the digits of the number N; \n" <<
			"4:  the geometric mean of the digits of the number N; \n" <<
			"5:  factorial N!; \n" <<
			"6:  the sum of all even numbers from 1 to N; \n" <<
			"7:  the sum of all odd numbers from 1 to N.\n" <<
			"X:  To close the program.\n:";
		cin >> m;
		if (m != 'x' && m != 'X')
		{
			cout << "Input your number N =";
			cin >> N;
		}
		switch (m)
		{
		case '1':
			cout << endl << endl <<
				"Number " << N << " has " << task1(N) << " digits" <<
				endl << endl;
			break;
		case '2':
			arr = task2(N);
			cout << "An arr array with elements is created:\n";
			for (int i = 0; i < task1(N); i++)
			{
				cout << " / " << arr[i] << " / ";
			}
			break;
		case '3':
			cout << endl << endl << "Arithmetic mean of digits of a number " << N << " is " << task3(N) << endl << endl;
			break;
		case '4':
			cout << endl << endl << "The geometric mean of the digits of a number " << N << " is " << task4(N) << endl << endl;
			break;
		case '5':
			cout << endl << endl << "Factorial of number " << N << " is " << task5(N) << endl << endl;
			break;
		case '6':
			cout << endl << endl << "The sum of all even numbers from 1 to " << N << " is " << task6(N) << endl << endl;
			break;
		case '7':
			cout << endl << endl << "The sum of all odd numbers from 1 to " << N << " is " << task7(N) << endl << endl;
			break;
		case 'x':
		case 'X':
			cout << "Closing the program";
			break;
		default:
			cout << "Incorrect option selected.\n";
			break;
		}
	}

	while (m != 'x' && m != 'X');
}
int task1(int N)
{
	int r = 1, count = 0, save = N;
	while (N > 0) { N /= 10;   count++; }
	return count;
}
int* task2(int N)
{
	int length = task1(N);
	int i;
	int* arr = new int[length];
	for (i = length; i > 0; i--) {
		arr[i - 1] = N % 10;   N /= 10;
	}
	return arr;
}
float task3(int N)
{
	int size = task1(N);
	int summ = 0;
	int* arr = task2(N);

	int i = 0;
	do {
		summ += arr[i];
		i++;
	} while (i < size);

	return summ / (float)size;
}
double task4(int N)
{
	int size = task1(N), prod = 1; int* arr = task2(N);   int i = 0;
	while (i < size) {
		prod *= arr[i];   i++;
	}
	return pow(prod, 1. / size);
}
int task5(int N) {
	int ans = 1, i = 0;
	for (int i = 0; i < N; i++) {
		ans *= (i + 1);
	}
	return ans;
}
int task6(int N)
{
	int summ = 0;
	int i = 2;
	do
	{
		summ += i;
		i += 2;
	} while (i <= N);
	return summ;
}
int task7(int N)
{
	int summ = 0;
	int i = 1;
	do
	{
		summ += i;
		i += 2;
	} while (i <= N);
	return summ;
}
int task7(float N)
{
	cout << endl << endl << "Your input is not an integer. " << N << endl << endl; return -1;
}
int task7(int N, int m)
{
	N = N + m; int r = 1, count = 0, save = N; while (N > 0) { N /= 10;   count++; }
	return count;
}