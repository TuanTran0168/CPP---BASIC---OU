#include <iostream>
using namespace std;

struct NODE
{
    int Data;
    struct NODE *Link;
};
typedef struct NODE Node;

struct LIST
{
    Node *pHead;
    Node *pTail;
};
typedef struct LIST List;

//Nguyên mẫu hàm sau khai báo struct nếu không lỗi sml
void ham_Init(List &l);
Node *ham_CreateNode(int x);
void ham_Insert_First(List &l, Node *p);
void ham_Insert_Last(List &l, Node *p);
void ham_InPut(List &l);
void ham_OutPut(List l);
Node *ham_Search(List l, int x);

void ham_Insert_AfterQ(List &l, Node *&p, Node *&q);
void ham_Insert_BeforeQ(List &l, Node *&p, Node *&q);
int ham_Length_List(List l);
void ham_Insert_Node(List &l, Node *&p, int &pos, int n);

void ham_Delete_First(List &l);
void ham_Delete_Last(List &l);
void ham_Delete_AfterQ(List &l, Node *&p, Node *&q);

int main()
{
    List l;
    Node *q;
    Node *p;
    int pos;

    while (true)
    {
        system("cls");
        ham_Init(l);
        ham_InPut(l);
        ham_OutPut(l);
        int n = ham_Length_List(l); // Hàm tìm độ dài của danh sách
        //ham_Insert_AfterQ(l, p, q);
        //ham_Insert_BeforeQ(l, p, q);
        //ham_Insert_Node(l, p, pos, n);
        //ham_Delete_First(l);
        //ham_Delete_Last(l);
        //ham_Delete_AfterQ(l, p, q);
        cout << endl;
        ham_OutPut(l);

        system("pause");
    }

    system("pause");
    return 0;
}

void ham_Init(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

Node *ham_CreateNode(int x) //Node số nguyên
{
    Node *p = new Node; //Cấp phát Node p
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat !!!";
        return NULL;
    }
    p->Data = x;
    p->Link = NULL; //Node mới chưa có liên kết nào nên trỏ đến NULL

    return p; //Trả về Node p đó có chứa x trong Data
}

void ham_Insert_First(List &l, Node *p)
{
    if (l.pHead == NULL) //Danh sách rỗng không có phần tử nào
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->Link = l.pHead;
        l.pHead = p;
    }
}

void ham_Insert_Last(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->Link = p; //Lấy link Node cuối liên kết với Node p muốn thêm
        l.pTail = p;       // Cho thằng Node cuối là Node p luôn vì Node p giờ nằm cuối rồi
    }
}

void ham_InPut(List &l)
{
    int n;
    cout << "\nNhap so luong Node: ";
    cin >> n;
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap gia tri thu " << i << ": ";
        cin >> x;

        //ham_Insert_First(l, ham_CreateNode(x));	// Nhập x vào hàm CreateNode (Tạo ra 1 Node) sau đó bỏ Node vừa khởi tạo vào hàm Insert_First (Thêm vào đầu)
        ham_Insert_Last(l, ham_CreateNode(x)); // Này cũng thế nhưng thêm vô cuối :)) Xài 1 trong 2 thôi :))
    }
}

void ham_OutPut(List l)
{
    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        cout << k->Data << " ";
    }
}

Node *ham_Search(List l, int x)
{
    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        if (k->Data == x)
            return k;
    }

    return NULL;
}

void ham_Insert_AfterQ(List &l, Node *&p, Node *&q)
{
    int Xq, Xp; // Giá trị X của p và q
    cout << "\nNhap gia tri Node q: ";
    cin >> Xq;
    cout << "\nNhap gia tri Node p: ";
    cin >> Xp;

    q = ham_CreateNode(Xq);

    if (q->Data == l.pHead->Data && l.pHead->Link == NULL)
    {
        ham_Insert_Last(l, p);
    }
    else
    {
        for (Node *k = l.pHead; k != NULL; k = k->Link)
        {
            if (k->Data == q->Data)
            {
                p = ham_CreateNode(Xp); // CHỖ NÀY PHẢI CẤP LẠI ĐỊA CHỈ (MỚI) CHO NODE P NẾU KHÔNG SẼ BỊ TUỘT MẤT LIÊN KẾT, VÌ NODE P (CŨ) SẼ TRỎ THẲNG TỚI NODE G (MỚI)
                Node *g = k->Link;      //Thêm Node g là Node kế bên Node q (tức là Node k vì Data k và q bằng nhau)
                p->Link = g;            //Nối Link Node p qua Node g
                k->Link = p;            //Cho Node k (tức là Node q ban nãy) nối tới Node p
            }
        }
    }
}

void ham_Insert_BeforeQ(List &l, Node *&p, Node *&q)
{
    int Xq, Xp;
    cout << "\nNhap gia tri Node q: ";
    cin >> Xq;
    cout << "\nNhap gia tri Node p: ";
    cin >> Xp;

    q = ham_CreateNode(Xq);

    if (q->Data == l.pHead->Data && l.pHead->Link == NULL)
    {
        ham_Insert_First(l, p);
    }
    else
    {
        Node *g = new Node; // Tạo ra Node g để lát nữa giữ vị trí Node nằm trước Node q

        for (Node *k = l.pHead; k != NULL; k = k->Link)
        {
            if (k->Data == q->Data)
            {
                p = ham_CreateNode(Xp);
                p->Link = k;
                g->Link = p;
            }
            //Sau các bước lặp không thỏa điều kiện if thì Node k sẽ dừng lại trước Node q và gán cho Node g để giữ lại.
            g = k; // Chỗ này là Node g sẽ liên kết với Node k (tức là Node trước Node q)
        }
    }
}

int ham_Length_List(List l)
{
    int count = 0;

    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        count++;
    }
    return count;
}

void ham_Insert_Node(List &l, Node *&p, int &pos, int n) //Thêm Node p vào vị trí (pos) bất kỳ
{
    int Xp;
    cout << "\nNhap vi tri ban muon them vao danh sach: ";
    cin >> pos;

    if (l.pHead == NULL || pos == 1) // Danh sách rỗng hoặc muốn thêm vào vị trí số 1 thì thêm vào đầu
    {
        cout << "\nNhap gia tri Node p: ";
        cin >> Xp;
        ham_Insert_First(l, ham_CreateNode(Xp));
    }
    else if (pos == n + 1)
    {
        cout << "\nNhap gia tri Node p: ";
        cin >> Xp;
        ham_Insert_Last(l, ham_CreateNode(Xp)); //Thêm cuối
    }
    else // Vị trí nằm trong khoảng [2, n]
    {
        int Xp;
        cout << "\nNhap gia tri Node p: ";
        cin >> Xp;

        Node *g = new Node; // Tạo ra Node g để lát nữa giữ vị trí Node nằm trước Node q
        int count = 0;      //Biến đếm xác định vị trí

        for (Node *k = l.pHead; k != NULL; k = k->Link)
        {
            count++;
            if (count == pos) //Biến đếm (count) đã đếm lên tới vị trí (pos) cần thêm
            {
                p = ham_CreateNode(Xp);
                p->Link = k;
                g->Link = p;
                break;
            }
            //Sau các bước lặp không thỏa điều kiện if thì Node k sẽ dừng lại trước Node q và gán cho Node g để giữ lại.
            g = k; // Chỗ này là Node g sẽ liên kết với Node k (tức là Node trước Node q)
        }
    }
}

void ham_Delete_First(List &l)
{
    if (l.pHead == NULL) //Danh sách rỗng thì khỏi xóa
    {
        return;
    }
    else
    {
        Node *p = l.pHead;       // Lấy Node p giữ Node đầu (Node l.pHead) là Node thí mạng thôi :))
        l.pHead = l.pHead->Link; // Cập nhật Node đầu (Node l.pHead) là Node kế tiếp
        delete p;                // Xóa thôi :)))
    }
}

void ham_Delete_Last(List &l)
{
    if (l.pHead->Link == NULL) //Trường hợp danh sách có một phần tử thì xóa đầu
    {
        ham_Delete_First(l);
        return;
    }

    if (l.pHead == NULL) //Danh sách rỗng
    {
        return;
    }
    else
    {
        for (Node *k = l.pHead; k != NULL; k = k->Link)
        {
            //Lúc này trong vòng lặp đang dừng lại ở (Node k) ở vị trí kế Node cuối (Node l.pTail) nên điều kiện if là (k->Link) tức là Node l.pTail
            if (k->Link == l.pTail)
            {
                delete l.pTail; //Xóa Node cuối
                k->Link = NULL; //Cho Node kế cuối trỏ đến NULL vì Node cuối (Node l.pTail) bay màu rồi :)
                l.pTail = k;    //Cập nhật Node cuối thành Node k
                return;
            }
        }
    }
}

void ham_Delete_AfterQ(List &l, Node *&p, Node *&q)
{
    int Xq;
    cout << "\nNhap gia tri Node q: ";
    cin >> Xq;

    q = ham_CreateNode(Xq);

    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        if (k->Data == q->Data) // Tìm vị trí Node q
        {
            p = k->Link;       // Cho Node p giữ giá trị của Node nằm sau Node q để tí xóa
            k->Link = p->Link; // Cho Node q (Tức Node k luôn vì Data của k = q) liên kết với Node phía sau Node p
            delete p;          // Xóa :)
        }
    }
}