#include <iostream>
#include <streambuf>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
#define PI 3.1415926
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	cin >> n;
	int i = 0;
	while (++i<= n)
	{
		double x, y;
		cin >> x >> y;
		x *= x;
		y *= y;
		double r2 = x + y;
		double ye;
		ye = r2*PI / 2.0;
		int year = (int)(ceil(ye/50));
		cout << "Property " << i << ": This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	//cin.rdbuf(bk);
	return 0;
}