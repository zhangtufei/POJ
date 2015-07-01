#include <iostream>
#include <iomanip>
#include <streambuf>
#include <fstream>
using namespace std;
int main()
{
	//streambuf *ba;
	//fstream fin;
	//fin.open("data.txt");
	//ba = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	double h[1000];
	double temp = 0.5;
	h[1] = 0.5;
	for (int i = 2; i < 1000 && temp < 5.2; ++i)
	{
		temp += 1.0 / (i+1);
		h[i] = temp;
	}
	while (cin >> temp&&temp)
	{
		int flag = 1;
		while (temp > h[flag])
			++flag;
		cout << flag << " card(s)" << endl;
	}
	//cin.rdbuf(ba);
	return 0;
}