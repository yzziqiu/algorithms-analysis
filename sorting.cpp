
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define random(x) (double)rand() / RAND_MAX * 100000
using namespace std;

int *aMerge, *aQuick, *b;
int n;
int mergeCount;
int quickCount;

//mergeSort(A, 1, n);

void randomG(int n)
{
	aMerge = new int[n];
	aQuick = new int[n];
	b = new int[n];
	srand((int)time(0));
	for (int i = 0; i < n; i++)
	{
		aMerge[i] = random(100000);
		aQuick[i] = aMerge[i];
	}
}


void output(int *a)
{
	cout << "Output:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void stop_clock(clock_t start_t, int flag)
{
	char *name = (flag == 0) ? "Merge sort" : "Quick sort";
	int compare = (flag == 0) ? mergeCount : quickCount;

	clock_t stop_t = clock();
	double time = stop_t - start_t;
	cout << endl;
	cout << name;
	cout << time << "ms" << endl;
	cout << compare << endl;
}

void Merge(int *a, int *b, int low, int mid, int high) {
	for (int k = low; k <= high; k++) {
		b[k] = a[k];
	}
	int p = low;
	int q = mid + 1;
	int t = low;
	while (p <= mid && q <= high) {
		if (b[p] <= b[q])
			a[t++] = b[p++];
		else
			a[t++] = b[q++];
	}
	while (p <= mid)a[t++] = b[p++];
	while (q <= high)a[t++] = b[q++];
}


void mergeSort(int *a, int *b, int low, int high) {

	if (low >= high)return;

	int mid = (low + high) / 2;
	mergeSort(a, b, low, mid);
	mergeSort(a, b, mid + 1, high);
	Merge(a, b, low, mid, high);
}
void count_mergeSort()
{
	clock_t startM = clock();
	mergeCount = 0;
	mergeSort(aMerge, b, 0, n - 1);
	stop_clock(startM, 0);

}


void swap(int *a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void setReference(int *a, int low, int high)
{
	quickCount += 2;
	int mid = (low + high) / 2;
	if (a[mid] < a[high])
	{
		if (a[low] < a[mid]) // a[low] < a[mid] < a[high]
		{
			swap(a, low, mid);
		}
		else if (a[low] < a[high]) // a[mid] < a[low] < a[high]
		{

		}
		else // a[mid] < a[high] < a[low]
		{
			swap(a, low, high);
		}
	}
	else
	{
		if (a[mid] < a[low]) // a[high] < a[mid] < a[low]
		{
			swap(a, low, mid);
		}
		else if (a[low] > a[high]) // a[high] < a[low] < a[mid]
		{

		}
		else // a[low] < a[high] < a[mid]
		{
			swap(a, low, high);
		}
	}
}

int split(int *a, const int low, const int high)
{
	int temp = 0;
	// setReference(a, low, high);
	int refer = a[low];
	int i = low;
	for (int j = low + 1; j <= high; j++)
	{
		if (a[j] <= refer)
		{
			i++;
			// exchange(a, i, j);
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		quickCount++;
	}
	swap(a, i, low);
	return i;
}

void quicksort(int *a, int low, int high)
{
	if (low < high)
	{
		int pos = split(a, low, high);
		quicksort(a, low, pos - 1);
		quicksort(a, pos + 1, high);
	}
}

void count_quickSort()
{

	clock_t start_quick = clock();
	quickCount = 0;
	quicksort(aQuick, 0, n - 1);
	stop_clock(start_quick, 1);
}




int main() {
	int i, ch;
	char choose = 'y';
	while (choose == 'Y' || choose == 'y')
	{
		cout << "choose the way" << endl;
		cout << "1.enter by yourself" << endl;
		cout << "2.random generate" << endl;
		cin >> ch;
		if (ch == 1)
		{

			cout << "input the int, 1 <= i <= 20:";
			cin >> i;
			if (i <= 0 || i >= 21)
			{
				cout << "error" << endl;
			}
			else
			{

				n = 5000 * i;
				randomG(n);


				count_mergeSort();


				count_quickSort();
			}
		}
		else if (ch == 2)
		{
			for (i = 1; i < 21; i++)
			{
				cout << "-----------------------------------" << endl;
				n = 5000 * i;
				//cout << n << "sequence:" << endl;
				//output(n);
				randomG(n);
				count_mergeSort();


				count_quickSort();
			}
		}
		else
		{
			cout << "error" << endl;
		}


		cout << endl << "continue?y/n:";
		cin >> choose;
	}
	system("pause");
	return 0;
}
