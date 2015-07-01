#include <iostream>
#include <string>
#include <algorithm>
#include <streambuf>
#include <fstream>
using namespace std;
struct DNA{
	string s;
	int x;
};
DNA a[110];
int dp[110];
void sovle(DNA &a)
{
	for (int i = a.s.size() - 1; i >= 0; --i)
	{
		if (a.s[i] == 'A')
			continue;
		for (int j = i + 1; j <= a.s.size() - 1; ++j)
		{
			if (a.s[i] > a.s[j])
				++dp[i];
			else if (a.s[i] == a.s[j])
			{
				dp[i] += dp[j];
				break;
			}
		}
		a.x += dp[i];
	}
}
bool Comp(DNA a, DNA b)
{
	if (a.x == b.x)
		return a.s < b.s;
	else
		return a.x < b.x;
}
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a[i].s;
		a[i].x = 0;
		memset(dp, 0, sizeof(dp));
		sovle(a[i]);
	}
	sort(a + 1, a + m+ 1, Comp);
	for (int i = 1; i <= m; ++i)
	{
		cout << a[i].s << endl;
	}
	//cin.rdbuf(bk);
	return 0;
}