#include<iostream>
using namespace std;

const double PI = 3.14159; /// You can calculate with perfect precision pi = 4*arctan(1) or pi=arccos(-1), but we haven't learnt those yet

int main()
{
    char c;
    cin>>c;
    if(c=='S')
    {
        double a;
        cin>>a;
        cout<<a*a<<endl;
    }
    else if(c=='C')
    {
        double r;
        cin>>r;
        cout<<r*r*PI<<endl;
    }
    else if(c=='R')
    {
        double a,b;
        cin>>a>>b;
        cout<<a*b<<endl;
    }
    else if(c=='T')
    {
        double a,b,h;
        cin>>a>>b>>h;
        cout<<((a+b)*h)/2<<endl; /// We can omit the brackets but it's good practice to write brackets in longer formulas
    }
    else if(c=='3')
    {
        double a,h;
        cin>>a>>h;
        cout<<(a*h)/2<<endl; /// We can again omit the brackets, but again.. good practice
    }
    else
    {
        cout<<"Wrong symbol!"<<endl;
    }
    return 0;
}
