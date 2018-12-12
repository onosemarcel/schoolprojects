/*
[a] Grafuri neorientate

1. metode de reprezentare
    Apps : - conversii

2. parcurgere DFS _it ( BKTR_ST )  in NDG

       1 *
       /   \
    2 *    * 3
    /   \
4 *    * 5

 DFS(1) : 1,2,4,5,3

3. parcurgere DFS _rec ( BKTR_ST )  in NDG

*/
#include<iostream>
using namespace std;
int G[100][100];
int n;
int S[100];
int vf;
int read_data()
{  n=3;
    /*
       1 *
       /   \
    2 *    * 3
    /   \
4 *    * 5

 DFS(1) : 1,2,4,5,3

 input.dat
 5
  0 1 1 0 0
  1 0 0 1 1
  1 0 0 0 0
  0 1 0 0 0
  0 1 0 0 0

output.dat
1,2,4,5,3

 */
}

int init(int S[],int top)
{
S[top]=0;
}

int tipar(int S[],int top)
{
 cout<<endl;
 for(int i=1;i<top;i++) cout<<" "<<S[i];
}

int solutie(int S[],int top)
{
if ( top==(n+1) )    return 1;
else return 0;
}

int succesor(int S[],int top)
{
if (S[top]<n)   { S[top]++;return 1;}
else return 0;
}
int valid(int S[],int top)
{
if (top==1)     return 1;
else {
        for(int i=1;i<top;i++)
        {if (S[top]==S[i]) return 0;}
        return 1;
        }
}

int DFS_BKTR_REC_ST(int ST[],int top)
{
 if (solutie(ST,top)) { tipar(ST,top);}
 while (succesor(ST,top))
    {
     if (valid(ST,top)) {
                                init(ST,top+1);
                                DFS_BKTR_REC_ST(ST,top+1);
                              }
    }
return 0; }

int main()
{
read_data();

DFS_BKTR_REC_ST(S,1);
}
