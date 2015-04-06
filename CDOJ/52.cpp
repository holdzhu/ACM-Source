#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node
{
	int P;
	string wordB;
	string wordC;
};

int S;
int s;
int step;
int mins;
map<string, Node *> m;
const char null[] = {"NULL"};

void dfs(Node * node)
{
	if (s >= S && mins > step)
	{
		mins = step;
		return;
	}
	if (node->wordB != null)
	{
		s += node->P;
		step++;
		dfs(m[node->wordB]);
		step--;
		s -= node->P;
	}
	if (node->wordC != null)
	{
		dfs(m[node->wordC]);
	}
	if (s + node->P >= S && mins > step + 1)
	{
		mins = step + 1;
		return;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N >> S;
		m.clear();
		string a;
		Node * mainNode;
		for (int i = 0; i < N; ++i)
		{
			string wordA;
			int P;
			string wordB;
			string wordC;
			cin >> wordA >> P >> wordB >> wordC;
			Node * node = new Node();
			if (i == 0)
			{
				mainNode = node;
			}
			node->P = P;
			node->wordB = wordB;
			node->wordC = wordC;
			m.insert(pair<string, Node *>(wordA, node));
		}
		s = 0;
		step = 0;
		mins = N + 1;
		dfs(mainNode);
		if (mins < N + 1)
		{
			cout << mins << '\n';
		}
		else
		{
			cout << "impossible" << '\n';
		}
	}
	return 0;
}
