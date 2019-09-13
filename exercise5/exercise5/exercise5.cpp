
#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char* s1 = "Hello ";
	const char* s2 = "123";
	char a[20];
	strcpy_s(a, s1);
	cout << (strcmp(a, s1) == 0 ? "" : "not ") << "equal\n";
	cout << strcat_s(a, s2) << endl;
	cout << a << endl;
	cout << _strrev(a) << endl;
	cout << _strset_s(a, 'c') << endl;
	cout << a << endl;
	cout << (strstr(s1, "ell") ? "" : "not ") << "found\n";
	cout << (strchr(s1, 'c') ? "" : "not ") << "found\n";

}
