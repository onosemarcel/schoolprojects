#include <iostream>
#include <fstream>

using namespace std;


ifstream f("input.dat");
int G[100][100], start=1, n, ST[100], VIZ[100], k, top=1;

void read_data()
{
    f >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f >> G[i][j];
    f >> k;
}

int push(int ST[], int *top, int value)
{
    *top = *top + 1;
    ST[*top] = value;
    return 0;
}

int pop(int ST[], int *top)
{
    int old = ST[*top];
    (*top) = (*top) - 1;
    return old;
}

int isEmpty(int ST[], int top)
{
    if( top==0) return 1;
    return 0;
}

int DFS_REC(int ST[], int *top, int node)
{
    if(!isEmpty(ST, *top))
        {
            int some;
            some = pop(ST, top);
            cout << " " << some;
            VIZ[some] = 1;
            for(int i = 1; i <= n; i++){
            if(G[some][i] == 1 && VIZ[i] == 0)
            {
                    push(ST, top, i);
                    DFS_REC(ST, top, i);
            }
        }
    return 0;
        }
}

int main()
{
    read_data();
    push(ST, &top, start);
    DFS_REC(ST, &top, start);
}
