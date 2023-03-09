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

int cost = 0;

struct DisjointSetUnion{
	int par[maxn], val[maxn];
	void init(int n){
		for(int i = 1; i <= n; ++i) par[i] = i;
	}
	int qry(int v){
		return (v == par[v] ? v : par[v] = qry(par[v]));
	}
	void uni(int u, int v){
		u = qry(u), v = qry(v);
		par[u] = v;
		val[v] += val[u];
		cost = max(cost, val[v]);
	}
}dsu;

void solve(){
	int n; cin >> n;
	dsu.init(n);
	vector<int> v(n + 1, 0), id(n + 1, 0), used(n + 2, 0);
   	for(int i = 1; i <= n; ++i) cin >> v[i], dsu.val[i] = v[i];
	for(int i = 1; i <= n; ++i) cin >> id[i];
	reverse(id.begin() + 1, id.end());
	vector<int> ans(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		int k = id[i];
		if(used[k - 1]) dsu.uni(k - 1, k);
		if(used[k + 1]) dsu.uni(k + 1, k);
		int kk = dsu.qry(k);
		cost = max(cost, dsu.val[k]);
		ans[n - i + 1] = cost;
		used[k] = 1;
	}
	for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
