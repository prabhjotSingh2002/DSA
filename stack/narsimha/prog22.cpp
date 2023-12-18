//finding spans

#include<iostream>
using namespace std;

void findingSpan(int A[],int n)
{
    //input: array of A of n integer 
    //output:array of S of spans of A

    int i,j;
    int s[n]={0};

    for(i=0;i<n;i++)
    {
        j=1;
        while(j<=i && A[i]>A[i-j])
        {
            j=j+1;
        }
        s[i]=j;
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
}

int main()
{
    int n=5;
    int a[5]={6,3,4,5,2};
    findingSpan(a,n);
    
}