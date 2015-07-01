#include <iostream>
#include <streambuf>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	//streambuf *bk;
	//bk = cin.rdbuf();
	//fstream fin;
	//fin.open("data.txt");
	//cin.rdbuf(fin.rdbuf());
	double sum = 0, temp;
	for (int i = 0; i < 12; ++i)
	{
		cin >> temp;
		temp /= 12.0;
		sum += temp;
	}
	cout.precision(2);
	cout << '$' << fixed << sum << endl;
	//cin.rdbuf(bk);
	return 0;
}