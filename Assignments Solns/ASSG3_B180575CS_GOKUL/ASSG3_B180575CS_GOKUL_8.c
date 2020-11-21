#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node 
{ 
  int data; 
  struct Node *next; 
};

typedef struct Node * node; 

node createNode()
{
	node temp;
	temp=(node)malloc(sizeof(struct Node));
	temp->next=NULL;
	return temp;
}

void push(node *stk,int element)
{
	node new,p;
	new=createNode();
  new->data=element;
  if(*stk==NULL)
    { 
        new->next = NULL;  
        *stk=new;
    }
  else
  {
    new->next=*stk;
    *stk=new;
  }
}

int pop(node *stk)
{
  node p;
  int popped;
  if(*stk==NULL)
      return -1;
  popped=(*stk)->data;
  p=(*stk)->next;
  free(*stk);
  *stk=p;
  return popped;
}

int find_size(node head)
{
  node temp=head;
  int n=0;
  while(temp!=NULL)
  {
    n++;
    temp=temp->next;
  }
  return n;
}

void print(node stk,int n,FILE *fp2)
{
  node temp=stk;
  int count=0;
  node p=stk;
  if(stk==NULL)
    {
      fprintf(fp2,"-1\n");
      return;
    }
  int size=find_size(stk);
  if(n==0 || n>size)
  {
    while(temp!=NULL)
   {
    fprintf(fp2,"%d",temp->data);
    temp=temp->next;
    if(temp==NULL)
    {
      if(n>size)
        fprintf(fp2," END");
      fprintf(fp2,"\n");
    }
    else
      fprintf(fp2," ");
   }
   return;
  }
  if(n>0 && n<=size)
   {
    while(count<n)
    {
      fprintf(fp2,"%d",p->data);
      p=p->next;
      count++;
      if(count==n)
        fprintf(fp2,"\n");
      else 
        fprintf(fp2," ");
    }   
   }
}


int main(int argc,char *argv[])
{
	  char ch;
	  int element,p,n;
	  FILE *fp1;
    FILE *fp2;
    node head=NULL;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    if(fp1==NULL)
       	printf("Error opening file");
    else
        {
		while(1)
       	 {
			fscanf(fp1,"%c",&ch);
       		  if(ch=='p')
            {
              fscanf(fp1,"%d",&element);
              push(&head,element);   
            }
            else if(ch=='t')
             	 {
                p=pop(&head);
                fprintf(fp2,"%d\n",p);
               }
            else if(ch=='d')
            {
            	 fscanf(fp1,"%d",&n);
            	 print(head,n,fp2);
            }
            else if(ch=='s')
               	break;
           	}

         }
	   fclose(fp1);
   	fclose(fp2);
    return 0;
}