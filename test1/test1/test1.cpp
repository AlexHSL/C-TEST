#include "pch.h"
#include <iostream>
using namespace std;
int printEachLine( int j )
{
    if( j == 0 )
        return 1;
    else
    {
        cout << "* ";

        printEachLine( j - 1 );


        return 1;
    }
}

int print( int i )
{
    if( i == 0 )
        return 1;
    else
    {
        print( i - 1 );

        printEachLine( i );

        cout << endl;
        return 1;
    }
}

int main()
{
    print( 4 );
}