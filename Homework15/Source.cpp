#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n, temp = 0;
	const int rows = 10;
	const int cols = 10;
	int rowSum[rows]{};

	int mx[rows][cols];
	srand(time(0));
	cout << "��������� ������:\n";
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			mx[y][x] = rand() % 100;
			cout << mx[y][x] << '\t';
			rowSum[y] += mx[y][x];
		}
		cout << endl;
	}

	// ������� 1.
	cout << "\n������� 1\n����� �����:\n";
	for (int i = 0; i < rows; i++)
		cout << rowSum[i] << "\n";
	cout << "\n";

	// ������� 2.
	cout << "������� 2\n������� ����� �� 0 �� 9 -> ";
	cin >> n;

	cout << "��������������� ���:\n";	
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols - 1; x++) {
			if (mx[n][x] > mx[n][x + 1]) {
				temp = mx[n][x];
				mx[n][x] = mx[n][x + 1];
				mx[n][x + 1] = temp;
			}
		}
	}
	
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			if (mx[n][x] == mx[y][x]) {
				cout << "*";
				cout << mx[y][x] << "\t";
			}
			else
			cout << mx[y][x] << "\t";
		}
		cout << endl;
	}

	return 0;
}