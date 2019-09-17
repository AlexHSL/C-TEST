#include "pch.h"
#include <iostream>_

void g(int& i);
void f(int& i);
using namespace std;
int main()
{
	//using namespace std;
	////对指针的熟悉
	//int a = 1;
	//int *t=&a;
	//*t = a;
	//cout << (*t += 1) << " " << a << endl;
	////
	int count = 1;
	g(count);
	f(count);
}
void g(int& i)
{
	cout << "call g()" << endl;
	if (i > 100) return;
	i++;
	f(i);
}

void f(int& i)
{
	cout << "call f()" << endl;
	if (i > 100) return;
	i++;
	g(i);
}
