#include <iostream>
#include <streambuf>
#include <fstream>
#include <map>
using namespace std;
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int p, e, i, d;
	int flag = 1;
	while (cin >> p >>e>> i >> d)
	{
		if (p == -1)
			break;
		int temp;
		//注意：day 可能在题目所给p e i之前
		int p1 = p % 23;
		int e1 = e % 28;
		int i1 = i % 33;
		temp = i1;
		//注意：这里要小于等于n，而不是21252
		int n = 21252 + d;
		while (temp <=n)
		{
			while (temp <= d)
				temp += 33;
			if ((temp - e1) % 28 == 0 && (temp - p1) % 23 == 0)
			{
				if (temp == p&&temp == e&&temp == i)
					continue;
				cout << "Case " << flag++ << ": the next triple peak occurs in " << temp - d << " days." << endl;
				break;
			}
			temp += 33;
		}
		//int temp = 33+i;
		//map<int, int> mi;
		//++mi[temp];
		//while (temp <= 21252)
		//{
		//	++mi[temp + 33];
		//	temp += 33;
		//}
		//temp = 28 + e;
		//while (temp <= 21252)
		//{

		//	if (mi[temp]&&temp > d && (temp - p) % 23 == 0)
		//	{
		//		cout << "Case " << flag++ << ": the next triple peak occurs in " << temp -d<< " days." << endl;
		//		break;
		//	}
		//	temp += 28;
		//}
	}
	//cin.rdbuf(bk);
	return 0;
}