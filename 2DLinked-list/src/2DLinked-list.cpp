#include<iostream>
#include<math.h>

using namespace std;

struct Node
{
	int data;
	Node* right, *down;

	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};

void linkedDownList(Node *iarray[], int n)
{
    for(int i = 0; i< n-1; i++)
    {
        Node *iterator1 = iarray[i];
        Node *iterator2 = iarray[i+1];

        while(iterator1 && iterator2)
        {
            iterator1->down = iterator2;
            iterator1 = iterator1->right;
            iterator2 = iterator2->right;
        }
    }
}
Node *createLinkedList(Node *head, int n)
{

    Node *temp = new Node(n);
    Node *iterator = NULL;

    if(head == nullptr)
    {
        head = temp;
        return temp;
    }
    iterator = head;

    while(iterator->right != NULL)
    {
    	iterator = iterator->right;
    }

    iterator->right = temp;

    return head;
}

#define MAX 3
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node *iNodeArray[n];

   for(int i = 0; i<n ; i++)
   {
	   Node* head = nullptr;
	   for(int j = 0; j<n ; j++)
	   {
		   int data = mat[i][j];
		   head =  createLinkedList(head, data);
	   }

	   iNodeArray[i] = head;
   }

   	   linkedDownList(iNodeArray,n);


   return iNodeArray[0];
}

int main(void)
{
//	int a[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
//
//	Node *head = constructLinkedMatrix(a, 3);
//
//	cout<< head->right->down->data;

	for(int i =0, j= 0; i<=2, j<=5;i++,j++)
		cout<<"I and J are "<<i<<" "<<j<<endl;



	//cout<<sizeof(a)/sizeof(a[0]);

}
