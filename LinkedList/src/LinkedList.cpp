//============================================================================
// Name        : LinkedList.cpp
// Author      : Hrishikesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "list.h"
using namespace std;

int main() {

	list ll;
	ll.addNode(1);
	ll.addNode(2);
	ll.addNode(3);
	ll.addNode(4);
	ll.addNode(5);
	ll.addNode(6);

	ll.printLinkedList();
	ll.findMiddleElement();

	cout<<endl;
	ll.deleteNode(2);
	cout<<endl;

	ll.printLinkedList();
	ll.findMiddleElement();

	cout<<"Reversing List"<<endl;
	ll.reverseLinkList();
	ll.findMiddleElement();
	return 0;
}
