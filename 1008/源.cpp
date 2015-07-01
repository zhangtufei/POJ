#include <iostream>
#include <string>
#include <streambuf>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
string mon[19] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac"
, "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
string days[21] = { "","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb"
, "ben", "ix","mem", "cib", "caban", "eznab", "canac", "ahau" };
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	cin >> n;
	vector<int> vd, vy;
	vector<string> vm;
	int day, year;
	string month;
	char c;
	for (int i = 1; i <= n; ++i)
	{
		cin >> day >> c >> month >> year;
		vd.push_back(day);
		vy.push_back(year);
		vm.push_back(month);
	}
	cout << n << endl;
	long long ds = 0;
	for (int i = 0; i < n; ++i)
	{
		ds = vy[i] * 365 + vd[i] + 1;
		for (int j = 0; j <= 18; ++j)
		{
			if (vm[i] == mon[j])
			{
				ds += (j * 20);
				break;
			}
		}
		year = ds / 260;
		ds %= 260;
		if (ds == 0)
		{
			--year;
			ds = 260;
		}
		day = ds % 13;
		if (day == 0)
		{
			day = 13;
		}
		ds %= 20;
		if (ds == 0)
		{
			ds = 20;
		}
		month = days[ds];
		cout << day << ' ' << month << ' ' << year << endl;
	}
	//cin.rdbuf(bk);
	return 0;
}