#include <iostream>
#include <stack>
#include <streambuf>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("data.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	stack<string> fw, back;
	string cur, cmd;
	string c1 = "VISIT", c2 = "BACK", c3 = "FORWARD", c4 = "QUIT", c5 = "Ignored";
	cur = "http://www.acm.org/";
	while (cin >> cmd&&cmd != c4)
	{
		if (cmd == c1)
		{
			back.push(cur);
			while (!fw.empty())
				fw.pop();
			cin >> cur;
		}
		else if (cmd == c2)
		{
			if (back.empty())
			{
				cout << c5 << endl;
				continue;
			}
			fw.push(cur);
			cur = back.top();
			back.pop();
		}
		else if (cmd == c3)
		{
			if (fw.empty())
			{
				cout << c5 << endl;
				continue;
			}
			back.push(cur);
			cur = fw.top();
			fw.pop();
		}
		cout << cur<<endl;
	}
	//cin.rdbuf(bk);
	return 0;
}