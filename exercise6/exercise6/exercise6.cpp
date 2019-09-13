
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string a, s1 = "Hello ";
    string s2 = "123";
    cout << a.length();
    a = s1;
    cout << a.length();
    cout << ( a == s1 ? "" : "not " ) << "equal\n";
    cout << ( a += s2 ) << endl ;
    cout << "hello world" << endl;
    reverse( a.begin(), a.end() );
    cout << a << endl;
    cout << a.replace( 0, 9, 3, 'c' ) << endl;
    cout << a.find( 'c' ) << endl;
    cout << ( s1.find( "ll" ) != -1 ? "" : "not " ) << "found" << endl;
	cout << (s1.find("ll") != -1 ? s1.find("ll"): s1.find("ll")) << "found" << endl;
	cout << (s1.find('c') != -1 ? s1.find('c') : s1.find('c')) << "found" << endl;
	cout << ( s1.find( 'c' ) != -1 ? "" : "not " ) << "found" << endl;
}
