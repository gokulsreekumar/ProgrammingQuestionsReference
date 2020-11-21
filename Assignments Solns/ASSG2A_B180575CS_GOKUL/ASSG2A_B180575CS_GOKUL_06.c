#include <stdio.h>
#include <stdlib.h>

FILE *F1;
FILE *F2;

char* read(int n)
{
        char *arr;
        arr = (char*)malloc((n+1)*sizeof(char));
        int i;
        for(i=0;i<n;i++)
        {
                fscanf(F1,"%c",&arr[i]);
                if(arr[i]==' '||arr[i]=='\n'||arr[i]=='\t'||arr[i]=='\f'||arr[i]=='\r')
                i--;
        }
        return arr;
}


void display(char a[],int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                fprintf(F2,"%c ",a[i]);
                if(i==(n-1))
                fprintf(F2,"\n");
        }
}

void recursive_Selectionsort(char A[],int n)
{
        if(n!=1)
        {
        //finding min
                int min=0;
                for(int i=1;i<n;i++)
                        {
                                if(A[i]<A[min])
                                        min=i;
                        }

        //swapping
                char temp=A[min];
                A[min]=A[0];
                A[0]=temp;
                recursive_Selectionsort(&A[1],n-1);
         }
}

int main(int argc,char *argv[])
  {
        char sel;
        int n;
        char *arr;
        F1=fopen(argv[1],"r");
        F2=fopen(argv[2],"w");
        if(F1==NULL)
         printf("Cant open file");
        else
          {
           while(1)
           {
fscanf(F1,"%c",&sel);
             if(sel=='r')
             {
               fscanf(F1," %d",&n);
               arr= read(n);
             }
            else if(sel=='s')
             {
              recursive_Selectionsort(arr,n);
              for(int i=0;i<n;i++)
                {
                        fprintf(F2,"%c ",arr[i]);
                        if(i==(n-1))
                        fprintf(F2,"\n");
                }
             }

            else if(sel=='d')
             {
               display(arr,n);
             }
             else if(sel=='t')
               break;
           }
    }

   fclose(F1);
   fclose(F2);
}

