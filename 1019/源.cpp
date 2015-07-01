#include <iostream>
#include <streambuf>
#include <fstream>
#include <algorithm>
#include<vector>
using namespace std;
int a[32010];
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	a[1] = 1;
	for (int i = 2; i <= 32000; ++i)
	{
		if (i < 10)
			a[i] = a[i - 1] + 1;
		else if (i < 100)
			a[i] = a[i - 1] + 2;
		else if (i < 1000)
			a[i] = a[i - 1] + 3;
		else if (i < 10000)
			a[i] = a[i - 1] + 4;
		else if (i < 100000)
			a[i] = a[i - 1] + 5;
	}
	int t;
	cin >> t;
	while (t--)
	{
		long long sum = 0,num;
		cin >> num;
		int i = 1;
		int re;
		while (sum + a[i] < num)
		{
			sum += a[i++];
		}
		for (int j = 1; j <= i; ++j)
		{
			int temp;
			if (j < 10)
				temp = 1;
			else if (j < 100)
				temp = 2;
			else if (j < 1000)
				temp = 3;
			else if (j < 10000)
				temp = 4;
			else if (j < 100000)
				temp = 5;
			sum += temp;
			if (sum >= num)
			{
				while (sum >= num)
				{
					re = j % 10;
					j /= 10;
					--sum;
				}
				cout << re << endl;
				break;
			}
		}
	}
	//cin.rdbuf(bk);
	return 0;
}