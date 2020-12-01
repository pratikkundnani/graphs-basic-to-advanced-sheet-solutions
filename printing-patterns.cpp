#include<bits/stdc++.h>
using namespace std;
 
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
 
bool isValid(int i, int j, int row, int col)
{
    if(i>=0 and i<row and j>=0 and j<col) return true;
    return false;
}
 
 
int main()
{
    
    int row,col,ci,cj;
    cin>>row>>col>>ci>>cj;
 
    int level[row][col];
 
    bool visited[row][col];
    memset(visited,false,sizeof(visited));
 
    level[ci][cj]=0;
    visited[ci][cj]=true;
    queue<pair<int,int>> Q;
    Q.push(make_pair(ci,cj));
    
    int i,j;
    while(!Q.empty())
    {
         i=Q.front().first;
         j=Q.front().second;
        Q.pop();
 
        for(int k=0;k<8;k++)
        {
            if(isValid(i+dx[k],j+dy[k],row,col) )
            {  
                if(!visited[i+dx[k]][j+dy[k]])
                {
                     level[i+dx[k]][j+dy[k]]=level[i][j]+1;
                     visited[i+dx[k]][j+dy[k]]=true;
                     Q.push(make_pair(i+dx[k],j+dy[k]));
 
                }
               
            }
        }
 
 
    }
 
    for(int p=0;p<row;p++)
    {
        for(int q=0;q<col;q++)
        {
            cout<<level[p][q]<<" ";
        }
        cout<<endl;
    }
    
    
 
    
}
