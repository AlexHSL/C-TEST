#include "pch.h"
#include <iostream>
using namespace std;
int count_num_1( int number )
{
    if( number == 1 )
    {
        return 1;
    }
    else if( number == 0 )
    {
        return 0;
    }
    else
    {
        return count_num_1( number ) + number % 2;
    }
}
int main()
{
    int num;
    cout << "输入数字，输出该数字二进制表示中1的个数:";
    cin >> num;
    cout << "结果是:" << count_num_1( num );
}
