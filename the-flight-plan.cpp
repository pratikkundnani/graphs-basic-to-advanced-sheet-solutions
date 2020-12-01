//Author: kaiyu
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<int,int>
#define tt ll t;cin >> t;while(t--)
#define int3(x,y,z) ll x,y,z;cin >> x >> y >> z;
#define int2(x,y) ll x,y;cin >> x >>y;
#define int1(x) ll x;cin>>x;
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
ll power(ll a,ll b,ll m=mod){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


bool cmp(pair<string,int>p1,pair<string,int>p2) {
    return p1.ss > p2.ss;
}

const int MAXN = 1 * 1000 + 10;
bool vis[MAXN];
vvi adj(MAXN);
int n,m,t,c;
int from, to;
vi p(MAXN);
void bfs(int source) {
    vis[source] = true;
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int child:adj[node]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
                p[child] = node;
            }
        }
    }
}


int32_t main() {
    fio

    cin >> n >> m >> t >> c;
    for (int i = 0; i <m ; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cin >> from >> to;
    for (int j = 1; j <= n; ++j) {
        sort(all(adj[j]));
    }
    bfs(from);
    vector<int>path;
    for(int i = to;i!= from;i = p[i]) {
        path.pb(i);
    }
    path.pb(from);
    reverse(path.begin(),path.end());
    cout << path.size() << endl;
   for(int i: path) {
       cout << i << " ";
   }
}





