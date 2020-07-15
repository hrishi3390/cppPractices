/*
 * TwoWayBinaryTree.cpp
 *
 *  Created on: Jul 14, 2020
 *      Author: Hrishikesh.Chaudhari
 */

#include<iostream>
#include<stack>
#include<sstream>
#include<vector>

using namespace std;

void DirectoryPathInInUnix()
{
	vector<string> directory;
	string input {"/a/.."};
	stringstream ss(input);
	string token;
	stack<string> folders;

	while(getline(ss, token, '/'))
	{
		if(token != "")
			directory.push_back(token);
	}

	for(int i=0; i<(int)directory.size(); i++)
	{

		if(directory[i] == "..")
		{
			if(!folders.empty())
				folders.pop();
		}
		else if(directory[i] == ".")
		{
			//do nothings
		}
		else
			folders.push(directory[i]);

		//cout<<directory[i]<<"\t";
	}

	if(folders.empty())
	{
		cout<<"/"<<endl;
	}

	cout<<endl;
	string result;
	while(!folders.empty())
	{
		result += folders.top();
		folders.pop();
	}

	for(int i= result.size()-1 ; i>=0; i--)
	{
		cout<<"/"<<result[i];
	}

	cout<<endl;
}


