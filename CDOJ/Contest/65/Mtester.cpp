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
		ofstream fout("M.in");
		int n = 3;
		int m = 3;
		fout << n << " ";
		fout << m << "\n";
		for (int i = 0; i < n - 1; ++i)
		{
			int u = rand() % (i + 1) + 1;
			int v = i + 2;
			fout << u << " " << v << " " << rand() % 10 << " " << rand() % 10 << "\n";
		}
		for (int i = 0; i < m; ++i)
		{
			fout << rand() % n + 1 << " ";
		}
		fout.close();
		system("Mnew.exe < M.in > Mnew.out");
		system("Mright.exe < M.in > Mright.out");
		ifstream fin("Mnew.out");
		ifstream fnewin("Mright.out");
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
