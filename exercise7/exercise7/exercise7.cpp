
#include "pch.h"
#include <iostream>

//因为高中同学提到*&的问题，就看了一下，本来以为会很好玩，结果发现其实没什么，应该是他理解错了
int main()
{
    using namespace std;
    int temp = 1;
    int temp2 = *&temp;
	int x = temp;
    cout << temp << endl;
	cout << temp2 << endl;
	cout << x << endl;
    cout << ( temp = temp + 1 ) << temp2 << endl;
	cout << temp << endl;
	cout << temp2 << endl;
	cout << x << endl;

}
