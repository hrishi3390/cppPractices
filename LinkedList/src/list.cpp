/*
 * list.cpp
 *
 *  Created on: Jun 14, 2020
 *      Author: Hrishikesh.Chaudhari
 */

#include "list.h"
#include <iostream>

using namespace std;

list::list() {
	// TODO Auto-generated constructor stub
		head = nullptr;

}

list::~list() {
	// TODO Auto-generated destructor stub

	while(head)
	{
		Node *tmp =head;
		head = head->next;
		cout<<"Deleting a Node: "<<tmp->data<<endl;
		delete(tmp);
	}

}


void list::addNode(int a)
{
	Node *newNode = new Node;
	newNode->data = a;
	newNode->next = nullptr;

	if (isEmpty())
	{
		head = newNode;
		return;
	}

	Node* itr = head;
	while (itr->next != nullptr)
	{
		itr = itr->next;
	}

	itr->next = newNode;

	return;
}

void list::printLinkedList()
{
	Node* itr = head;

	while (itr->next != nullptr)
	{
		cout << itr->data << "====>";
		itr = itr->next;
	}

	cout<<itr->data<<endl;

	return;
}

void list::deleteNode(int a)
{

	cout<<"Deleting a Node: "<<a<<endl;
	if(head == nullptr)
	{
		cout<<"List is Empty"<<endl;
		return;
	}


	Node *curr = head;
	Node *prev = nullptr;

	// if Head is to be deleted
	if(curr->data == a)
	{
		head = curr->next;
		delete(curr);
		return;
	}

	prev = curr;
	curr = curr->next;

	while( curr != nullptr)
	{
		if(curr->data == a)
		{
			prev->next = curr->next;
			delete(curr);
			return;
		}
		else{
			prev = curr;
			curr = curr->next;
		}

	}

	cout<<"Cannot find "<<a<<" in linked list"<<endl;
}

bool list::isEmpty()
{
	if(head == nullptr)
	{
		return true;
	}

	return false;
}

void list::findMiddleElement()
{
	Node *curr = head;
	Node *next = head->next->next;

	while( next != nullptr)
	{
		curr= curr->next;
		if(next->next)
		{
			next = next->next->next;
		}
		else{
			break;
		}
	}
	cout<<"Middle Element of List is: "<<curr->data<<endl;
}

void list :: reverseLinkList()
{
	Node * curr = head;
	Node *next = nullptr;
	Node *prev = nullptr;

	if(isEmpty())
	{
		cout<<"Linked-List is empty"<<endl;
		return;
	}


	while(curr != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;

	printLinkedList();
}
