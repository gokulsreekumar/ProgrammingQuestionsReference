#include<stdio.h>
#include<stdlib.h>

FILE* F1;
FILE* F2;
void read(int A[], int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                fscanf(F1,"%d", &A[i]);
        }
}
void display(int A[],int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                fprintf(F2,"%d ",A[i]);
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
void Max_Heapify(int A[], int n, int i)
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
        int temp1=A[i];
        A[i]=A[largest];
        A[largest]=temp1;
        Max_Heapify(A, n, largest);
    }
}

void Build_Heap(int A[], int n)
{
    int i;
    int last=n-1;
    for(i=(last/2);i>=0;i--)
    {
        Max_Heapify(A, n, i);
    }
}
int kthSmallest(int A[],int n,int k)
{
    int i;
    int size=n;
    Build_Heap(A, n);
    for(i=n-1;i>=k-1;i--)
    {
        int temp1 = A[0];
        A[0]=A[n-1];
        A[n-1]=temp1;
        n=n-1;
        Max_Heapify(A,n,0);
    }
    return A[k-1];
}


int main(int argc,char* argv[])
{
        F1 = fopen(argv[1],"r");
        F2 = fopen(argv[2],"w");
        char s;
        int num;
        int size;
        int* A;
        while(1)
        {
                fscanf(F1,"%c",&s);
                if(s=='r')
                {
                        fscanf(F1,"%d", &num);
                        size=num;
                        A=(int*)malloc(sizeof(int)*num);
                        read(A,num);
                }
                else if(s=='s')
                {
                        fscanf(F1,"%d", &num);
                        if(num>size)
                        {
                                num=num%size;
                        }
			if(num==0)
			{
				num=size;
			}
                        int p=kthSmallest(A,size,num);
                        fprintf(F2,"%d\n",p);
                }
                else if(s=='d')
                {
                        fscanf(F1,"%d", &num);
                        display(A,num);
                }
                else if(s=='t')
                        break;
        }
    return 0;
}



