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

vector<vector<int>> mmul(vector<vector<int>> A, vector<vector<int>> B){
	int n = A.size();
	vector<vector<int>> ret(n, vector<int>(n, 0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				ret[i][j] += A[i][k] * B[k][j] % mod;
				ret[i][j] %= mod;
			}
		}
	}
	return ret;
}

vector<vector<int>> fastpow(vector<vector<int>> A, int b){
	int n = A.size();
	vector<vector<int>> ret(n, vector<int> (n, 0));
	for(int i = 0; i < n; ++i) ret[i][i] = 1;
	for(; b; b >>= 1){
		if(b & 1) ret = mmul(ret, A);
		A = mmul(A, A);
	}
	return ret;
}

void solve(){
	int n, k; cin >> n >> k;
	vector<vector<int>> adj(n, vector<int>(n, 0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> adj[i][j];
		}
	}
	adj = fastpow(adj, k);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			ans += adj[i][j];
			if(ans > mod) ans -= mod;
		}
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
