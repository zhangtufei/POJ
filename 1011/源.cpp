#include <iostream>
#include <streambuf>
#include <fstream>
#include <algorithm>
using namespace std;
int n, stick[65], sum, goal;
bool visit[65];
bool Comp(int a, int b)
{
	return a > b;
}
bool dfs(int now, int index, int cnt)
{
	if (goal*cnt == sum)
		return true;
	for (int i = index; i < n; ++i)
	{
		if (visit[i] || (i&&!visit[i - 1] && stick[i] == stick[i - 1]))
			continue;
		if (now + stick[i] == goal)
		{
			visit[i] = true;
			if (dfs(0, 0, cnt + 1))
				return true;
			visit[i] = false;
			return false;
		}
		else if (now + stick[i] < goal)
		{
			visit[i] = true;
			if (dfs(now + stick[i], i + 1, cnt))
				return true;
			visit[i] = false;
			if (now == 0)
				return false;
		}
	}
	return false;
}
int sovle()
{
	sort(stick, stick + n, Comp);
	for (goal = stick[0]; goal < sum; ++goal)
	{
		if (sum%goal)
			continue;
		memset(visit, false, sizeof(visit));
		if (dfs(0, 0, 0))
			break;
	}
	return goal;
}
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	while (cin >> n&&n)
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> stick[i];
			sum += stick[i];
		}
		cout << sovle() << endl;
	}
	//cin.rdbuf(bk);
	return 0;
}