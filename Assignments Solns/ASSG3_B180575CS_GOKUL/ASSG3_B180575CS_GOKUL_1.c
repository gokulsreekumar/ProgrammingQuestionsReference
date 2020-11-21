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

void Print(node head1,FILE* fp2)
{
	node p;
	p=head1;
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

int middle(node head)
{
	int m;
	node p;
	p=head;
	double n=0;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	m=ceil(n/2)+1;
	return m;
}

void insert_middle(node head,int new_elem)
{
	int i=0;
	node p,new_node;
	p=head;
	int mid_pos=middle(head);
	new_node=createNode();
	new_node->data=new_elem;

	while(i<mid_pos-2)
	{
		p=p->next;
		i++;
	}
	new_node->next=p->next;
	p->next=new_node;
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
		else if(sel=='i')
		{
			fscanf(fp1,"%d",&elem);
			insert_middle(head,elem);
		}
		else if(sel=='s')
		{
			break;
		}
	}
}
