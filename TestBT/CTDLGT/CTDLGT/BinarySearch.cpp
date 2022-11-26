#include <iostream>
#define MAX 10
using namespace std;
void BinarySearch(int a[], int n, int X);

int main ()
{
	int a[MAX] = {1, 2, 3, 4, 4, 4, 5, 6, 8, 8};
	int b[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	BinarySearch(a, MAX, 8);

	system("pause");
	return 0;
}

void BinarySearch(int a[], int n, int X)
{
	int count = 0;
	int b[MAX];
    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == X)
		{
			b[count] = mid;
			while (a[mid--] == X)
			{
				b[++count] = mid;
				right--;
				
			}
			while (a[mid++] == X)
			{
				b[++count] = mid;
				left++;
			}
		}
        if (X > a[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }

	cout << "Xuat hien " << count << " lan va o cac vi tri: ";
	for (int i = 0; i < count; i++)
		cout << b[i] << " ";
	cout << "\nEm thua roi" << endl;
}