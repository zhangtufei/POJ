/*
题目POJ 1001，用字符串实现浮点数的幂。
输入如：95.123的12次幂
0.4321的20次幂
5.1234^15
6.7592 ^9
98.999^10
1.0100^12

输出：
548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
*/
#include <iostream>
#include <string>
#include <vector>
#include <streambuf>
#include <fstream>
using namespace std;
string stra(string a, string b)
{
	if (a.size() < b.size())
	{
		string temp = a;
		a = b;
		b = temp;
	}
	int temp = 0;
	int j = a.size() - 1;
	for (int i = b.size() - 1; i >= 0; --i,--j)
	{
		int x = (a[j] - '0') + (b[i] - '0') + temp;
		a[j] = x % 10 + '0';
		temp = x / 10;
	}
	while (temp&&j>=0)
	{
		int x = a[j] - '0' + temp;
		a[j--] = x % 10+'0';
		temp = x / 10;
	}
	if (temp)
	{
		char c = temp + '0';
		a = c + a;
	}
	return a;
}
string strm(string re, string s)
{
	vector<string> ans;
	string st;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		int temp = 0;
		string t=re;
		int j = t.size() - 1;
		for (; j >= 0; --j)
		{
			int x = (s[i] - '0')*(t[j] - '0') + temp;
			t[j] = x % 10 + '0';
			temp = x / 10;
		}
		if (temp)
		{
			char c = temp + '0';
			t = c + t;
		}
		t += st;
		st += '0';
		ans.push_back(t);
	}
	st = ans[0];
	for (int i = 1; i < ans.size(); ++i)
	{
		st = stra(ans[i], st);
	}
	return st;
}
int main()
{
	//streambuf *backup;
	//fstream fin;
	//fin.open("data.txt");
	//backup = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	string s;
	int n;
	while (cin >> s >> n)
	{
		string re,temp;
		int p=0;
		bool flag = false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != '.')
				re += s[i];
			else
			{
				p = i;
				flag = true;
			}
		}
		if (flag)
		{
			if (p == 0)
				re = "0" + re;
			p = s.size() - p - 1;
		}
		temp = re;
		for (int i = 1; i < n; ++i)
		{
			re = strm(re, temp);
		}
		p *= n;
		if (p)
		{
			p = re.size() - p;
			re.insert(p, ".");
		}
		int beg = 0;
		while (re[beg] == '0')
			++beg;
		int ed = re.size() - 1;
		if (p)
		{
			while (re[ed] == '0')
				--ed;
			if (re[ed] == '.')
				--ed;
		}
		for (int i = beg; i <= ed; ++i)
			cout << re[i];
		cout << endl;
	}
	//cin.rdbuf(backup);
	return 0;
}