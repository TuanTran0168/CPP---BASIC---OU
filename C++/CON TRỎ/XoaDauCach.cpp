#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    cout << "Nhap cai gi di: ";
    char *a = new char[100];
    cin.getline(a, 100);

    char *b = new char[100];
    char *token = strtok(a, " ");

    /*
	//TEST COI CÁI HÀM strtok với TOKEN COI NÓ CHẠY SAO :))

	cout << strlen(token) << endl;

    cout << token << endl;
    token = strtok(NULL, " ");

    cout << token << endl;
    token = strtok(NULL, " ");

    cout << token << endl;
    token = strtok(NULL, " ");*/

    /*************************************************************************************************/

    int count = 0;
    while (token != NULL)
    {
        for (int i = 0; i < strlen(token); i++) // Chạy đếm số lượng của token thứ nhất
        {
            b[count] = token[i]; // Gán từng kí tự của token vào mảng b, Biến count dùng để giữ chỉ số cho mảng b được liên tục
            count++;             // Nếu để b[i] = token[i] thì xong token đầu tiên tới token tiếp theo nó lại gán vào ô số 0 của mảng b => Mất token cũ
        }
        b[count++] = ' '; // Gán xong 1 token thì thêm 1 khoảng trắng vô cho đẹp
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++)
    {
        cout << b[i];
    }

    delete[] a;
    delete[] b;

    system("pause");
    return 0;
}

// Ý TƯỞNG CỦA NGƯỜI TA
//long i = 0;
//   while (token != NULL)
//   {
//       for (int dem = 0; dem < strlen(token); i++) // for này chạy theo số lượng chữ cái trong biến token;	Còn i++ kia là cho mảng b;
//       {
//           b[i] = token[dem++]; // Gán token đầu tiên vào mảng b
//       }
//       b[i++] = ' '; // Gán xong một token thì thêm 1 khoảng trắng
//       token = strtok(NULL, " ");
//   }
// for (int i1 = 0; i1 < i; i1++)
//   {
//       cout << b[i1];
//   }