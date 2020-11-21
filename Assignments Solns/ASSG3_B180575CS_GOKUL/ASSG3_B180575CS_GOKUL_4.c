#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
	int data;
	struct Node* next;
};

typedef struct Node* node;

node createNode()
{
	node t=(node)malloc(sizeof(struct Node));
	if(t==NULL)
		{
			printf("Memory not allocated for node");
			exit(0);
		}
	t->next=NULL;
	return t;
}


void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = createNode();
    struct Node *last = *head_ref;
    new_node->data  = new_data; 

    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     
}


void Create(node* head,FILE* fp1)
{
	int data;char c;
	do{
	fscanf(fp1,"%d%c",&data,&c);
	append(head,data);
	}while(c!='\n');
}

void Print(node head,FILE* fp2)
{
	node p;
	p=head;
	while(p!=NULL)
	{
		fprintf(fp2,"%d ",p->data);
		p=p->next;
		if(p==NULL)
			fprintf(fp2,"\n");
		else
			fprintf(fp2," ");
	}

}

void swap_nodes(node n1, node n2)
{
	if(n2==NULL)
		return;
	int temp=n1->data;
	n1->data=n2->data;
	n2->data=temp;
}

void swap_pairwise(node head)
{
	node p1,p2;
	p1=head;
	p2=p1->next;
	while(p2!=NULL)
	{
		swap_nodes(p1,p2);
		p1=p2->next;
		p2=p2->next;
		p2=p2->next;
	}
}

int main()
{
	FILE* fp1;
	FILE* fp2;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	node head=NULL;
	char sel;
	int elem;
	while(1)
	{
		fscanf(fp1,"%c",&sel);
		if(sel=='c')
		{
			Create(&head,fp1);
		}
		else if(sel=='p')
		{
			Print(head,fp2);
		}
		else if(sel=='w')
		{
			swap_pairwise(head);
		}

		else if(sel=='s')
		{
			break;
		}
	}
}
