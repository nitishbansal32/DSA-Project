#include<iostream>
#include<list>
#include<string> //to define getline()
#define MAX_CHAR 256
using namespace std;


class SuffixTrieNode
{
private:
	SuffixTrieNode *children[MAX_CHAR];
	list<int> *indexes;
public:
	SuffixTrieNode() // Constructor
	{
		// Create an empty linked list for indexes of
		// suffixes starting from this node
		indexes = new list<int>;

		// Initialize all child pointers as NULL
		for (int i = 0; i < MAX_CHAR; i++)
		children[i] = NULL;
	}

	/* A recursive function to insert a suffix of the txt
	in subtree rooted with this node*/
	void insertSuffix(string suffix, int index);//overloaded function

	/* A function to search a pattern in subtree rooted
	 with this node.*/
	list<int>* search(string pat);//overloaded function
};

//Suffiex Trie
class SuffixTrie
{
private:
	SuffixTrieNode root;
public:
	// Constructor (Builds a trie of suffies of the given text)
	SuffixTrie(string txt)
	{
		/*Using recurssive function insertSuffix() we add 
		the suffixes to SuffixTrienode*/
		for (int i = 0; i < txt.length(); i++)
			root.insertSuffix(txt.substr(i), i);
	}

	// Function to searches a pattern in this suffix trie.
	void search(string pat);//overloaded fucntion
	

};

int main()
{
	
	string txt; //define txt as string
	cout<<"Enter the String : "; 
	getline(cin, txt); //taking the user input of the main string 
	SuffixTrie S(txt); //now the string is fed to the function
    
	//Sub string inputs
	string sub1;
	cout << "Enter sub string 1" << endl;
	getline(cin, sub1); 
	S.search(sub1);

	
	string sub2;
	cout << "Enter sub string 2" << endl;
	getline(cin, sub2);
	S.search(sub2);

	string sub3;
	cout << "Enter sub string 3" << endl;
	getline(cin, sub3);
	S.search(sub3);

	string sub4;
	cout << "Enter sub string 4" << endl;
	getline(cin, sub4);
	S.search(sub4);

	return 0;
}

// A recursive function to insert a suffix of the txt 
void SuffixTrieNode::insertSuffix(string s, int index)
{
	// Store index in linked list
	indexes->push_back(index);

	// If string has characters > 0
		if (s.length() > 0)
	{
		// First Character
		char cIndex = s.at(0);

		// No edge, then add new edge
		if (children[cIndex] == NULL)
			children[cIndex] = new SuffixTrieNode();

		//Recurssion continues
		children[cIndex]->insertSuffix(s.substr(1), index+1);
	}
}

// A recursive function to search a pattern in subtree 
list<int>* SuffixTrieNode::search(string s)
{
	// if no characters left
	if (s.length() == 0)
		return indexes;

	//follow the edge, if there is one
	if (children[s.at(0)] != NULL)
		return (children[s.at(0)])->search(s.substr(1));

	// No patter if there is no
	else return NULL;
}

//for text - print all occurences of pat in Suffix trie S
void SuffixTrie::search(string pat)
{
	// We call the recurssive function and gives us the index where pat occurs
	list<int> *result = root.search(pat);

	// Check if the list of indexes is empty or not
	if (result == NULL)
		cout << "Pattern not found" << endl;
	else
	{
	list<int>::iterator i;
	int patLen = pat.length();
	for (i = result->begin(); i != result->end(); ++i)
		cout << "Pattern found at position " << *i - patLen<< endl;
	}
}
