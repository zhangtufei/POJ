#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <streambuf>
#include <fstream>
using namespace std;
int main()
{
	//streambuf *ba;
	//fstream fin;
	//fin.open("data.txt");
	//ba = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	map<string, int> ma;
	cin >> n;
	while (n--)
	{
		
		string s_in;
		cin >> s_in;
		string s;
		for (int i = 0; i < s_in.size(); ++i)
		{
			if (s_in[i] >= '0'&&s_in[i] <= '9')
				s += s_in[i];
			else if (s_in[i] >= 'A'&&s_in[i] <= 'P')
				s += ((s_in[i] - 'A') / 3 + 2 + '0');
			else if (s_in[i]>'Q'&&s_in[i] < 'Z')
				s += ((s_in[i] - 'A' - 1) / 3 + 2 + '0');
		}
		s.insert(s.begin() + 3, '-');
		++ma[s];
	}
	map<string, int>::iterator iter = ma.begin();
	bool flag = false;
	for (; iter != ma.end(); ++iter)
	{
		if (iter->second > 1)
		{
			flag = true;
			cout << iter->first << ' ' << iter->second << endl;
		}
	}
	if (!flag)
		cout << "No duplicates." << endl;
	//cin.rdbuf(ba);
	return 0;
}