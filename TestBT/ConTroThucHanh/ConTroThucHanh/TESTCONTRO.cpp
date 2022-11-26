#include <iostream>
using namespace std;

int main()
{
    int c = 5;
    int &d = c; // Có dấu & thì 2 địa chỉ và 2 giá trị bằng nhau, không có & thì địa chỉ khác nhau

    cout << "d = " << d;
    cout << "\n&d = " << &d;
    cout << endl;
    cout << "\nc = " << c;
    cout << "\n&c = " << &c;

    /*RẮC RỐI NHƯ TRÊN SẼ GẶP NHƯ HÀM DƯỚI ĐÂY :))))))))))) mình khôn vl :) */

    // int *ham_TimMaxMinCoConTro(int *a, int n, bool MaxOrMin)
    // {
    //     /*
    // 	CHỖ NÀY NẾU KHÔNG GÁN TRUNG GIAN QUA BIẾN TEMP THÌ Ô a[0] SẼ BỊ GÁN THÀNH BIẾN MAXMIN :)) LÚ
    // 	VÌ BIẾN MAXMIN ĐANG LẤY CÙNG 1 ĐỊA CHỈ VỚI Ô a[0] :))
    //      */
    //     int temp = a[0];
    //     int &MAXMIN = temp;

    //     if (MaxOrMin == 1) // Lớn nhất
    //     {
    //         for (int i = 1; i < n; i++)
    //         {
    //             if (MAXMIN < a[i])
    //             {
    //                 MAXMIN = a[i];
    //             }
    //         }
    //     }
    //     else if (MaxOrMin == 0) // Nhỏ nhất
    //     {
    //         for (int i = 1; i < n; i++)
    //         {
    //             if (MAXMIN > a[i])
    //             {
    //                 MAXMIN = a[i];
    //             }
    //         }
    //     }
    //     return &MAXMIN;
    // }

    cout << "\n\t======================================================================================================\n\n";

    int v = 7;
    int *p = &v;

    cout << "\nv = " << v;
    cout << "\n&v = " << &v;
    cout << endl;
    cout << "\np = " << p;
    cout << "\n*p = " << *p;
    cout << "\n&p = " << &p;

    cout << endl;
    system("pause");
    return 0;
}
