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
int find_end(node head)
{
	node p;
	int n=0;
	p=head;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}

void find_knode(node head, int k,FILE* fp2)
{
	int end=find_end(head);
	node p;
	p=head;
	int i=0;
	if(k>end)
	{
		fprintf(fp2, "%d\n", -1);
		return;
	}
	while(i<end-k)
	{
		p=p->next;
		i++;
	}
	fprintf(fp2, "%d\n", p->data);

}

int main()
{
	FILE* fp1;
	FILE* fp2;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	node head=NULL;
	char sel;
	int elem,k;
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
		else if(sel=='f')
		{
			fscanf(fp1,"%d",&k);
			find_knode(head, k,fp2);
		}
		else if(sel=='s')
		{
			break;
		}
	}
	fclose(fp1);
	fclose(fp2);
}

