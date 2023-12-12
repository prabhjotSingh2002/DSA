#include<iostream>
using namespace std;



int isPalindrome(string A)
{
    int i=0,j=A.lengthb()-1;

    while(i<j && A[i]==A[j])
    {
        i++;j--;
    }

    if(i<j)
    {
        cout<<"NOT A PALINDROME"<<endl;
        return 0;
    }
    else
    {
        cout<<"PALINDROME"<<endl;
        return 1;
    }
}

int main()
{
    isPalindrome("abaaaabbbbabbbbbxbbbabbbbabaaaaaba");
}