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
#define maxn 50005
#define mod 1000000007

int deg[maxn];
vector<int> adj[maxn];
bitset<maxn> cnt[maxn];

void solve(){
	int n, m, q; cin >> n >> m >> q;
	for(int i = 1; i <= m; ++i){
		int a, b; cin >> b >> a;
		deg[b]++;
		adj[a].pb(b);
	}
	queue<int> bfs;
	for(int i = 1; i <= n; ++i){
		if(deg[i] == 0) bfs.push(i);
		cnt[i][i] = 1;
	}
	while(bfs.size()){
		int u = bfs.front();
		bfs.pop();
		for(auto v:adj[u]){
			deg[v]--;
			cnt[v] |= cnt[u];
			if(deg[v] == 0) bfs.push(v);
		}
	}
	for(; q; q--){
		int a, b; cin >> a >> b;
		if(cnt[a][b]) cout << "YES\n";
		else cout << "NO\n";
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}

