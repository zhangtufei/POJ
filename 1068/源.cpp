#include <iostream>
#include <streambuf>
#include <fstream>
using namespace std;
int dp[60];
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char a[60];
		int flag = 0;
		int n1 = 0, n2 = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> n2;
			for (int i = 0; i < n2 - n1; ++i)
				a[flag++] = '(';
			a[flag++] = ')';
			n1 = n2;
		}
		memset(dp, 0, sizeof(dp));
		flag = 0;
		for (int i = 0; i <2* n; ++i)
		{
			if (a[i] == ')')
			{
				++flag;
				int sum = 1;
				for (int j = i - 1; j >= 0; --j)
				{
					if (a[j] == '(')
					{
						if (!dp[j])
						{
							if (flag == n)
								cout << sum << endl;
							else
								cout << sum << ' ';
							dp[j] = 1;
							break;
						}
						else
						{
							++sum;
						}
					}
				}
			}
		}
	}
	//cin.rdbuf(bk);
	return 0;
}