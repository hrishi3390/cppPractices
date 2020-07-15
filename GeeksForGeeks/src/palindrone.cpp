/*
 * palindrone.cpp
 *
 *  Created on: Jul 15, 2020
 *      Author: Hrishikesh.Chaudhari
 */

#include<iostream>


using namespace std;

bool checkAlphanumaric(char c)
{
	if( c >= 'a' && c <= 'z')
		return true;
	if( c >= '0' && c <= '9')
		return true;
	if( c >= 'A' && c <= 'Z')
		return true;

	return false;
}

void palindrone(void)
{
	string input = "A man, a plan, a canal: Panama";

	int length = input.length();

	int start = 0;
	int end = length -1;
	while(start < end)
	{
		while(!checkAlphanumaric(input[start]))
			start++;

		while(!checkAlphanumaric(input[end]))
			end--;

		if(tolower(input[start]) == tolower(input[end]))
		{
			start++;
			end--;
		}
		else
		{
			cout<<"Input is not a palindrom"<<endl;
			return;
		}
	}

		cout<<"Input is pallindrom"<<endl;

	return;
}

