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
		ofstream fout("B.in");
		int n = 100;
		fout << n << "\n";
		for (int i = 0; i < n; ++i)
		{
			int u = rand() % 10 + 1;
			int v = rand() % 10 + 1;
			fout << u << " " << v << "\n";
		}
		fout.close();
		system("B.exe < B.in > B.out");
		system("Bright.exe < B.in > Bright.out");
		ifstream fin("B.out");
		ifstream fnewin("Bright.out");
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
