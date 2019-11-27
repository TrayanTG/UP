#include<iostream>
using namespace std;

int main()
{
    int a[256][256];
    int m, n, p, q, maxSum = (1<<31); /// getting the minimum integer (in binary form it is 10000000 00000000 00000000 000000000)
    cin>>m>>n; /// by the description of the task n and m are swapped but that doesn't affect our code if we swap m and n everywhere
    for(int i=0;i<m;i++)
     for(int j=0;j<n;j++)
      cin>>a[i][j];
    cin>>p>>q;
    for(int i=0;i<=m-p;i++)
     for(int j=0;j<=n-q;j++)
     {
         int s=0;
         for(int i1=i;i1<i+p;i1++)
          for(int j1=j;j1<j+q;j1++)
           s+=a[i1][j1];
         maxSum = s>maxSum? s: maxSum;
     }
    cout<<maxSum<<endl;
    return 0;
}
