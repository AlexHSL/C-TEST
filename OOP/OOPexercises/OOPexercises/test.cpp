#include "pch.h"
//#include "test.h"
//#include <iostream>

int test::getPrice()
{
    return price;
}

test::test()
{
    price = 100;
    length = 0;
}


test::~test()
{
}
vector<test*> test::v;
