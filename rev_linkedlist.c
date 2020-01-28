#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int count=0;
struct Book
{
	char title[50];
	int id;
};

struct Node{
	struct Book data;
	struct Node *nextNode;
};

void printBook(struct Book *ptr)
{
	printf("Book Name:%s\n", ptr->title);
    printf("Book ID:%d\n", ptr->id);
}

struct Node* GetBook()
{
	static int bookid=0;
    struct Node *node=malloc(sizeof(struct Node));	
	strcpy(node->data.title,"C++ Programming Guide");
	node->data.id=bookid++;
	return node;
}

void PrintLinkedList(struct Node *head)
{
	struct Node *curr=NULL;
	
	curr=head;
	for(int i=0;i<count;i++)
	{
		printBook(&(curr->data));
		curr=curr->nextNode;
	}
}
void FreeMem(struct Node *head)
{
	struct Node *curr=NULL;
	curr=head;
	for(int k=0;k<count;k++)
	{
		head=curr->nextNode;
		free(curr);
		curr=head;
	}
}

void Reverse(struct Node *head)
{
	struct Node *curr=NULL;
	struct Node *next=NULL;
	struct Node *prev=NULL;
	
	curr=head;
	prev=head;
	while(curr!=NULL)
	{
		next=curr->nextNode;
		curr->nextNode=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
	
	PrintLinkedList(head);
		
	FreeMem(head);
}



int main()
{
	struct Node *head=NULL;
	struct Node *curr=NULL;
	
	
	curr=GetBook();
	curr->nextNode=NULL;
	count++;
	head=curr;
	
	for(int j=0;j<5;j++)
	{
		curr->nextNode=GetBook();
		count++;
		curr=curr->nextNode;
	}
	curr->nextNode=NULL;
	
	
	PrintLinkedList(head);
	
	Reverse(head);
	
	FreeMem(head);
	
}