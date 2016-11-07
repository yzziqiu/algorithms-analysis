
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int a[9][9];

//input array
/*void input() {
cout << "please input the sudoku number:" << endl;
for (i = 1; i <= 9; i++)
for (j = 1; j <= 9; j++)
cin >> a[i][j];
}/*
//check the space where can fill in
/*int checkSpace(int a[9][9]) {
for (i = 1; i <= 9; i++)
for (j = 1; j <= 9; j++) {
if (a[i][j] == 0) {
return true;
}
else
return false;
}
}*/


int checkNum(int count)
{
	int row = count / 9;
	int col = count % 9;
	int j;
	//same r
	for (j = 0; j < 9; ++j) {
		if (a[row][j] == a[row][col] && j != col) {
			return false;
		}
	}
	//same col
	for (j = 0; j < 9; ++j) {
		if (a[j][col] == a[row][col] && j != row) {
			return false;
		}
	}
	//same grid
	int tempRow = row / 3 * 3;
	int tempCol = col / 3 * 3;
	for (j = tempRow; j < tempRow + 3; ++j) {
		for (int k = tempCol; k < tempCol + 3; ++k) {
			if (a[j][k] == a[row][col] && j != row && k != col) {
				return false;
			}
		}
	}
	return true;
}

void solution(int count) {
	int row = count / 9;
	int col = count % 9;
	if (count == 81) {
		cout << "result£º" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}

	}

	if (a[row][col] == 0) {
		for (int i = 1; i <= 9; i++) {
			a[row][col] = i;
			if (checkNum(count)) { //ok
				solution(count + 1);//next
			}
		}
		a[row][col] = 0;//back
	}
	else {
		solution(count + 1);
	}
}



int main()
{
	clock_t start, finish;
	int c;
	cout << "please choose the way:" << endl;
	cout << "*******************1.using existing array**********2.input the array by yourself********"<<endl;
	
	cin >> c;
	switch (c)
	{
	case 1: {
		
		int	a[9][9] = { { 3, 4, 1, 0, 0, 2, 0, 7, 5 },
		{ 0, 5, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 0, 0, 8, 0, 0, 2, 0, 0 },
		{ 0, 0, 0, 6, 0, 0, 0, 9, 4 },
		{ 0, 0, 0, 2, 0, 9, 0, 0, 0 },
		{ 4, 9, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 9, 0, 0, 7, 0, 0, 0 },
		{ 0, 3, 0, 0, 0, 0, 0, 5, 0 },
		{ 2, 7, 0, 9, 0, 0, 0, 1, 3 } };
		start = clock();
		solution(0);
		finish = clock();
		double dura = (double)(finish - start);
		cout << "Time used" << dura;
		
	}
	case 2: {
		cout << "enter the data" << endl;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				cin >> a[i][j];
		}
		start = clock();
		solution(0);
		finish = clock();
		double dura = (double)(finish - start);
		cout << "Time used" << dura<<"ms"<<endl;
	}
	}

	system("pause");
	return 0;

}
