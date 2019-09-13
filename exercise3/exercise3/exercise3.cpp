
//求Pi的方法
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <iostream>
int main() {
	using namespace std;
	int z = ((5 > 8) ? 9 : 9);
	cout << ((5 > 8) ? 9 : 2)<< " aaa " << z << endl;
	double sum = 0, item = 1;
	for (int n = 1; abs(item) > 1e-6; ++n) {
		item *= (-1.0)*(2 * n - 3) / (2 * n - 1);
		sum += item;
	}
	cout << "Pi = " << fixed << sum * 4 << endl;
}
