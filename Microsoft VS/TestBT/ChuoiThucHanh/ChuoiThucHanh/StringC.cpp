#include <iostream>
#include <cstring>
using namespace std;

int ham_DemChu_C_String(char *s);
int ham_DemSo_C_String(char *s);
int ham_DemKhoangTrang_C_String(char *s);
void ham_ChuyenInHoaInThuong_C_String(char *s);
char *ham_ChuyenInHoaInThuong_C_String_NEW(char *s);
void ham_ChuyenInHoaInThuong_C_String_NEW1(char *s);

int main()
{
    const int MaxChar = 100;
    char s[MaxChar];
    cout << "So ky tu: " << strlen(s) << endl;

    cout << "Nhap cai gi di: ";
    cin.getline(s, 50);
    cout << "\nChuoi ban vua nhap: " << s << endl;

    cout << "\nSo ky tu chu co trong chuoi la: " << ham_DemChu_C_String(s);
    cout << "\nSo ky tu so co trong chuoi la: " << ham_DemSo_C_String(s);
    cout << "\nSo khoang trang co trong chuoi la: " << ham_DemKhoangTrang_C_String(s);
    cout << endl;

    cout << ham_ChuyenInHoaInThuong_C_String_NEW(s);
    //ham_ChuyenInHoaInThuong_C_String_NEW1(a);

    system("pause");
    return 0;
}

int ham_DemChu_C_String(char *s)
{
    /*char *ptr = s;*/
    int count = 0;

    while (*s) // while (*s) = while (*s != NULL)
    {
        if (isalpha(*s)) // Hàm trả về số khác 0 (tức khác NULL cũng được) nếu chuỗi s là chữ
        {
            count++;
        }
        s++;
    }

    /*delete ptr;
	ptr = NULL;*/

    return count;
}

int ham_DemSo_C_String(char *s)
{
    int count = 0;

    while (*s)
    {
        if (isdigit(*s))
        {
            count++;
        }
        s++;
    }

    return count;
}

int ham_DemKhoangTrang_C_String(char *s)
{
    int count = 0;

    while (*s)
    {
        if (isspace(*s))
        {
            count++;
        }
        s++;
    }

    return count;
}

void ham_ChuyenInHoaInThuong_C_String(char *name)
{
    char *token = strtok(name, " ");

    while (token != NULL)
    {
        if (token[0] >= 97 && token[0] <= 122)
        {
            token[0] = token[0] - 32;
        }

        for (int i = 1; i < strlen(token); i++)
        {
            if (token[i] >= 65 && token[i] <= 90)
            {
                token[i] = token[i] + 32;
            }
        }

        cout << token << endl;
        token = strtok(NULL, " ");
    }
}

char *ham_ChuyenInHoaInThuong_C_String_NEW(char *s)
{
    char *token = strtok(s, " ");
    static char NewChar[1000];

    while (token != NULL)
    {
        if (token[0] >= 97 && token[0] <= 122)
        {
            token[0] = token[0] - 32;
        }

        for (int i = 1; i < strlen(token); i++)
        {
            if (token[i] >= 65 && token[i] <= 90)
            {
                token[i] = token[i] + 32;
            }
        }
        strcat(NewChar, token);
        strcat(NewChar, " ");
        token = strtok(NULL, " ");
    }

    return NewChar;
}

void ham_ChuyenInHoaInThuong_C_String_NEW1(char *s)
{
    char *token = strtok(s, " ");
    static char NewChar[1000];

    while (token != NULL)
    {
        if (token[0] >= 97 && token[0] <= 122)
        {
            token[0] = token[0] - 32;
        }

        for (int i = 1; i < strlen(token); i++)
        {
            if (token[i] >= 65 && token[i] <= 90)
            {
                token[i] = token[i] + 32;
            }
        }
        strcat(NewChar, token);
        strcat(NewChar, " ");
        token = strtok(NULL, " ");
    }
    cout << NewChar;
}