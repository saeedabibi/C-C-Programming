#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

//function for New Node 
struct Node* NewNode()
{
    struct Node *node=malloc(sizeof(struct Node));	
	strcpy(node->data.title,"New Node");
	node->data.id=20;
	return node;
}

int main()
{
	struct Node *head=NULL;
	struct Node *curr=NULL;
	struct Node *insertedNode=NULL;
	int count=0,n;
	
	curr=GetBook();
	count++;
	head=curr;
	
	for(int j=0;j<5;j++)
	{
		curr->nextNode=GetBook();
		count++;
		curr=curr->nextNode;
	}
	
	curr=head;
	for(int i=0;i<count;i++)
	{
		printBook(&(curr->data));
		curr=curr->nextNode;
	}
	
	//Assigning value to New Node
	insertedNode=NewNode();
	//Print New Node value
	printBook(&(insertedNode->data));
	
	//Getting Id from user, after which node will be added
	printf("Enter id where you want to insert the Node \n");
	scanf("%d",&n);
	
	int cnt=count;
	curr=head;
	
	//Adding Node in the list
	for(int k=0;k<cnt;k++)
	{
		if(k==n)
		{
			insertedNode->nextNode=curr->nextNode;
			curr->nextNode=insertedNode;
			curr=insertedNode;
			count++;
		}
		curr=curr->nextNode;
	}
	//////////////////////////////////////////////////////////////////////
	
	curr=head;
	for(int i=0;i<count;i++)
	{
		printBook(&(curr->data));
		curr=curr->nextNode;
	}
	
	curr=head;
	for(int k=0;k<count;k++)
	{
		head=curr->nextNode;
		free(curr);
		curr=head;
	}
}