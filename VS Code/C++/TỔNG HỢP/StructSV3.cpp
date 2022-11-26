#include <iostream>
#include <string>
#define MAXYEAR 2020

using namespace std;

struct Date
{
    int day, month, year;
};
struct Student
{
    string name;
    string code;
    Date date;
    double markMath, markEnglish, markLiterature;
};

void inputInfor(Student &student);
void inputInfor(Student &student);
void inputList(Student *student, int numOfElements);
void outputInfor(Student student);
void outputInfor(Student student);
void outputList(Student *student, int numOfElements);
int checkDate(Date &date);
void lockingForStuCode(Student *student, int numOfElements, string code);
void lockingForStuName(Student *student, int numOfElements, string name);
void memoryAllocation(Student *&student, int oldMemory, int newMemory);
void delStuCode(Student *student, int &numOfElements, string codeStu);
void delStuName(Student *student, int &numOfElements, string nameStu);
void addStu(Student *student, int &numOfElements, Student addStu);
void fixInforStu(Student *student, int number);
void sortStuName(Student *student, int numOfElements, string nameStu);
void sortStuCode(Student *student, int numOfElements, string codeStu);
void sortStuMarkMath(Student *student, int numOfElements);
void sortStuMarkEnglish(Student *student, int numOfElements);
void sortStuMarkLiterature(Student *student, int numOfElements);
void rankStu(Student *student, int numOfElements);

int main()
{
    Student *stu;
    int numOfElements;
    int choice;
    int check = 0;

    do
    {
        system("cls");
        cout << "\n\t\t|====================================MENU====================================|";
        cout << "\n\t\t|< 1 > Input information student.                                            |";
        cout << "\n\t\t|< 1 > Output informaition student.                                          |";
        cout << "\n\t\t|< 1 > Add student into list.                                                |";
        cout << "\n\t\t|< 1 > Locking information student (name).                                   |";
        cout << "\n\t\t|< 1 > Locking information student (code).                                   |";
        cout << "\n\t\t|< 1 > Delete information student (code).                                    |";
        cout << "\n\t\t|< 1 > Fix information student.                                              |";
        cout << "\n\t\t|< 1 > Sort information student (code).                                      |";
        cout << "\n\t\t|< 1 > Sort information student (name).                                      |";
        cout << "\n\t\t|< 1 > Sort information student mark math and rank (high -> low).            |";
        cout << "\n\t\t|< 1 > Sort information student mark english and rank (high -> low).         |";
        cout << "\n\t\t|< 1 > Sort information student mark literature and rank (high -> low).      |";
        cout << "\n\t\t|< 0 > Exit.                                                                 |";
        cout << "\n\t\t|============================================================================|";
        cout << "\n=> Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // input amount
            do
            {
                cout << "- Enter amount: ";
                cin >> numOfElements;
                if (numOfElements < 1)
                    cout << "<!> Wrong input (amount > 0). Try again!\n";
            } while (numOfElements < 1);

            stu = new Student[numOfElements];

            inputList(stu, numOfElements);

            check = 1;
            break;
        }
        case 2:
        {
            if (check == 1)
                outputList(stu, numOfElements);
            else
                cout << "<!> You haven't entered infor student. Please enter and try again!\n";
            break;
        }
        default:
            break;
        }
    } while (choice != 0);

    // free pointer
    delete[] stu;
    stu = nullptr;
    system("pause");
    return 0;
}
void inputDate(Date &date)
{
    // input year
    do
    {
        cout << "\t+ Enter year: ";
        cin >> date.year;
        if (date.year < 1990 || date.year > MAXYEAR)
            cout << "<!> Wrong input. Try again!\n";
    } while (date.year < 1990 || date.year > MAXYEAR);

    // input month
    do
    {
        cout << "\t+ Enter month: ";
        cin >> date.month;
        if (date.month < 1 || date.month > 12)
            cout << "<!> Wrong input. Try again!\n";
    } while (date.month < 1 || date.month > 12);
    int maxDay = checkDate(date);

    // input day
    do
    {
        cout << "\t+ Enter day: ";
        cin >> date.day;
        if (date.day < 1 || date.day > maxDay)
            cout << "<!> Wrong input. Try again!\n";
    } while (date.day < 1 || date.day > maxDay);
}
void inputInfor(Student &student)
{
    cin.ignore();
    cout << "- Enter your name: ";
    getline(cin, student.name);
    cout << "- Enter your code: ";
    getline(cin, student.code);
    cout << "- Enter your date:\n";
    inputDate(student.date);

    // input grade
    do
    {
        cout << "- Enter your mark math: ";
        cin >> student.markMath;
        if (student.markMath < 0 || student.markMath > 10)
            cout << "<!> Wrong input. Try again!\n";
    } while (student.markMath < 0 || student.markMath > 10);

    do
    {
        cout << "- Enter your mark english: ";
        cin >> student.markEnglish;
        if (student.markEnglish < 0 || student.markEnglish > 10)
            cout << "<!> Wrong input. Try again!\n";
    } while (student.markEnglish < 0 || student.markEnglish > 10);

    do
    {
        cout << "- Enter your mark literature: ";
        cin >> student.markLiterature;
        if (student.markLiterature < 0 || student.markLiterature > 10)
            cout << "<!> Wrong input. Try again!\n";
    } while (student.markLiterature < 0 || student.markLiterature > 10);
}
void inputList(Student *student, int numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
    {
        cout << "\n\tENTER INFORMATION STUDENT " << i + 1 << endl;
        inputInfor(*(student + i));
    }
}
void outputInfor(Student student)
{
    cout << "- Name: " << student.name << endl;
    cout << "- Code: " << student.code << endl;
    cout << "- Date: " << student.date.day << "/" << student.date.month << "/" << student.date.year << endl;
    cout << "- Mark math: " << student.markMath << endl;
    cout << "- Mark english: " << student.markEnglish << endl;
    cout << "- Mark literature: " << student.markLiterature << endl;
}
void outputList(Student *student, int numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
    {
        cout << "\n\tINFORMATION STUDENT " << i + 1 << endl;
        outputInfor(*(student + i));
    }
}
int checkDate(Date &date)
{
    int day;
    switch (date.month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
    {
        day = 31;
        break;
    }
    case 2:
    {
        if (date.year & 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0)
            day = 29;
        else
            day = 28;
        break;
    }
    default:
    {
        day = 30;
        break;
    }
    }
    return day;
}
void lockingForStuCode(Student *student, int numOfElements, string code)
{
    int flag = 0;
    for (int i = 0; i < numOfElements; i++)
        if ((student + i)->code == code)
        {
            cout << "\n\tINFORMATION STUDENT\n";
            outputInfor(*(student + i));
            flag = 1;
            break;
        }
    if (flag == 0)
        cout << "<!> No information!\n";
}
void lockingForStuName(Student *student, int numOfElements, string name)
{
    int flag = 0;
    for (int i = 0; i < numOfElements; i++)
        if ((student + i)->name == name)
        {
            cout << "\n\tINFORMATION STUDENT\n";
            outputInfor(*(student + i));
            flag = 1;
            break;
        }
    if (flag == 0)
        cout << "<!> No information!\n";
}
void memoryAllocation(Student *&student, int oldMemory, int newMemory)
{
    Student *tempStu = new Student[oldMemory];
    for (int i = 0; i < oldMemory; i++)
        *(tempStu + i) = *(student + i);
    delete[] student;
    student = new Student[newMemory];
    for (int i = 0; i < newMemory; i++)
        *(student + i) = *(tempStu + i);
    delete[] tempStu;
}
void delStuCode(Student *student, int &numOfElements, string codeStu)
{
    for (int i = 0; i < numOfElements; i++)
        if ((student + i)->code == codeStu)
        {
            for (int j = i; j < numOfElements - 1; j++)
                *(student + i) = *(student + i + 1);
            --numOfElements;
            memoryAllocation(student, numOfElements + 1, numOfElements);
            break;
        }
}
void delStuName(Student *student, int &numOfElements, string nameStu)
{
    for (int i = 0; i < numOfElements; i++)
        if ((student + i)->name == nameStu)
        {
            for (int j = i; j < numOfElements; j++)
                *(student + i) = *(student + i + 1);
            --numOfElements;
            memoryAllocation(student, numOfElements + 1, numOfElements);
            break;
        }
}
void fixInforStu(Student *student, int number)
{
    int choice;

    do
    {
        system("cls");
        cout << "\n\t\t< 1 > Fix name student.";
        cout << "\n\t\t< 2 > Fix code student.";
        cout << "\n\t\t< 3 > Fix date student.";
        cout << "\n\t\t< 4 > Fix mark math.";
        cout << "\n\t\t< 5 > Fix mark english.";
        cout << "\n\t\t< 6 > Fix mark literature.";
        cout << "\n\t\t< 0 > Exit.";
        cout << "\n=> Your choice: ";
        cin >> choice;

        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            cout << "- Enter name you want to rename: ";
            getline(cin, (student + number)->name);
            cout << "\n=> Fix succesful!\n";
            break;
        }
        case 2:
        {
            cout << "- Enter code you want to recode: ";
            getline(cin, (student + number)->code);
            cout << "\n=> Fix successful!\n";
            break;
        }
        case 3:
        {
            cout << "- Enter date you want to redate: ";
            inputDate((student + number)->date);
            cout << "\n=> Fix successful!\n";
            break;
        }
        case 4:
        {
            do
            {
                cout << "- Enter your mark math: ";
                cin >> (student + number)->markMath;
                if ((student + number)->markMath < 0 || (student + number)->markMath > 10)
                    cout << "<!> Wrong input. Try again!\n";
            } while ((student + number)->markMath < 0 || (student + number)->markMath > 10);
            cout << "\n=> Fix successful!\n";
            break;
        }
        case 5:
        {
            do
            {
                cout << "- Enter your mark english: ";
                cin >> (student + number)->markEnglish;
                if ((student + number)->markEnglish < 0 || (student + number)->markEnglish > 10)
                    cout << "<!> Wrong input. Try again!\n";
            } while ((student + number)->markEnglish < 0 || (student + number)->markEnglish > 10);
            cout << "\n=> Fix successful!\n";
            break;
        }
        case 6:
        {
            do
            {
                cout << "- Enter your mark literature: ";
                cin >> (student + number)->markLiterature;
                if ((student + number)->markLiterature < 0 || (student + number)->markLiterature > 10)
                    cout << "<!> Wrong input. Try again!\n";
            } while ((student + number)->markLiterature < 0 || (student + number)->markLiterature > 10);
            cout << "\n=> Fix successful!\n";
            break;
        }
        default:
        {
            cout << "=> You choose exit!\n";
            break;
        }
        }
        system("pause");
    } while (choice != 0);
}
void sortStuName(Student *student, int numOfElements, string nameStu)
{
    for (int i = 0; i < numOfElements - 1; i++)
        for (int j = i; j < numOfElements; j++)
        {
            if ((student + i)->name < (student + j)->name)
            {
                Student tempStu = *(student + i);
                *(student + i) = *(student + j);
                *(student + j) = tempStu;
            }
        }
}
void sortStuCode(Student *student, int numOfElements, string codeStu)
{
    for (int i = 0; i < numOfElements - 1; i++)
        for (int j = i; j < numOfElements; j++)
        {
            if ((student + i)->code < (student + j)->code)
            {
                Student tempStu = *(student + i);
                *(student + i) = *(student + j);
                *(student + j) = tempStu;
            }
        }
}
void sortStuMarkMath(Student *student, int numOfElements)
{
    for (int i = 0; i < numOfElements - 1; i++)
        for (int j = i; j < numOfElements; j++)
        {
            if ((student + i)->markMath < (student + j)->markMath)
            {
                Student tempStu = *(student + i);
                *(student + i) = *(student + j);
                *(student + j) = tempStu;
            }
        }
}
void sortStuMarkEnglish(Student *student, int numOfElements)
{
    for (int i = 0; i < numOfElements - 1; i++)
        for (int j = i; j < numOfElements; j++)
        {
            if ((student + i)->markEnglish < (student + j)->markEnglish)
            {
                Student tempStu = *(student + i);
                *(student + i) = *(student + j);
                *(student + j) = tempStu;
            }
        }
}
void sortStuMarkLiterature(Student *student, int numOfElements)
{
    for (int i = 0; i < numOfElements - 1; i++)
        for (int j = i; j < numOfElements; j++)
        {
            if ((student + i)->markLiterature < (student + j)->markLiterature)
            {
                Student tempStu = *(student + i);
                *(student + i) = *(student + j);
                *(student + j) = tempStu;
            }
        }
}
void rankStu(Student *student, int numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
        cout << "\t Rank " << i + 1 << ": " << (student + i)->name << endl;
}
void addStu(Student *student, int &numOfElements, Student addStu)
{
    memoryAllocation(student, numOfElements, numOfElements + 1);
    for (int i = numOfElements; i > 0; i--)
        *(student + i) = *(student + i - 1);
    *(student + 0) = addStu;
    numOfElements++;
}