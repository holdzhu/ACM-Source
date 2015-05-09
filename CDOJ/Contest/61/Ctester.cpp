#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((int)time(0));
	bool flag = true;
	while (flag)
	{
		ofstream fout("C.in");
		string s;
		// for (int i = 0; i < rand() % 10 + 1; ++i)
		{
			int h = rand() % 3 + 3;
			if (h < 10)
			{
				s = s + (char)(h + '0') + "\n";
			}
			else
			{
				s = s + "10\n";
			}
			for (int i = 0; i < h; ++i)
			{
				int l = rand() % 3;
				for (int j = 0; j < 10 - l; ++j)
				{
					int t = rand() % 10;
					s = s + (char)(t + 'A');
				}
				s = s + '\n';
			}
		}
		fout << s;
		fout.close();
		system("C.exe < C.in > C.out");
		system("Cnew.exe < C.in > Cnew.out");
		ifstream fin("C.out");
		ifstream fnewin("Cnew.out");
		string t;
		string q;
		while (fin >> t)
		{
			fnewin >> q;
			if (t == q)
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
				flag = false;
			}
		}
		cout << "-------------\n";
		fin.close();
		fout.close();
	}
	return 0;
}
