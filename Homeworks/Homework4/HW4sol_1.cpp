#include<iostream>
using namespace std;

const int MAX = 128;
const int MAX_INT = ~(1<<31); /// signed

void init(int m, int n, int stx, int sty, int (*time)[MAX])
{
    for(int i=0; i<m; i++)
     for(int j=0; j<n; j++)
      time[i][j] = MAX_INT;
    time[sty][stx] = 1;
}

int time1(char c)
{
    return c-'0';
}

int time2(char c)
{
    if (c < '4') return 1;
    return 3;
}

void findP(const char (*board)[MAX], int (*timeTable)[MAX], int m, int n, int x, int y, int fnx, int fny, int (*tPath)[2], int (*path)[2], int &pathLen, int &time, int tPathLen = 0, int tTime = 1)
{
    if(tTime>=time) return;

    tPath[tPathLen][0] = y;
    tPath[tPathLen][1] = x;

    if(x==fnx && y==fny)
    {
        time = tTime;
        pathLen = tPathLen;
        for(int i=0; i<=pathLen; i++)
        {
            path[i][0] = tPath[i][0];
            path[i][1] = tPath[i][1];
        }
        return;
    }

    if(x>0 && board[y][x-1]!='0' && timeTable[y][x-1]>tTime+time1(board[y][x-1]))
    {
        timeTable[y][x-1] = tTime+time1(board[y][x-1]);
        findP(board, timeTable, m, n, x-1, y, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time1(board[y][x-1]));
    }
    if(y>0 && board[y-1][x]!='0' && timeTable[y-1][x]>tTime+time1(board[y-1][x]))
    {
        timeTable[y-1][x] = tTime+time1(board[y-1][x]);
        findP(board, timeTable, m, n, x, y-1, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time1(board[y-1][x]));
    }
    if(x<n-1 && board[y][x+1]!='0' && timeTable[y][x+1]>tTime+time1(board[y][x+1]))
    {
        timeTable[y][x+1] = tTime+time1(board[y][x+1]);
        findP(board, timeTable, m, n, x+1, y, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time1(board[y][x+1]));
    }
    if(y<m-1 && board[y+1][x]!='0' && timeTable[y+1][x]>tTime+time1(board[y+1][x]))
    {
        timeTable[y+1][x] = tTime+time1(board[y+1][x]);
        findP(board, timeTable, m, n, x, y+1, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time1(board[y+1][x]));
    }
}

void escortP(const char (*board)[MAX], int (*timeTable)[MAX], int m, int n, int x, int y, int fnx, int fny, int (*tPath)[2], int (*path)[2], int &pathLen, int &time, int tPathLen = 0, int tTime = 1)
{

    if(tTime>=time) return;

    tPath[tPathLen][0] = y;
    tPath[tPathLen][1] = x;

    if(x==fnx && y==fny)
    {
        time = tTime;
        pathLen = tPathLen;
        for(int i=0; i<=pathLen; i++)
        {
            path[i][0] = tPath[i][0];
            path[i][1] = tPath[i][1];
        }
        return;
    }

    if(x>0 && board[y][x-1]!='0' && board[y][x-1]!='2' && timeTable[y][x-1]>tTime+time2(board[y][x-1]))
    {
        timeTable[y][x-1] = tTime+time2(board[y][x-1]);
        escortP(board, timeTable, m, n, x-1, y, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time2(board[y][x-1]));
    }
    if(y>0 && board[y-1][x]!='0' && board[y-1][x]!='2' && timeTable[y-1][x]>tTime+time2(board[y-1][x]))
    {
        timeTable[y-1][x] = tTime+time2(board[y-1][x]);
        escortP(board, timeTable, m, n, x, y-1, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time2(board[y-1][x]));
    }
    if(x<n-1 && board[y][x+1]!='0' && board[y][x+1]!='2' && timeTable[y][x+1]>tTime+time2(board[y][x+1]))
    {
        timeTable[y][x+1] = tTime+time2(board[y][x+1]);
        escortP(board, timeTable, m, n, x+1, y, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time2(board[y][x+1]));
    }
    if(y<m-1 && board[y+1][x]!='0' && board[y+1][x]!='2' && timeTable[y+1][x]>tTime+time2(board[y+1][x]))
    {
        timeTable[y+1][x] = tTime+time2(board[y+1][x]);
        escortP(board, timeTable, m, n, x, y+1, fnx, fny, tPath, path, pathLen, time, tPathLen+1, tTime+time2(board[y+1][x]));
    }
}

void showPath(const int (*path)[2], int pathLen)
{
    cout<<'('<<path[0][0]<<", "<<path[0][1]<<')';
    for(int i=1;i<=pathLen;i++)cout<<"->("<<path[i][0]<<", "<<path[i][1]<<')';
    cout<<endl;
}

int main()
{
    char board[MAX][MAX];
    int timeTable[MAX][MAX]; /// time to reach st->(x, y) for the st->pr stage and time to reach pr->(x, y) for the pr->fn stage
    int path1[MAX*MAX][2], pathLen1 = MAX_INT, time1 = MAX_INT, path2[MAX*MAX][2], pathLen2 = MAX_INT, time2 = MAX_INT, tPath[MAX*MAX][2];
    int m, n, sty, stx, pry, prx, fny, fnx;

    /// Input
    cin>>m>>n>>sty>>stx>>pry>>prx>>fny>>fnx;
    for(int i=0; i<m; i++) cin>>board[i];

    /// st->pr
    init(m, n, stx, sty, timeTable);
    findP(board, timeTable, m, n, stx, sty, prx, pry, tPath, path1, pathLen1, time1);

    /// pr->fn
    init(m, n, prx, pry, timeTable);
    escortP(board, timeTable, m, n, prx, pry, fnx, fny, tPath, path2, pathLen2, time2);

    cout<<time1<<' '<<time2<<endl;
    showPath(path1, pathLen1);
    showPath(path2, pathLen2);

    return 0;
}

/**
1 10
0 0 0 9 0 0
1111011111
10 10
*/
