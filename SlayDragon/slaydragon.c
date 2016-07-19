#include <stdio.h>
#include <stdlib.h>

int* shellSort(int* A, int n)
{
    int increment = n;
    int i,temp,j;
    do
    {
        increment = increment/5+1;
        for(i = increment;i<n;i++)
        {
            if(A[i]<A[i-increment])
            {
                temp = A[i];
                for(j=i-increment;A[j]>temp && j>=0;j-=increment)
                    A[j+increment] = A[j];
                A[j+increment] = temp;
            }
        }
    }
    while(increment>1);
    return A;
}

int main()
{
    const int MAX = 20010;
    int Array_Dnumber[MAX],Array_Knumber[MAX];
    int Dnumber,Knumber;
    int i,j;
    while(scanf("%d%d",&Dnumber,&Knumber) == 2)
    {
        if(Dnumber == 0 && Knumber == 0)
        {
            break;
        }

        for(i=0;i<Dnumber;i++)
            scanf("%d",&Array_Dnumber[i]);
        for(i=0;i<Knumber;i++)
            scanf("%d",&Array_Knumber[i]);

        shellSort(Array_Knumber,Knumber);
        shellSort(Array_Dnumber,Dnumber);

        int sum=0;
        i=j=0;
        for(i=0;i<Dnumber;i++)
        {
            if(j>=Knumber) break;
            while(j<Knumber && Array_Dnumber[i]>Array_Knumber[j])
                j++;
            if(j>=Knumber) break;
            sum+=Array_Knumber[j];
            j++;
        }
        if(i<Dnumber)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n",sum);

    }

    return 0;
}
