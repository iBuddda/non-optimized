// pozor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	vector<string> blacklist;
	fstream black_list_file,Text,Output;
	black_list_file.open("Blacklist.txt");
	string word;
	while (!black_list_file.eof())
	{
			black_list_file >> word;
			if (!word.empty())
			blacklist.push_back(word);
	}
	black_list_file.close();
	for (int i = 0; i < blacklist.size();i++)
	{
			cout << blacklist[i] << "\n";
	}
	Text.open("Text.txt");
	Output.open("Result.txt", ios::out);
	
	word.clear();
		while (!Text.eof())
		{
			char symbol = Text.get();
			if (symbol >= 'A' && symbol <= 'Z' ||
				symbol >= 'a' && symbol <= 'z')
			{
				word += symbol;
			}
			else 
			{
				if (!word.empty())
				{ 
					bool in_blacklist = false;
					for (int i = 0; i < blacklist.size(); i++)
					{
						if (word == blacklist[i])
						{
							in_blacklist = true;
							break;
						}
					}
					if (!in_blacklist)
					{
						Output << word;
					}
					word.clear();
				}
				Output << symbol;
			}
		}
		
	Text.close();
	Output.close();
}

