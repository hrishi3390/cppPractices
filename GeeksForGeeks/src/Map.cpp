/*
 * Map.cpp
 *
 *  Created on: Jul 14, 2020
 *      Author: Hrishikesh.Chaudhari
 */

#include<iostream>
#include <map>

using namespace std;

void findMap()
{
	map<string , int> stringMap;
	stringMap.insert(make_pair<string, int>("Hrishikesh", 1));
	stringMap.insert(make_pair<string, int>("Hrishi", 1));
	stringMap.insert(make_pair<string, int>("Hri", 1));
	stringMap.insert(make_pair<string, int>("Hriesh", 1));
	stringMap.insert(make_pair<string, int>("ishikesh", 1));


	map<string, int>::iterator itr = stringMap.find("Hri3shi");

	if(itr!=stringMap.end())
	{
		cout<<itr->first<<" : "<<itr->second<<endl;
	}
	else
		cout<<"Key not found"<<endl;



}
