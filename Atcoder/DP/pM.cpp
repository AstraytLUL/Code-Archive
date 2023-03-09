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

void solve(){
	int n, k; cin >> n >> k;
	vector<int> dp(k + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		int a; cin >> a;
		vector<int> tmp(k + 1, 0);
		for(int j = 0; j <= k; ++j){
			int id = j + a + 1;
			tmp[j] += dp[j];
			tmp[j] %= mod;
			if(id <= k) tmp[id] -= dp[j], tmp[j] %= mod;
			if(j != 0) tmp[j] += tmp[j - 1], tmp[j] %= mod;
		}
		dp = tmp;
	}
	cout << (dp[k] + mod) % mod;
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
