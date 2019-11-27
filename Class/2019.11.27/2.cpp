#include<iostream>
using namespace std;

int main()
{
    int a[256][256];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
      cin>>a[i][j];
    int l=0, r=n-1, u=0, d=n-1;
    while(l<=r && u<=d)
    {
        if(l<=r && u<=d)
        {
            for(int i=l;i<=r;i++)cout<<a[u][i]<<' ';
            u++;
        }
        if(l<=r && u<=d)
        {
            for(int i=u;i<=d;i++)cout<<a[i][r]<<' ';
            r--;
        }
        if(l<=r && u<=d)
        {
            for(int i=r;i>=l;i--)cout<<a[d][i]<<' ';
            d--;
        }
        if(l<=r && u<=d)
        {
            for(int i=d;i>=u;i--)cout<<a[i][l]<<' ';
            l++;
        }
    }
    return 0;
}
