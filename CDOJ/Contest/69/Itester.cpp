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
		ofstream fout("I.in");
		int n = 3000;
		int m = 300;
		fout << n << "\n";
		fout << m << "\n";
		for (int i = 0; i < n; ++i)
		{
			int u = -(rand() * rand() % 100000000 + 1);
			int v = rand() * rand() % 100000000 + 1;
			fout << u << " " << v << "\n";
		}
		for (int i = 0; i < m; ++i)
		{
			int u = rand() * rand() % 100000000 + 1;
			int v = rand() * rand() % 100000000 + 1;
			fout << u << " " << v << "\n";
		}
		fout.close();
		system("I.exe < I.in > I.out");
		system("Iright.exe < I.in > Iright.out");
		ifstream fin("I.out");
		ifstream fnewin("Iright.out");
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
