//
//
//Song Lyric assignment
//
//by 
//Jeffrey Darmawan
//2001585474
//Wilson Fransicius
//2001505303
//Dylan
//2001585530
//
//Featured song: Wiz Khalifa - Black n Yellow


#include<iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct wordData{ //for original words and word length
	string sWordName;
	int nWordLength; 
};

struct newWordData{ //for modified words and word count
	string sWord;
	int nAmount;
};

int numberOfWords = 0;
int diffWords = 0;

wordData arrayData[999]; //original 
newWordData final[999];	//final = after removing duplicates and sorting

void addLyricsArray(string word);
void filter();
void convertLower();
void countAndRemove();
void sort();
void output();


int main()
{
	ifstream inputFile;
	inputFile.open("Lyrics.txt");
	
	string word;
	while (inputFile >> word)
	{
		addLyricsArray(word);
	}
	
	inputFile.close();
	filter();
	convertLower();
	
	cout << "==============================" << endl;
	
	countAndRemove(); 
	sort();
	output();

	return 0;
}

void addLyricsArray (string word)
{
	wordData newWords;
	newWords.sWordName = word;
	newWords.nWordLength = word.length();
	
	arrayData[numberOfWords] = newWords;
	
	numberOfWords++;
}

void filter()
{
	//clear punctuation
	for (int i = 0; i<numberOfWords; i++)
	{
		string checking = arrayData[i].sWordName;
		int x = arrayData[i].nWordLength;
		for (int j = 0; j < x; j++)	
		{
			if (ispunct(checking[j]))
			{
				checking.erase(j,1); 
			}
		}
		arrayData[i].sWordName=checking;
	}	
}

void convertLower()
{
	
	for (int i = 0; i<numberOfWords; i++)
	{
		string checking = arrayData[i].sWordName;
		int x = arrayData[i].nWordLength;
		for (int j = 0; j < x; j++) 
		{
			if (isupper(checking[j]))
			{
				checking[j] = tolower(checking[j]);
			}
		}
	 	arrayData[i].sWordName=checking;
	}
	
}

void countAndRemove()
{
	int x=0;
	for (int i = 0; i<numberOfWords; i++)
	{
		string checking = arrayData[i].sWordName;
		int counter = 0;
		
		//ignore blankspaces, actually only to stop adding final[i] and diffWords if there are no more words 
		//(because the loop continues based on numberOfWords)
		
		if(checking != "" && checking != " ")
		{
			for(int j = 0; j<numberOfWords; j++) 
			{
				if(arrayData[j].sWordName == checking )
				{
					arrayData[j].sWordName= ""; //remove duplicate
					counter++; //count same words
				}
			}
			final[x].sWord = checking;
			final[x].nAmount = counter;
		
			diffWords++;
			x++;
		}	
	}
}

void sort()
{
	newWordData temp; 
	for(int i=0;i<diffWords;i++) //sort numbers
    {
    	for(int j=0;j<diffWords-1;j++)
        {	
        	if (final[j].nAmount < final[j + 1].nAmount)
			{
				temp = final[j];
				final[j] = final[j + 1];
				final[j + 1] = temp;
			}
		}
    }
}


void output()
{	
	for(int i = 0; i < diffWords; i++) //display top 10 words
	{
		//ignore words bellow 5 character and ignore words with frequency bellow 3 
		//actually better to do this work before importing the lyric
		if(final[i].sWord.length() < 5 || final[i].nAmount < 3) 
		{
		}
		else
		{
			cout << final[i].sWord << "   "; 
		
			if(final[i].sWord.length() > 4)
			{
				cout << "\t";	
			}
			else
				cout << "\t\t";
			
			for(int j = 0; j < final[i].nAmount; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
}
