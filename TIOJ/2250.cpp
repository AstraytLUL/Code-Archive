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
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

map<pii, bool> vis;
map<pii, vector<pii>> adj;
vector<pii> ans;

void dfs(pii cur){
	ans.pb(cur);
	vis[cur] = 1;
	for(int i = 0; i < rand() % 10; ++i)random_shuffle(adj[cur].begin(), adj[cur].end());
	for(auto nxt:adj[cur]){
		if(vis[nxt]) continue;
		dfs(nxt);
		break;
	}
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			vis[mp(i, j)] = 0;
			adj[mp(i, j)] = {};
			for(int u = 1; u <= n; ++u){
				for(int v = 1; v <= m; ++v){
					if(u == i || v == j || abs(u - i) == abs(v - j)) continue;
					adj[mp(i, j)].pb(mp(u, v));
				}
			}
		}
	}
	dfs(mp(1, 1));
	bool ok = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			ok &= vis[mp(i, j)];
		}
	}
	if(!ok) cout << -1 << '\n';
	else {
		for(auto [x, y]:ans){
			cout << x << ' ' << y << '\n';
		}
		cout << "1 1\n"; 
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
