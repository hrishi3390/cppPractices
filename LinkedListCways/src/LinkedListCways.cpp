//============================================================================
// Name        : LinkedListCways.cpp
// Author      : Hrishikesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

typedef struct Node Node;

Node *head = nullptr;
Node *tail = nullptr;

int main() {

	void createList(int [], int);
	void displayList();
	int insertNode(int, int);
	int deleteNode(int);
	int search(int key);

	int values[] = {1,2,3,4,5,6,7,8,9};

	createList(values, 9);
	displayList();
	cout<<endl;

	cout<<"Inserting 10 at position 1"<<endl;
	insertNode(1,10);
	displayList();

	cout<<endl<<endl;

	cout<<"Inserting 4 at position 3"<<endl;
	insertNode(3,4);
	displayList();

	cout<<endl<<endl;

	cout<<"deleting head at 1"<<endl;
	deleteNode(1);
	displayList();

	cout<<endl<<endl;

	cout<<"deleting node at 2"<<endl;
	deleteNode(2);
	displayList();

	cout<<endl<<endl;

	cout<<"deleting head at 1"<<endl;
	deleteNode(1);
	displayList();

	cout<<endl<<endl;

	cout<<"Head: "<<head->data<<endl;
	cout<<"Tail:"<<tail->data <<endl;

	if(!search(6))
	{
		cout<<"Element found"<<endl;
	}
	else
		cout<<"Element does not found"<<endl;


	return 0;
}



void createList(int values [], int size)
{
	Node *createNode(int);

	for(int i=0; i<size ;i++)
	{
		Node *newNode = createNode(values[i]);
		if(head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

}

Node *createNode(int value)
{
	Node *temp = nullptr;
	temp = (Node*)malloc(sizeof (Node));

	temp->data = value;
	temp->next = nullptr;

	return temp;

}

void displayList()
{
	Node *itr = head;

	while(itr != nullptr)
	{
		cout<<itr->data<<"\t";
		itr = itr->next;
	}
}

int insertNode(int position, int value)
{
	Node *itr = head;
	Node *newNode = createNode(value);

	//position is head
	if(position == 1)
	{
		newNode->next = head;
		head = newNode;
		return 0;
	}

	//position can be anywhere middle and tail
	for(int i=1 ;i<position-1; i++)
	{

		itr = itr->next;
		if(itr == nullptr)
		{
			free(newNode);
			return -1;
		}

	}

	newNode->next = itr->next;
	itr->next = newNode;

	//just check if newnode of next is nullptr .. then appoint it as tail of linklist
	if(newNode->next ==nullptr)
		tail = newNode;

	return 0;
}

int deleteNode(int position)
{
	Node *temp = nullptr;
	Node *itr = head;

	if(head == nullptr)
		return 1;

	if(position == 1)
	{
		temp = head;
		head = temp->next;

		if(!head)
			tail = head;

		delete(temp);
		return 0;
	}

	for(int i =1; i<position-1; i++)
	{
		itr = itr->next;

		if(itr == nullptr)
			return 1;
	}

	temp = itr->next;
	itr->next = temp->next;
	delete(temp);

	if(itr->next ==nullptr)
		tail = itr;

	return 0;

}

int search(int key)
{
	Node *itr = head;

	while(itr!=nullptr)
	{
		if(itr->data == key)
			return 0;

		itr = itr->next;
	}

	return -1;
}
