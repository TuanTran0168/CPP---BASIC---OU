#include<iostream>
#include <thread>
using namespace std;

long a[10000];

void sangnguyento(int head, int n)
{
	for (int i = head; i <= n; i++) {
		if (a[i] == 0) {
			for (int i1 = i * 2; i1 <= n; i1 += i) {
				a[i1] = 1;
			}
		}
	}
}

int main()
{
	
	thread task(sangnguyento, 2, 101);
	thread task1(sangnguyento, 2, 521);
	thread task2(sangnguyento, 2, 1000);
	task1.join();
	task2.join();
	task.join();

	for (int i = 2; i <= 1000; i++) {
		if (a[i] == 0)
			cout << i << "   ";
	}
	return 0;}