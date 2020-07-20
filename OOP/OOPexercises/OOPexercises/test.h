#pragma once
#include <vector>
using namespace std;
class test
{
protected:
    int price;
    int length;
public:
	static vector<test*> v;
    int getPrice();
    test();
    ~test();
};

