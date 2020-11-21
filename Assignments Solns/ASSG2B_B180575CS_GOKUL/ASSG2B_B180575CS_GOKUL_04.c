#include<stdio.h>
#include<stdlib.h>
FILE* F1;
FILE* F2;
void read(char A[],int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                fscanf(F1,"%c",&A[i]);
                if(A[i]==' '||A[i]=='\n'||A[i]=='\t'||A[i]=='\f'||A[i]=='\r')
                i--;
        }
}

void display(char A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        fprintf(F2,"%c ",A[i]);
    }
    fprintf(F2,"\n");
}

int LEFT(int i)
{
    return 2*i+1;
}
int RIGHT(int i)
{
    return 2*i+2;
}
void Max_Heapify(char A[], int n, int i)
{
    int l, r;
    l=LEFT(i);
    r=RIGHT(i);

    int largest;
    if (l<n && A[l]>A[i])
    {
        largest=l;

    }
    else
        largest=i;
    if(r<n && A[r]>A[largest])
        largest=r;

    if(largest!=i)
    {
        char temp1=A[i];
        A[i]=A[largest];
        A[largest]=temp1;
        Max_Heapify(A, n, largest);
    }
}

void Build_Heap(char A[], int n)
{
    int i;
    int last=n-1;
    for(i=(last/2);i>=0;i--)
    {
        Max_Heapify(A, n, i);
    }
}

void heapSort(char A[],int n)
{
    int i;
    int size=n;
    Build_Heap(A, n);
    for(i=n-1;i>=1;i--)
    {
        char temp1 = A[0];
        A[0]=A[n-1];
        A[n-1]=temp1;
        n=n-1;
        Max_Heapify(A,n,0);

    }
    display(A,size);
}

int main(int argc, char* argv[])
{
    F1 = fopen(argv[1],"r");
    F2 = fopen(argv[2],"w");
    char s;
    int num;
    int size;
    char* A;
    while(1)
    {
        fscanf(F1,"%c",&s);
        if(s=='r')
        {
            fscanf(F1,"%d", &num);
            size=num;
            A=(char*)malloc((sizeof(char))*num);
            read(A,num);
        }
        else if(s=='s')
        {
           heapSort(A,size);
        }
        else if(s=='d')
        {
            fscanf(F1,"%d", &num);
            display(A,num);
        }
        else if(s=='t')
            break;
    }
}



