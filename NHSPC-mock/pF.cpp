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
#define maxn 1000005
#define mod 1000000007

int dp[maxn], sz[maxn];
vector<int> adj[maxn];

void dfs(int u, int p){
    bool leaf = 1;
	sz[u] = 1;
    int mx_son = 0;
    for(auto v:adj[u]){
        if(v == p) continue;
        leaf = 0;
        dfs(v, u);
		sz[u] += sz[v];
    }
	int k = adj[u].size();
	sort(adj[u].begin(), adj[u].end(), [](int a, int b){return (dp[a] == dp[b] ? sz[a] > sz[b] : dp[a] > dp[b]);});
	for(int i = 0, c = 0; i < adj[u].size(); ++i){
		int v = adj[u][i];
		if(v == p) continue;
		dp[u] = max(dp[u], dp[v] + c);
		c++;
	}
	if(leaf) dp[u] = 1;
}

void solve(){
    int n, a; cin >> n >> a;
	for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
	if(n <= 2){
		cout << "0\n";
		return;
	}
    dfs(a, a);
    cout << dp[a] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
