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



int main()
{

	system("pause");
	return 0;
}

void Init(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void Process(List l)
{
	Node *p = l.pHead;
	while(p != NULL)
	{
		cout << 
	}
}