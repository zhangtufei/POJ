#include <iostream>
#include <algorithm>
#include <math.h>
#include <streambuf>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	double vs, r, c;
	int n;
	cin >> vs >> r >> c >> n;
	while (n--)
	{
		double w, vr, temp;
		cin >> w;
		temp = c*r*w;
		vr = temp*vs / sqrt(1 + temp*temp);
		cout.precision(3);
		cout << fixed<< vr << endl;
	}
	//cin.rdbuf(fin.rdbuf());
	return 0;
}