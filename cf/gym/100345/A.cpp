#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Name
{
	vector<string> name;
	bool operator < (const Name& rhs) const
	{
		if (name.back() != rhs.name.back())
		{
			return name.back() < rhs.name.back();
		}
		int len = min(name.size() - 1, rhs.name.size() - 1);
		for (int i = 0; i < len; ++i)
		{
			if (name[i] != rhs.name[i])
			{
				return name[i] < rhs.name[i];
			}
		}
		return name.size() < rhs.name.size();
	}
	bool operator != (const Name& rhs) const
	{
		return *this < rhs || rhs < *this;
	}
};

struct Reference
{
	string type;
	vector<Name> author;
	string title;
	string journal;
	string publisher;
	string year;
	string volume;
	string number;
	string pages;
	bool operator < (const Reference& rhs) const
	{
		int len = min(author.size(), rhs.author.size());
		for (int i = 0; i < len; ++i)
		{
			if (author[i] != rhs.author[i])
			{
				return author[i] < rhs.author[i];
			}
		}
		if (author.size() != rhs.author.size())
		{
			return author.size() < rhs.author.size();
		}
		if (title != rhs.title)
		{
			return title < rhs.title;
		}
		return volume.size() < rhs.volume.size() || (volume.size() == rhs.volume.size() && volume < rhs.volume);
	}
};

string trim(string s)
{
	s.erase(0, s.find_first_not_of(" \n"));
	s.erase(s.find_last_not_of(" \n") + 1);
	return s;
}

vector<Reference> references;
Reference currentReference;

Name getName(string str)
{
	Name rnt;
	int pos = 0;
	int last = 0;
	while ((pos = str.find(" ", last)) != -1)
	{
		rnt.name.push_back(trim(str.substr(last, pos - last - 1)));
		last = pos + 1;
	}
	rnt.name.push_back(trim(str.substr(last)));
	return rnt;
}

bool readField()
{
	string field;
	cin >> field;
	field = trim(field);
	if (field[0] == '}')
	{
		return false;
	}
	string equal;
	cin >> equal;
	string value;
	getline(cin, value);
	value = trim(value.substr(2, value.size() - (value[value.size() - 1] == ',' ? 4 : 3)));
	if (field == "author")
	{
		int pos = 0;
		int last = 0;
		while ((pos = value.find("and", last)) != -1)
		{
			currentReference.author.push_back(getName(value.substr(last, pos - last - 1)));
			last = pos + 4;
		}
		currentReference.author.push_back(getName(value.substr(last)));
		sort(currentReference.author.begin(), currentReference.author.end());
	}
	else if (field == "title")
	{
		currentReference.title = value;
	}
	else if (field == "journal")
	{
		currentReference.journal = value;
	}
	else if (field == "publisher")
	{
		currentReference.publisher = value;
	}
	else if (field == "year")
	{
		currentReference.year = value;
	}
	else if (field == "volume")
	{
		currentReference.volume = value;
	}
	else if (field == "number")
	{
		currentReference.number = value;
	}
	else if (field == "pages")
	{
		currentReference.pages = value;
	}
	return true;
}

bool readReference()
{
	string type;
	if (!(cin >> type))
	{
		return false;
	}
	currentReference = Reference();
	currentReference.type = type.substr(1);
	string bracket;
	cin >> bracket;
	while (readField());
	references.push_back(currentReference);
	return true;
}

int main()
{
	freopen("bibtex.in", "r", stdin);
	freopen("bibtex.out", "w", stdout);
	while (readReference());
	sort(references.begin(), references.end());
	for (int i = 0; i < references.size(); ++i)
	{
		cout << "[" << i + 1 << "]";
		for (int j = 0; j < references[i].author.size(); ++j)
		{
			if (j)
			{
				cout << ",";
			}
			cout << " " << references[i].author[j].name.back();
			for (int k = 0; k < references[i].author[j].name.size() - 1; ++k)
			{
				cout << " " << references[i].author[j].name[k][0] << ".";
			}
		}
		cout << " " << references[i].title;
		if (references[i].type == "book")
		{
			if (!references[i].volume.empty())
			{
				cout << ", Vol. " << references[i].volume;
			}
			cout << " -- " << references[i].publisher << ", " << references[i].year << endl;
		}
		else
		{
			cout << " // " << references[i].journal;
			if (!references[i].volume.empty())
			{
				cout << ", " << references[i].volume;
			}
			if (!references[i].number.empty())
			{
				cout << " (" << references[i].number << ")";
			}
			cout << " -- " << references[i].year;
			if (!references[i].pages.empty())
			{
				if (references[i].pages.find("--") != -1)
				{
					cout << " -- pp. " << references[i].pages;
				}
				else
				{
					cout << " -- p. " << references[i].pages;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
