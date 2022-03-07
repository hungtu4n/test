#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

void up(int a[4][4])
{
    int pos=0;
    for (int j=0;j<4;j++)
    {
        for (int i=0;i<4;i++)
        {
            if (!a[i][j]) continue;
            if (a[i][j]==a[i+1][j])
            {
                a[i][j]*=2;
                a[i+1][j]=0;
            }
            a[pos++][j]=a[i][j];
            if (i!=pos-1) a[i][j]=0;
        }
        pos=0;
    }
}
void down(int a[4][4])
{
    int pos=3;
    for (int j=0;j<4;j++)
    {
        for (int i=3;i>=0;i--)
        {
            if (!a[i][j]) continue;
            if (a[i][j]==a[i-1][j])
            {
                a[i][j]*=2;
                a[i-1][j]=0;
            }
            a[pos--][j]=a[i][j];
            if (i!=pos+1) a[i][j]=0;
        }
        pos=3;
    }
}
void left(int a[4][4])
{
    int pos=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (!a[i][j]) continue;
            if (a[i][j]==a[i][j+1])
            {
                a[i][j]*=2;
                a[i][j+1]=0;
            }
            a[i][pos++]=a[i][j];
            if (j!=pos-1) a[i][j]=0;
        }
        pos=0;
    }
}
void right(int a[4][4])
{
    int pos=3;
    for (int i=0;i<4;i++)
    {
        for (int j=3;j>=0;j--)
        {
            if (!a[i][j]) continue;
            if (a[i][j]==a[i][j-1])
            {
                a[i][j]*=2;
                a[i][j-1]=0;
            }
            a[i][pos--]=a[i][j];
            if (j!=pos+1) a[i][j]=0;
        }
        pos=3;
    }
}
void output(int a[4][4])
{
    int c(0);
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            Cout:cout<<a[i][j]<<setw(10);
        }
        cout<<"\n\n\n\n";
    }
}

int main()
{
    srand(time(0));
    int board[4][4];char act;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) board[i][j]=1;
    act=getch();
    switch (act)
    {
        case 'W':case 'w':up(board);    break;
        case 'S':case 's':down(board);  break;
        case 'A':case 'a':left(board);  break;
        case 'D':case 'd':right(board); break;
    }
    output(board);
    return 0;
}
