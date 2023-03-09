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

pii dist[maxn];
vector<pair<int, pii>> G1[maxn], G2[maxn];

void solve(){
	int n, m, s, t, d; cin >> n >> m >> s >> t >> d;
	vector<int> p(m, 0), h(m, 0);
	for(int i = 0; i < m; ++i) cin >> p[i], p[i]--;
	vector<pii> E(m);
	for(int i = 0; i < m; ++i) {
		cin >> E[i].ff >> E[i].ss;
	}
	for(int i = 0; i < m; ++i){
		int id = p[i];
		int u = E[id].ff, v = E[id].ss;
		G1[u].pb(mp(v, mp(i, id)));
		G1[v].pb(mp(u, mp(i, id)));
	}
	for(int i = 1; i <= n; ++i) dist[i] = mp(1e18, -1);
	dist[s].ff = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(mp(0, s));
	while(pq.size()){
		pii cur;
		do{
			cur = pq.top();
			pq.pop();
		}while(pq.size() && cur.ff > dist[cur.ss].ff);
		auto [d, u] = cur;
		for(auto [v, tmp] : G1[u]){
			auto [w, id] = tmp;
			if(max(w, d) < dist[v].ff){
				dist[v] = mp(max(w, d), id);
				pq.push(mp(dist[v].ff, v));
			}
		}
	}
	int SE = p[dist[t].ff];
	for(int i = 0; i <= dist[t].ff; ++i) h[p[i]] = i + 1;
	for(int i = dist[t].ff + 1; i < m; ++i) h[p[i]] = d + i + 1;
	int sum = 0, cur = t;
	while(cur != s){
		sum += h[dist[cur].ss];
		if(cur == E[dist[cur].ss].ff) cur = E[dist[cur].ss].ss;
		else cur = E[dist[cur].ss].ff;
	}
	h[SE] += d - sum;
	if((dist[t].ff != 0 && h[SE] <= h[p[dist[t].ff - 1]]) || h[SE] < 0) {
		cout << "NO\n";
		return;
	}
	for(int i = 1; i <= n; ++i) dist[i] = mp(1e18, -1);
	for(int i = 0; i < m; ++i){
		int id = p[i];
		int u = E[id].ff, v = E[id].ss;
		G2[u].pb(mp(v, mp(h[id], id)));
		G2[v].pb(mp(u, mp(h[id], id)));
	}
	dist[s].ff = 0;
	pq.push(mp(0, s));
	while(pq.size()){
		pii cur;
		do{
			cur = pq.top();
			pq.pop();
		}while(pq.size() && cur.ff > dist[cur.ss].ff);
		auto [d, u] = cur;
		for(auto [v, tmp] : G2[u]){
			auto [w, id] = tmp;
			if(w + d < dist[v].ff){
				dist[v] = mp(w + d, id);
				pq.push(mp(w + d, v));
			}
		}
	}
	for(int i = 1; i < m; ++i){
		if(h[p[i - 1]] >= h[p[i]]) {
			cout << "NO\n";
			return;
		}
	}
	if(dist[t].ff <= d){
		cout << "YES\n";
		for(auto x:h) cout << x << ' ';
	}else cout << "NO\n";
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
