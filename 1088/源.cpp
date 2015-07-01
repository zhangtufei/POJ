#include <iostream>
#include <string>
#include <algorithm>
#include <streambuf>
#include <fstream>
using namespace std;
struct Node
{
	int h;
	int i, j;
};
int map[110][110], used[110][110], msort[10010], r, c, maxl;
int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
int dfs(int x, int y)
{
	used[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx >= 0 && nx < r&&ny >= 0 && ny<c&&map[x][y]>map[nx][ny])
		{
			if (used[nx][ny])
			{
				if ( 1+used[nx][ny] > used[x][y])
				{
					used[x][y] = 1+ used[nx][ny];
				}
			}
			else
			{
				int temp = dfs(nx, ny);
				if (1+ temp>used[x][y])
					used[x][y] = 1+temp;
			}
		}
	}
	return used[x][y];
}
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> map[i][j];
		}
	}
	memset(used, 0, sizeof(used));
	maxl = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (!used[i][j] )
			{
				int temp=dfs(i, j);
				if (temp > maxl)
					maxl = temp;
			}
		}
	}
	cout << maxl << endl;
	//cin.rdbuf(bk);
	return 0;
}