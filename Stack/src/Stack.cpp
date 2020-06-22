//============================================================================
// Name        : Stack.cpp
// Author      : Hrishikesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

//Today we are going to implement the Stack data structure
/*
 *
 * This data structure will have mainly following functions
 * 1) push
 * 2) pop
 */

struct Node {
	int data;
	Node *next;
};

typedef Node Node;

Node *top = nullptr;
int main() {

	//prototypes
	void push(int);
	int pop();
	void printStack();

	int stack[] = {1,2,3,4,5,6,7};

	for(int i=0;i<(int)(sizeof(stack)/sizeof(stack[0])); i++)
		push(stack[i]);

	printStack();

	pop();
	printStack();

	pop();
	pop();
	printStack();

	pop();
    pop();
    printStack();
	pop();
	pop();
	printStack();
	pop();
	if(pop())
	{
		cout<<"Stack is empty"<<endl;
	}

	printStack();
	return 0;
}

Node *createNode(int number)
{
	Node *temp = nullptr;
	temp = (Node *)malloc(sizeof(Node));
	if(!temp)
		return nullptr;

	temp->data = number;
	temp->next = nullptr;

	return temp;
}

void push(int number)
{
	Node *newNode = nullptr;
	newNode = createNode(number);

	if(top == nullptr)
	{
		top = newNode;
		return;
	}

	newNode->next = top;
	top = newNode;

	return;
}

void printStack()
{
	Node *itr = nullptr;

	itr = top;

	while(itr != nullptr)
	{
		cout<<itr->data<<"\t";
		itr= itr->next;
	}

	cout<<endl;

}

bool isEmpty()
{
	if(top ==nullptr)
		return true;

	return false;
}

int pop()
{
	if(isEmpty())
	{
		return -1;
	}

	Node *temp = nullptr;

	temp = top;
	top = temp->next;
	temp->next = nullptr;
	free(temp);

	return 0;

}
