#include<stdio.h>
#include<stdlib.h>


struct Node { 
    int data; 
    struct Node* next; 
    struct Node* prev; 
}; 
  
typedef struct Node* node;
 
node createNode()
{
    node temp;
    temp=(node)malloc(sizeof(struct Node));
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void deleteNode(struct Node** head_ref, struct Node* del) 
{ 
    // base case 
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    // If node to be deleted is head node 
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    // Change next only if node to be deleted 
    // is NOT the last node 
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    // Change prev only if node to be deleted 
    // is NOT the first node 
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    // Finally, free the memory occupied by del 
    free(del); 
} 

void append(struct Node** head_ref, int new_data)  
{  

    node new_node = createNode();
    node last = *head_ref; 
    new_node->data = new_data;    
    if (*head_ref == NULL) 
    {  
        new_node->prev = NULL;  
        *head_ref = new_node;  
        return;  
    }  
    while (last->next != NULL)  
        last = last->next;  
    last->next = new_node;  
    new_node->prev = last;  
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


void remove_duplicate(node* head_ref) 
{ 

    if ((*head_ref) == NULL || (*head_ref)->next == NULL) 
        return; 
    struct Node* ptr1, *ptr2;  
    for (ptr1 = *head_ref; ptr1 != NULL; ptr1 = ptr1->next) { 
        ptr2 = ptr1->next; 
        while (ptr2 != NULL) {  
            if (ptr1->data == ptr2->data) {  
                struct Node* next = ptr2->next; 
                deleteNode(head_ref, ptr2); 
                ptr2 = next; 
            }  
            else
                ptr2 = ptr2->next; 
        } 
    } 
} 
  
void print(node head1,FILE* fp2)
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
            print(head,fp2);
        }
        else if(sel=='r')
        {
            remove_duplicate(&head);
            
        }
        else if(sel=='s')
        {
            break;
        }
    }
    fclose(fp1);
    fclose(fp2);
}

