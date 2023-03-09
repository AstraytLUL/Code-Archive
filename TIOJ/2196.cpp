//君の手を握ってしまったら
//孤独を知らないこの街には
//もう二度と帰ってくることはできないのでしょう
//君が手を差し伸べた 光で影が生まれる
//歌って聞かせて この話の続き
//連れて行って見たことない星まで
//さユリ - 花の塔
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 50005
#define mod 1000000007  

struct edge{
    int v, w, a, b, p;
    edge(int _v, int _w, int _a, int _b, int _p):v(_v), w(_w), a(_a), b(_b), p(_p){}
};

int dep[maxn], par[maxn][17];
int up[maxn][17][60], dwn[maxn][17][60];
vector<edge> adj[maxn];

void dfs(int u, int pp, int d = 1){
    par[u][0] = pp;
    dep[u] = d;
    for(auto [v, w, a, b, p]:adj[u]){
        if(v == pp) continue;
        for(int t = 0; t < 60; ++t){
            up[v][0][t] = w + (b - t + 60) % p;
            dwn[v][0][t] = w + (a - t + 60) % p;
        }
        dfs(v, u, d + 1);
    }
}

int LCA(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 16, k = dep[u] - dep[v]; i >= 0; --i){
        if(k & (1<<i)) u = par[u][i];
    }
    if(u == v) return v;
    for(int i = 16; i >= 0; --i){
        if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    }
    return par[u][0];
}

ll query(int u, int v, int t){
    int lca = LCA(u, v);
    ll ret = 0;
    int d1 = dep[u] - dep[lca];
    for(int i = 16; i >= 0; --i){
        int add = 0;
        if(d1 & (1<<i)) add = up[u][i][t] + 1, u = par[u][i];
        t = (t + add) % 60, ret += add;
    }
    int d2 = dep[v] - dep[lca];
    for(int i = 16; i >= 0; --i){
        int add = 0, tv = v;
        if(d2 & (1<<i)){
            d2 -= (1<<i);
            for(int j = 16; j >= 0; --j){
                if(d2 & (1<<j)) tv = par[tv][j];
            }
            add = dwn[tv][i][t] + 1;
        }
        t = (t + add) % 60, ret += add;
    }
    return ret - 1;
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n - 1; ++i){
        int u, v, w, a, b, p; cin >> u >> v >> w >> a >> b >> p;
        adj[u].pb(edge(v, w, a, b, p));
        adj[v].pb(edge(u, w, b, a, p));
    }
    dfs(1, 1);
    for(int j = 1; j <= 16; ++j){
        for(int i = 1; i <= n; ++i){
            int p = par[i][j - 1];
            par[i][j] = par[p][j - 1];
            for(int t = 0; t < 60; ++t){
                int tmp = (up[i][j - 1][t] + 1), cur = (t + tmp) % 60;
                up[i][j][t] = tmp + up[p][j - 1][cur];
                tmp = (dwn[p][j - 1][t] + 1), cur = (t + tmp) % 60;
                dwn[i][j][t] = tmp + dwn[i][j - 1][cur];
            }
        }
    }
    for(int i = 1; i <= q; ++i){
        int h, m, u, v; cin >> h >> m >> u >> v;
        cout << query(u, v, m) << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
