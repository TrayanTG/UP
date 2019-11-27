#include<iostream>
using namespace std;

int main()
{
    char ch;
    do
    {
        cin.get(ch); /// as there is get() and getline() for string, there is get() for 1 character
        if(ch>='A' && ch<='Z' || ch>='a' && ch<='z')cout<<ch;
        else cout<<endl;
    }while(ch!='.');

    /**
    char s[256];
    cin.getline(s, 201);
    for(int i=0;s[i];i++) /// s[i] is equal to s[i]!=0 is equal to s[i]!='\0'
    {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')cout<<ch;
        else cout<<endl;
    }
    */

    return 0;
}
