#include<iostream>
using namespace std;

int main()
{
    int hist[10]={0};
    char ch;
    do
    {
        cin.get(ch);
        if(ch>='0' && ch<='9')hist[ch-'0']++;
    }while(ch!='\n');

    for(int i=9;i>=0;i--)
     for(int j=0;j<hist[i];j++)
      cout<<i;
    cout<<endl;
    return 0;
}
