#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#pragma GCC optimize("O2")
#define CLR(s) memset(&s, 0, sizeof(s))
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leastsigbit(x)     __builtin_ffs(x)
const int MOD = 1e9 + 7;
#define hmap        unordered_map
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define tt ll tt;cin >> tt;while(tt--)
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
const double PI = acos(-1);
ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll power(ll a,ll b,ll m=MOD){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
double distform(int x, int y, int z, int w) {//(x1,y1,x2,y2)
    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
}
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
const int MAXN = 2e5+ 10;
const ll inf = 1e18;

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}
void read(vi & a) { for (int i = 0; i < sz(a); ++i) cin >> a[i];}
vvi a(1001,vi(1001));
int tmp;
int n,m;
void dfs(int i, int j, vector<vector<bool>> & vis) {
    vis[i][j] = true;
    tmp++;
    for (int k = 0; k < 8; ++k) {
        if( 0 <= i + dx[k]  && i + dx[k] < n && 0 <= j + dy[k] && j + dy[k] < m)
        if(!vis[i + dx[k]][j + dy[k]] && a[i + dx[k]][j + dy[k]] == 1) {
            dfs(i + dx[k],j + dy[k],vis);
        }
    }
}
void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m));

    int troops = 0, maxSoldiers = 0;tmp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!vis[i][j] && a[i][j] == 1) {
                troops++;
                dfs(i,j,vis);
                maxSoldiers = max(maxSoldiers,tmp);
                tmp = 0;
            }
        }
    }
    cout << troops << " " << maxSoldiers << endl;


}
int32_t main() {
    fio
    tt
    solve();
}




