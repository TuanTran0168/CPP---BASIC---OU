#include <iostream>
using namespace std;
const int MAXSIZE = 100;
void Input(int Arr[MAXSIZE], int &Size);
void Output(int Arr[MAXSIZE], int Size);
int Search(int Arr[MAXSIZE], int Size, int x);
int Insert(int Arr[MAXSIZE], int &Size, int pos, int x);
void Insert1(int Arr[MAXSIZE], int &Size, int pos, int x);
int Delete(int Arr[MAXSIZE], int &Size, int pos);

int main()
{
	int Arr[MAXSIZE];
	int Size;
	int choose;
	do
	{
		system("cls");
		cout << "\n1. Nhap mang";
		cout << "\n2. Xuat mang";
		cout << "\n3. Tim kiem";
		cout << "\n4. Them";
		cout << "\n5. Xoa";

		cout << "\n\nMoi ban nhap: ";
		cin >> choose;

		if (choose == 1)
		{
			Input(Arr, Size);
		}
		if (choose == 2)
		{
			Output(Arr, Size);
		}
		if (choose == 3)
		{
			int x;
			cout << "\nNhap x can tim: ";
			cin >> x;

			if (Search(Arr, Size, x) != -1)
				cout << x << " nam o vi tri " << Search(Arr, Size, x);
			else
				cout << "Khong co trong mang";
		}

		if (choose == 4)
		{
			int pos, x;
			cout << "\nNhap vi tri them: ";
			cin >> pos;
			cout << "\nNhap gia tri can them: ";
			cin >> x;
			
			int KQ = Insert(Arr, Size, pos, x);
			if (KQ == 0)
				cout << "\nKhong du kha nang luu tru";
			if (KQ == -1)
				cout << "\nVi tri them khong hop le";
			if (KQ == 1)
				cout << "\nThem thanh cong";
		
			/*Insert1(Arr, Size, pos, x);*/

			cout << "\n\nSize: " << Size;
		}
		if (choose == 5)
		{
			int pos;
			cout << "\nNhap vi tri can xoa: ";
			cin >> pos;

			int KQ = Delete(Arr, Size, pos);
			if (KQ == -1)
				cout << "\nVi tri xoa khong hop le";
			if (KQ == 1)
				cout << "\nXoa thanh cong";
		}

		system("pause");
	} while (choose != 0);

	system("pause");
	return 0;
}

void Input(int Arr[MAXSIZE], int &Size)
{
	do
	{
		cout << "\nNhap size cua mang: ";
		cin >> Size;
		if (Size < 1 || Size > 100)
			cout << "\nNhap sai dieu kien, moi nhap lai";

	}while(Size < 1 || Size > 100);

	for (int i = 0; i < Size; i++)
	{
		cout << "Nhap phan tu thu " << i << ": ";
		cin >> Arr[i];
	}
}

void Output(int Arr[MAXSIZE], int Size)
{
	cout << "\nCac phan tu trong mang la: " << endl;
	for (int i = 0; i < Size; i++)
	{
		cout << Arr[i] << " ";
	}
}

int Search(int Arr[MAXSIZE], int Size, int x)
{
	for (int i = 0; i < Size; i++)
	{
		if (Arr[i] == x)
		{
			return i;
		}
	}
	return -1;

	/*int j = 0;
	while (j < Size && Arr[j] != x)
	{
		j++;
	}
	if (j == Size)
		return -1;
	return j;*/
	
}

int Insert(int Arr[MAXSIZE], int &Size, int pos, int x)
{
	//Full Mang tra ve 0
	if (Size + 1 > MAXSIZE)
		return 0;
	// Vi tri them khong hop le tra ve -1
	if (pos < 0 || pos > Size)
		return -1;

	//Tim duoc tra ve 1
	// 1 2 3 4 5
	//     2
	// 1 2 69 3 4 5
	for (int i = Size - 1; i >= pos; i--)
	{
		Arr[i + 1] = Arr[i];
	}
	Arr[pos] = x;
	Size++;
	return 1;
}

void Insert1(int Arr[MAXSIZE], int &Size, int pos, int x)
{
	//Full Mang tra ve 0
	if (Size + 1 > MAXSIZE)
		return;
	// Vi tri them khong hop le tra ve -1
	if (pos < 0 || pos > Size)
		return;
	//Tim duoc tra ve 1
	// 1 2 3 4 5
	//     2
	// 1 2 69 3 4 5
	for (int i = Size - 1; i >= pos; i--)
	{
		Arr[i + 1] = Arr[i];
	}
	Arr[pos] = x;
	Size++;
}

int Delete(int Arr[MAXSIZE], int &Size, int pos)
{
	if (pos < 0 || pos > Size)
		return -1;
	else
	{
		for (int i = pos; i < Size; i++)
		{
			Arr[i] = Arr[i + 1];
		}
		Size--;
		return 1;
	}
}