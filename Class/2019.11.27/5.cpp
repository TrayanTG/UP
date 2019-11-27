#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char a[32];
    char b[32];
    cin>>a>>b; /// let's say a is always longer than b
    int lenA = strlen(a), lenB = strlen(b);
    for(int i=0; i<lenA-lenB+1; i++)
    {
        bool f=true;
        for(int j=i;j<i+lenB;j++)
        {
            if(a[j]!=b[j-i])
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            cout<<"yes\n";
            return 0;
        }
    }
    cout<<"no\n";
    return 0;
}
