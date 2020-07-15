/*
 * ReverseKNodes.cpp
 *
 *  Created on: Jul 14, 2020
 *      Author: Hrishikesh.Chaudhari
 */
#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

//func decl
Node *createLinkedList(Node *head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL)
	{
		return newNode;
	}

	Node *itr = head;

	while(itr->next)
	{
		itr = itr->next;
	}
	itr->next = newNode;

	return head;
}

void printLinkList(Node *head)
{
	while(head)
	{
		cout<<head->data<<"\t";
		head = head->next;
	}
}

Node* reverseList(Node *head, int k)
{
	Node *curr=NULL, *prev = NULL, *next = NULL;
	curr = head;
	int count = k;

	while(curr && count)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count--;
	}

	if(head)
		head->next =  reverseList(curr, k);

	return prev;

}

void ReverseKNodes(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9};

	Node *head = NULL;

	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<size; i++)
	{
		head = createLinkedList(head, arr[i]);
	}

	printLinkList(head);
	cout<<endl;
	int k = 3;

	head = reverseList(head, k);
	printLinkList(head);
	cout<<endl;
}
