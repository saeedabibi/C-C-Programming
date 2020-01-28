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
  printf("Book Name: %s\n", ptr->title);
  printf("Book ID: %d\n", ptr->id);
}

struct Node* GetBook()
{
  static int bookid=1;
  struct Node *node=malloc(sizeof(struct Node));
  strcpy(node->data.title,"C++ hhjkh ijkj lkk ");
  node->data.id=bookid++;

  //printBook(ptr);
  //free(ptr);
  
  return node;
}

int main()
{

  struct Node *head=NULL;
  struct Node *curr=NULL;
  int count=0;

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
  for(int k=0;k<5;k++)
  {
    printBook(&(curr->data));
    curr=curr->nextNode;
  }

  curr=head;

  for(int i=0;i<count;i++)
  {
    head=curr->nextNode;
    free(curr);
    curr=head;
  }

  /*struct Book* ptr=malloc(sizeof(struct Book));
  strcpy(ptr->title,"C++ hhjkh ijkj lkk");
  ptr->id=4;

  printBook(ptr);
  free(ptr);*/
   
  return 0;
}
