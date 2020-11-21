#include<stdio.h>
#include<stdlib.h>

FILE* F1;
FILE* F2;

void read(int* B, int n)
{
        for(int i = 0; i<n; i++)
        {
                fscanf(F1, "%d", &B[i]);
        }
}
void display(int A[], int n)
{
        for(int i =0; i<n; i++)
                fprintf(F2, "%d ",A[i]);
        fprintf(F2, "\n");
}

int findgcount(int X[], int n, int k)
{
        int i;
        int count=0;
        for(int i=0; i<n; i++)
        {
                if(X[i]>k)
                {
                        count++;
                }
        }
        if(count>=k)
        {
                return 1;
        }
        else
                return 0;
}

int search(int X[], int n)
{
        int i,j;
        int Noble_arr[500] = {0};
        for(j = 0; j<n; j++)
        {
                if(findgcount(X, n, X[j]))
                        Noble_arr[j]+=1;
                else
                        Noble_arr[j]=0;
        }

        int max = -999;
        for(i = 0; i<n; i++)
        {
                if(Noble_arr[i]>0)
                {
                        if(X[i]>=max)
                        {
                                max = X[i];
                        }
                }
        }
        return max;
}
int main(int argc, char* argv[])
{
        F1 = fopen(argv[1], "r");
        F2 = fopen(argv[2], "w");
        char s;
        int num;
        int* A;
        int size;
        while(1)
        {
                fscanf(F1, "%c", &s);
                if(s == 'r')
                {
                        fscanf(F1,"%d", &num);
                        size = num;
                        read(A, num);
                }
                else if(s == 'd')
                {
                        fscanf(F1,"%d", &num);
                        display(A, num);
                }
                else if(s == 's')
                {
                        int p = search(A, size);
                        fprintf(F2,"%d\n", p);
                }
                else if(s == 't')
                        break;

        }

}


