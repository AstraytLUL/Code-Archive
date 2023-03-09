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
#define maxn 2005
#define mod 1000000007

vector<int> adj[maxn], vis[maxn];

void solve(){
	int n, m; cin >> n >> m;
	vector<int> col(n + 1);
	for(int i = 1; i <= n; ++i){
		adj[i].clear();
		vis[i].assign(n + 1, 0);
		cin >> col[i];
	}
	for(int i = 1; i <= m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	int ans = -1;
	queue<pair<int, pii>> que;
	que.push(mp(0, mp(1, n)));
	vis[1][n] = 1;
	while(que.size()){
		int d = que.front().ff;
		auto [u1, u2] = que.front().ss; que.pop();
		if(u1 == n && u2 == 1) ans = d; 
		for(auto v1:adj[u1]){
			for(auto v2:adj[u2]){
				if(col[v1] == col[v2] || vis[v1][v2]) continue;
				vis[v1][v2] = 1;
				que.push(mp(d + 1, mp(v1, v2)));
			}
		}
	}
	if(vis[n][1]) cout << ans << '\n';
	else cout << -1 << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
