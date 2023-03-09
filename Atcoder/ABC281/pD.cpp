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
	int n, K, d; cin >> n >> K >> d;
	vector<vector<pii>> dp(n + 1, vector<pii>(10005, mp(0, 0)));
	dp[0][0] = mp(0, 1);
	vector<int> v(n + 1, 0), a(n + 1, 0), b(n + 1, 0);
	for(int i = 1; i <= n; ++i) cin >> v[i], a[i] = v[i] / d, b[i] = v[i] % d;
	for(int i = 1; i <= n; ++i){
		for(int j = K; j >= 1; --j){
			for(int k = 10000; k >= b[i]; k--){
				if(dp[j - 1][k - b[i]].ss) dp[j][k].ss = 1, dp[j][k].ff = max(dp[j][k].ff, dp[j - 1][k - b[i]].ff + v[i]);
			}
		}
	}
	int ans = -1;
	for(int i = 0; i <= 10000; i += d){
		if(dp[K][i].ss != 0) ans = max(ans, dp[K][i].ff);
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
