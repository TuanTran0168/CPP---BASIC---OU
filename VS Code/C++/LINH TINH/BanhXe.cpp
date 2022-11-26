#include <iostream>
using namespace std;

int main()
{
    /*
        Trong bến xe có n xe vừa xe taxi, vừa xe lam. 
        Người ta đếm thấy có tất cả k bánh xe. Hỏi có bao nhiêu xe taxi và bao nhiêu xe lam?. 
        Biết rằng xe taxi có 4 bánh xe lam có 3 bánh.
    */

    /*
        PT bậc nhất 2 ẩn lớp 9 :)

        hệ
        {
            x + y = n   (1)
            4x + 3y = k (2)
        }
        nhân -3 vào ptrinh (1)
        lấy ptrinh (1) + ptrinh (2) => x = k - 3n

        nhân -4 vào ptrinh (2)
        lấy ptrinh (1) + ptrinh (2) => y = 4n - k

   */
    do
    {
        int n, k, x, y;
        cout << "\nNhap tong so xe co trong ben xe: ";
        cin >> n;
        cout << "Nhap so banh xe: ";
        cin >> k;

        x = k - 3 * n;
        y = 4 * n - k;

        if (x >= 0 && y >= 0)
        {
            cout << "\nSo xe taxi la: " << x;
            cout << "\nSo xe lam la: " << y;
            cout << endl;
        }
        else
        {
            cout << "\nKhong tim duoc!\n";
        }

    } while (true);

    system("pause");
    return 0;
}