#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int ans1[1001][1001];
int dis[1001][1001];
int ans[1001][1001];
void bfs(int a,int b,int m,int n,int ans[][1001])
{
    queue<pair<int,int>> q;
    q.push({a,b});
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=INT_MAX;
            ans1[i][j]=ans[i][j];
        }
    }
    dis[a][b]=0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>0 && y1>0 && x1<=m && y1<=n && ans[x1][y1]!=-1 ){
                if(dis[x1][y1]==INT_MAX){
                    dis[x1][y1]=dis[x][y]+1;
                    ans1[x1][y1]+=ans1[x][y];
                    q.push({x1,y1});
                }
                if(dis[x1][y1]==dis[x][y]+1){
                    ans1[x1][y1]=max(ans1[x1][y1],ans1[x][y]+ans[x1][y1]);
                }
 
            }
 
        }
    }
    return;
 
}
 
int main(){
    int m,n;
    cin>>m>>n;
    char c;
 
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='*') ans[i][j]=-1;
            else ans[i][j]=c-'0';
        }
    }
    int x,y;
    cin>>x>>y;
    bfs(x,y,m,n,ans);
    int Q;
    cin>>Q;
    while(Q--){
        int w,z;
        cin>>w>>z;
        if(dis[w][z]==INT_MAX) cout<<-1<<" "<<-1<<endl;
        else cout<<dis[w][z]<<" "<<ans1[w][z]<<endl;
    }
 
 
}
