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
#define maxn 305
#define mod 1000000007

int a[maxn];
pii dist[maxn][maxn];

pii operator+ (pii a, pii b){
	return pii(a.ff + b.ff, a.ss + b.ss);
}

pii cmp(pii a, pii b){
	if(a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss)) return a;
	else return b;
}

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == j) dist[i][j] = pii(0, 0); 
			else dist[i][j] = pii(1ll<<60, 0);
			char c; cin >> c;
			if(c == 'Y') dist[i][j] = pii(1, a[i]);
		}
	}
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				dist[i][j] = cmp(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int q; cin >> q;
	for(; q; q--){
		int u, v; cin >> u >> v;
		if(dist[u][v].ff > n) cout << "Impossible\n";
		else cout << dist[u][v].ff << ' ' << dist[u][v].ss + a[v] << '\n';
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
