
#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char** argv)
{
	if (argc != 3) return 0;
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	return 0;
}
 
