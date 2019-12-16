#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int a[128][128], n, m;

void print()
{
    system("cls");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cout<<a[i][j]<<' ';
        cout<<endl;
    }
    system("pause");
}

bool bfs(int x, int y, int step=1){
    print();
    if(x==n-1 && y==m-1)return 1;

    a[x][y]=step;
    //нагоре
    if(x>0 && (a[x-1][y]==0 || a[x-1][y]>step+1))
        if(bfs(x-1, y, step+1))return 1;
    //надолу
    if(x<n-1 && (a[x+1][y]==0 || a[x+1][y]>step+1))
        if(bfs(x+1, y, step+1))return 1;
    //наляво
    if(y>0 && (a[x][y-1]==0 || a[x][y-1]>step+1))
        if(bfs(x, y-1, step+1))return 1;
    //надясно
    if(y<m-1 && (a[x][y+1]==0 || a[x][y+1]>step+1))
        if(bfs(x, y+1, step+1))return 1;
    return 0;
}


int main(){
    char x;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>x;
            if(x=='-')a[i][j]=-1;
        }
    }
    cout<<bfs(0, 0)<<endl;


    return 0;
}