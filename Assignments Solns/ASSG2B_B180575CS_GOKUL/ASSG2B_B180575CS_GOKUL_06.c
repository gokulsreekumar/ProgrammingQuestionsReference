#include<stdio.h>
#include <stdlib.h>
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
void exchange(int* p, int* q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

int partition(int A[], int p, int r,int k)
{
if(p<r)
{
    int n = r-p+1;
    int x;
    x=A[r];
    int i=p;
    int j=p;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            exchange(&A[i],&A[j]);
            i=i+1;
        }
    }
    exchange(&A[i],&A[r]);
    if(i==n-k)
    {
        return A[i];
    }
    else if(i==r)
    {
        return partition(A,p,r-1,k-1);
    }
    return partition(A,p,r,k);
}
else
        return -1;

}
void kthLargest(int A[], int n, int k)
{
        int r=n-1;
        int p=partition(A,0,r,k);
        fprintf(F2,"%d\n",p);
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
                        kthLargest(A,size,num);
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
           


