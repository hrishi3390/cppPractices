/*
 * list.h
 *
 *  Created on: Jun 14, 2020
 *      Author: Hrishikesh.Chaudhari
 */

#ifndef LIST_H_
#define LIST_H_


struct Node {
	int data;
	Node *next;
};

class list {
private:
	Node* head;

public:
	list(int);
	list();
	void addNode(int a);
	void printLinkedList();
	void deleteNode(int a);
	bool isEmpty();
	void findMiddleElement();
	void reverseLinkList();
	void insertNode(int, int);

	virtual ~list();
};

#endif /* LIST_H_ */
