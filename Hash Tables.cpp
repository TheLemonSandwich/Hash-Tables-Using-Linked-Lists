//								HASH TABLE USING LINKED LISTS
#include <iostream>
#include <string>

using namespace std;

struct node
{
	string name;
	int reg;
	node* next;
};

class Hashing
{
public:
	Hashing();
	void search(int);
private:
	bool Append();
	string name;
	int reg, index;
	node* hashtable[30];
};
int main()
{
	cout << "\t\t\t\t\tStudent's Data Management System\n";
	cout << "Entering Student Details\nLeave the name place void to Stop Appending\n";
	Hashing h;
	int reg;
	do
	{
		cout << "Who do you want to search?";
		cin >> reg;
		h.search(reg);
	} while (true);
	

}
void Hashing::search(int reg)
{
	index = reg % 30;
	while (true)
	{
		if (hashtable[index]->reg == reg)
		{
			cout << "Name:\t" << hashtable[index]->name << endl;
			cout << "Reg:\t" << reg << endl;
			break;
		}
		else if (hashtable[index]->next == NULL)
		{
			cout << "Reg Not Found\n";
			break;
		}
		else hashtable[index] = hashtable[index]->next;
	}
}
Hashing::Hashing()
{
	for (int i = 0; i < 30; i++)
	{
		hashtable[i] = new node;
		hashtable[i]->next = NULL;
	}
	while (Append());
	
}
bool Hashing::Append()
{
		cout << "Name:\t";
		getline(cin, name);
		if (name == "")
			return false;
		cout << "Reg:\t";
		cin >> reg;
	index = reg % 30;
	cout << "Index: " << index << endl;
	while (true)
	{
		if (hashtable[index]->next == NULL)
		{
			hashtable[index]->name = name;
			hashtable[index]->reg = reg;
			break;
		}
		else hashtable[index] = hashtable[index]->next;
	}
	cin.ignore();
	return true;
}