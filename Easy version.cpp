#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;

struct wordData
{
	string sWordName;
	int nWordLength; 
};

struct newWordData{
	string sWord;
	int nAmount;
};

wordData iniVariable[999];

int main()
{
	ifstream inputFile;
	inputFile.open("Lyrics.txt");
	int i = 0;
	string word;
	
	//maaf loopnya berantakan
	while (inputFile >> word)
	{
		int x = word.length();
		for (int j = 0; j < x; j++) 
		{
			if (isupper(word[j])) //dari katanya, di search per huruf
			{
				word[j] = tolower(word[j]); //convert UPPER to lower
			}
			if (ispunct(word[j])) //is it punctuation??
			{
				word.erase(j,1); //nemu di internet buat apus 1 char di string erase(<posisi>, <brp banyak>)
				//bisa aja tanpa pake erase, tp panjang lagi (buatan hansvin)
			}
			
		}
		iniVariable[i].sWordName = word;
		iniVariable[i].nWordLength = x; //ga perlu sih kayanya
		i++; //counter banyaknya kata	
	}
	//coba aja cout i
	
	inputFile.close();
	
	string userInput;
	cout << "Search word: "; cin >> userInput;
	
	for(int x = 0; x < userInput.length(); x++)
	{
		if (isupper(userInput[x]))
			{
				userInput[x] = tolower(userInput[x]); //convert UPPER to lower
			}
	}
	
	int counter = 0; //itung jumlah kata yg dicari
	
	for(int p = 0; p < i; p++) //i tadi jumlah words kann
	{
		if(iniVariable[p].sWordName == userInput)
		{
			counter++;
		}
	}
	
	cout << "Search result: " << userInput << "  ";
		for(int j = 0; j < counter; j++)
			{
				cout << "*";
			}
	
	return 0;
}
