/*
 * DeleteDuplicateLineFromFile.cpp
 *
 *  Created on: Jul 14, 2020
 *      Author: Hrishikesh.Chaudhari
 */


#include<iostream>
#include<fstream>
#include<map>
#include<sstream>

using namespace std;

void DeleteDuplicateLineFromFile()
{
	fstream myFile("C:\\Users\\hrishikesh.chaudhari\\eclipse-workspace1\\GeeksForGeeks\\src\\file.txt", ios::in);
	fstream outFile("C:\\Users\\hrishikesh.chaudhari\\eclipse-workspace1\\GeeksForGeeks\\src\\out.txt", ios::out);

	map<string, int> lineMap;
	string line;


	if(myFile.is_open())
	{
		while(getline(myFile, line))
		{
			cout<<line<<endl;
			lineMap[line]++;
			if(lineMap[line] == 1)
			{
				outFile.write(line.c_str(), line.length());
				outFile.put('\n');
			}

		}
	}
	else
	{
		cout<<"Cannot open a file"<<endl;
	}

	myFile.close();
	outFile.close();


}

