#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 14;
int n, m, q, col[maxn], gpc, gp[maxn], wh[maxn];
vector<int> g[maxn];
bool check(int v, int c = 1){
    if(col[v])
        return col[v] == c;
    gp[v] = gpc;
    col[v] = c;
    for(auto u : g[v])
        if(!check(u, wh[v] == wh[u] ? 3 - c : c))
            return false;
    return true;
}
void spread(int v){
    if(col[v] == 3)
        return ;
    col[v] = 3;
    for(auto u : g[v])
        spread(u);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        cin >> wh[i];
    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        if(!col[i]){
            if(!check(i))
                spread(i);
            gpc++;
        }
    while(q--){
        int v, u, d, e;
        cin >> v >> u >> d >> e;
        v--, u--;
        if(col[v] == 3 || col[u] == 3 || gp[v] == gp[u] && (col[v] == col[u]) != (d == e))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
