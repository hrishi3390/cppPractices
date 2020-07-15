/*
 * NoOFDays.cpp
 *
 *  Created on: Jul 12, 2020
 *      Author: Hrishikesh.Chaudhari
 */
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

struct Date
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

vector<int> normalYearMonths {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> leapYearMonths {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void populateStruct(struct Date &s , vector<string> words);
bool isLeapYear(int);
int noDaysInYear(int year);
int calDaysTillMonth(int month, int year, int gap);
int numberOfdaysBetweenYears(int , int);



void NumberOfDays(void)
{
	Date start,end;
	string start_date{"10/02/2014"};
	string end_date{"10/03/2015"};
	vector<string> tokens;

//	cout<<"Enter the start date in format (DD/MM/YYYY)"<<endl;
//	cin>>start_date;
//
//	cout<<"Enter the end data in format (DD/MM/YYYY)"<<endl;
//	cin>>end_date;


	stringstream sdate(start_date);
	stringstream edate(end_date);

	string word;

	while(getline(sdate, word, '/'))
	{
		tokens.push_back(word);
	}
	populateStruct(start, tokens);
	tokens.clear();

	while(getline(edate, word, '/'))
	{
		tokens.push_back(word);
	}
	populateStruct(end, tokens);
	tokens.clear();

	cout<<"Start Date Enter is: "<<start.day<<"/"<<start.month<<"/"<<start.year<<endl;
	cout<<"End Date Enter is: "<<end.day<<"/"<<end.month<<"/"<<end.year<<endl;

	int noOfDaysTillStartdate  = calDaysTillMonth(start.month, start.year, start.year) + start.day;
	//cout<<noOfDaysTillStartdate <<endl;

	int noOfDaysTillEndDate = calDaysTillMonth(end.month, start.year , end.year) + end.day;
	//cout<<noOfDaysTillEndDate<<endl;

	cout<<"NoOfDaysInBetween : "<<noOfDaysTillEndDate - noOfDaysTillStartdate<<endl;


}


void populateStruct(struct Date &s , vector<string> words)
{
	int i=0;
	do
	{
		stringstream ss1(words[i]);
		ss1 >> s.day;
		i++;

		stringstream ss2(words[i]);
		ss2 >> s.month;
		i++;

		stringstream ss3(words[i]);
		ss3 >> s.year;

	}while(false);

}

bool isLeapYear(int year)
{
	if(year % 400 == 0)
		return true;
	else if(year % 100 == 0)
		return false;
	else if(year % 4 == 0)
		return true;

	return false;
}

int noDaysInYear(int year)
{
	if(isLeapYear(year))
		return 366;
	else
		return 365;
}

int calDaysTillMonth(int month , int startYear, int endYear)
{
	int total_days = 0;
	total_days = numberOfdaysBetweenYears(startYear, endYear);

	vector<int> leap_or_normal = normalYearMonths;
	if(isLeapYear(endYear))
	{
		leap_or_normal = leapYearMonths;
	}
	for(int i=0; i<month-1; i++)
	{
		total_days += leap_or_normal[i];
	}

	return total_days;
}

int numberOfdaysBetweenYears(int startYear, int endYear)
{
	int days = 0;
	for(int i = startYear; i<endYear; i++ )
	{
		days += noDaysInYear(i);
	}

	return days;
}

