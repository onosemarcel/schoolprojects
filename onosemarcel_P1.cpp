#include<fstream>
#include<iostream>
using namespace std;
int n, m=1;
int top;
int L[100];

typedef struct
{
    int x;
    int y;
    double cost;
}muchie;

muchie V[100];

ifstream f("input.dat");
ofstream g("output.dat");

int read_data()
{
    f>>n;
    while(true)
    {
        f>>V[m].x;
        f>>V[m].y;
        f>>V[m].cost;
        m++;
        if(f.eof()) break;
    }
    m=m-2;
    for(int i=1;i<=n;i++)
        L[i]=i;
    f.close();
    return 0;
}

int sort_data()
{
    int g=0;
    while(g==0)
    {
        g=1;
        for(int i=1;i<m;i++)
            if(V[i].cost>V[i+1].cost)
            {
                swap(V[i].cost,V[i+1].cost);
                swap(V[i].x,V[i+1].x);
                swap(V[i].y,V[i+1].y);
                g=0;
            }
    }
}

int arbori()
{
    int s,d;
    cout<<V[1].x<<" "<<V[1].y<<endl;
    s=V[1].x;
    d=V[1].y;
    for(int i=1;i<n;i++)
    {for(int j=2;j<=m;j++)
    {
        if(L[V[j].x]!=L[V[j].y] && (V[j].x==s || V[j].y==s || V[j].x==d || V[j].y==d))
        {
            if(V[j].x==s)
                s=V[j].y;
            if(V[j].y==d)
                d=V[j].x;
            cout<<V[j].x<<" "<<V[j].y<<endl;
            int z=L[V[j].y];
            for(int k=1;k<=n;k++)
                if(L[k]==z)
                    L[k]=L[V[j].x];
            i=1;
            j=2;
        }
    }}
}

int main()
{
    read_data();
    sort_data();
    arbori();
}
