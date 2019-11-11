#include "pch.h"
#include <iostream>
#include <vector>

std :: vector<int> add( const std::vector<int> &a, const std::vector<int> &b )
{
    std::vector<int> res( a );

    for(unsigned int i = 0; i < a.size(); i++ )
    {
        res[i] += b[i];
    }

    return res;
}
int main()
{
    std::vector<int> a = { 1, 2, 3 };
    std::vector<int>res = add( a, a );
	std::cout << res[0];
}



