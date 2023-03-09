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

int dist[maxn], pre[maxn], path_length[maxn];
vector<pii> G[maxn];

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v, w; cin >> u >> v >> w;
		G[u].pb(mp(v, w));
	}
	int s; cin >> s;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fill(dist, dist + maxn, 1e18);
	dist[s] = 0, pre[s] = -1, path_length[s] = 1;
	pq.push(mp(0, s));
	while(pq.size()){
		auto [d, u] = pq.top();
		pq.pop();
		if(d > dist[u]) continue;
		for(auto [v, w]:G[u]){
			if(d + w < dist[v]){
				dist[v] = d + w;
				pre[v] = u;
				path_length[v] = path_length[u] + 1;
				pq.push(mp(d + w, v));
			}
		}
	}
	int query_count; cin >> query_count;
	for(; query_count; query_count--){
		int t; cin >> t;
		cout << dist[t] << '\n';
		int path[path_length[t]];
		int index = 0, cur_node = t;
		while(cur_node != -1){
			path[index] = cur_node;
			cur_node = pre[cur_node];
			index++;
		}
		while(--index >= 0){
			cout << path[index] << ' ';
		}
		cout << '\n';
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
