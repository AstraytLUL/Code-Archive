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

vector<vector<int>> MMUL(vector<vector<int>> A, vector<vector<int>> B){
	int n = A.size();
	vector<vector<int>> ret(n, vector<int>(n, -1e18));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				ret[i][j] = max(ret[i][j], A[i][k] + B[k][j]);
			}
		}
	}
	return ret;
}

vector<vector<int>> fastpow(vector<vector<int>> A, int b){
	int n = A.size();
	vector<vector<int>> ret(n, vector<int>(n, -1e18));
	for(int i = 0; i < n; ++i) ret[i][i] = 0;
	for(; b; b >>= 1){
		if(b & 1) ret = MMUL(ret, A);
		A = MMUL(A, A);
	}
	return ret;
}

void solve(){
	int n, m, s, t; cin >> n >> m >> s >> t;
	vector<int> c(n);
	vector<vector<int>> adj(n, vector<int>(n, -1e18));
	for(auto &x:c) cin >> x;
	for(int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		adj[u - 1][v - 1] = c[v - 1];
	}
	vector<vector<int>> res = fastpow(adj, t);
	int ans = -1e18;
	for(int i = 0; i < n; ++i){
		ans = max(ans, res[s - 1][i]);
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
