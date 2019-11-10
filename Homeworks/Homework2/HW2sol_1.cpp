#include<iostream>
using namespace std;

int main()
{
    long long a, cnt = 1;
    cin>>a;
    while(a>1)
    {
        //cout<<a<<endl;
        if(a&1) a = 3*a+1; /// if(a%2==1) a = 3*a+1;
        else a>>=1; /// else a/=2;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
