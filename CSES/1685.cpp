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
#define maxn 100005
#define mod 1000000007

int t = 1, cnt = 0, in[maxn], low[maxn], id[maxn], scc_deg[maxn];
vector<int> tmp, adj[maxn], scc_elem[maxn], scc_adj[maxn];

struct DSU{
	int par[maxn];
	void init(int n){
		for(int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int u){
		return u == par[u] ? u : par[u] = find(par[u]);
	}
	void uni(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		par[u] = v;
	}
}dsu;

void dfs(int u){
	in[u] = low[u] = t++;
	tmp.pb(u);
	for(auto v:adj[u]){
		if(!in[v]){
			dfs(v);
			low[u] = min(low[v], low[u]);
		}else if(!id[v]){
			low[u] = min(low[u], in[v]);
		}
	}
	if(low[u] >= in[u]){
		int cur;
		cnt++;
		do{
			cur = tmp.back();
			scc_elem[cnt].pb(cur);
			id[cur] = cnt;
			tmp.pop_back();
		}while(tmp.size() && cur != u);
	}
}

void solve(){
	int n, m; cin >> n >> m;
	dsu.init(n);
	vector<pii> ans;
	for(int i = 1; i <= m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		dsu.uni(u, v);
	}
	int cur = 1;
	for(int u = 1; u <= n; ++u){
		if(dsu.find(u) != dsu.find(cur)){
			adj[cur].pb(u);
			ans.pb(mp(cur, u));
			cur = u;
		}
	}
	if(cur != 1) {
		adj[cur].pb(1);
		ans.pb(mp(cur, 1));
	}
	for(int u = 1; u <= n; ++u){
		if(!in[u]) dfs(u);
	}
	for(int u = 1; u <= n; ++u){
		for(int v:adj[u]){
			if(id[u] == id[v]) continue;
			scc_adj[id[u]].pb(id[v]);
			scc_deg[id[v]]++;
		}
	}
	vector<int> S, T;
	queue<int> bfs;
	for(int u = 1; u <= cnt; u++){
		if(scc_deg[u] == 0) bfs.push(u), S.pb(u);
	}
	while(bfs.size()){
		int u = bfs.front(), c = 0; bfs.pop();
		for(auto v:scc_adj[u]){
			c++;
			scc_deg[v]--;
			if(scc_deg[v] == 0){
				bfs.push(v);
			}
		}
		if(c == 0) T.pb(u);
	}
	int mx = max(S.size(), T.size()), mn = min(S.size(), T.size());
	if(mx != 1){
		for(int i = 0; i < mx; ++i){
			int u = T[i % mn], v = S[i % mn];
			ans.pb(mp(scc_elem[u][0], scc_elem[v][0]));
		}
	}
	cout << ans.size() << '\n';
	for(auto [u, v] :ans){
		cout << u << ' ' << v << '\n';
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
