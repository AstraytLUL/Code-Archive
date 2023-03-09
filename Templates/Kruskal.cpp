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

int ans = 0, cnt = 0;

struct DisjointSetUnion{
    int par[maxn];
    void init(int n){
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    int find(int u){
        return u == par[u] ? u : par[u] = find(par[u]);
    }
    void Union(int u, int v, int w){
        u = find(u), v = find(v);
        if(u != v) par[u] = v, ans += w, cnt++;
    }
}dsu;

struct edge{
	int u, v, w;
};

void solve(){
	int n, m;
	while(cin >> n >> m){
		dsu.init(n);
		cnt = 0, ans = 0;
		vector<edge> E(m);
		for(auto &[u, v, w]:E){
			cin >> u >> v >> w;
		}
		sort(E.begin(), E.end(), [](edge E1, edge E2){return E1.w < E2.w;});
		for(auto [u, v, w]:E){
			dsu.Union(u, v, w);
		}
		if(cnt == n - 1) cout << ans << '\n';
		else cout << "-1\n";
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
