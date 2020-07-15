/*
 * findKFrequenceWords.cpp
 *
 *  Created on: Jul 12, 2020
 *      Author: Hrishikesh.Chaudhari
 */


#include<iostream>
#include<sstream>
#include<fstream>
#include<map>

using namespace std;

struct Frequency
{
	string word;
	int freq;
};

struct Tree
{
	Frequency fr;
	Tree *left;
	Tree *right;
};

Tree* createBinarySearchTree(Frequency[], int);
void findFirstKFrequectWords(Tree *, int);


void KFrequenceWords(void)
{
	ifstream myfile("C:\\Users\\hrishikesh.chaudhari\\eclipse-workspace1\\GeeksForGeeks\\src\\file.txt");
	string line;
	string word;
	map<string, int> wordMap;


	if(myfile.is_open())
	{
		while(getline(myfile, line))
			{
				stringstream ss(line);
				while(getline(ss, word, ' '))
					{
						wordMap[word]++;
					}
			}
	}
	else
	{
		cout<<"File not found"<<endl;
	}

	map<string, int>::iterator itr = wordMap.begin();
	int total_words = wordMap.size();
	Frequency wordWithFreq[total_words];


	for(int i=0; i<total_words; i++)
	{
		wordWithFreq[i].word = itr->first;
		wordWithFreq[i].freq = itr->second;
		itr++;
	}

	Tree *root = createBinarySearchTree(wordWithFreq, total_words);
	int k =3;
	findFirstKFrequectWords(root, k);

}
int count = 4;

void findFirstKFrequectWords(Tree *root, int k)
{

		if(root == NULL)
		{
			return ;
		}
		findFirstKFrequectWords(root->left, k);

		if(count)
		{
			cout<<root->fr.word<<" with frequency "<<root->fr.freq<<endl;
			count--;
		}

		findFirstKFrequectWords(root->right, k);
}
Tree *createNode(Frequency fr)
{
	Tree *newNode = new Tree;
	newNode->fr = fr;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
Tree *createBST(Tree *root, Frequency fr)
{
	if(root==NULL)
	{
		root = createNode(fr);
		return root;
	}

	if(root->fr.freq < fr.freq)
	{
		root->left = createBST(root->left, fr);
	}
	else
	{
		root->right = createBST(root->right, fr);
	}

	return root;
}

Tree *createBinarySearchTree(Frequency fr[], int size)
{
	Tree *root = NULL;

	for(int i=0; i<size ; i++)
	{
		root = createBST(root, fr[i]);
	}

	return root;
}
