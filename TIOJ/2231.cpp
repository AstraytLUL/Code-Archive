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
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

void solve(){
	int n; cin >> n;
	vector<int> b(n + 1, 0), w(n + 1, 0), t(n + 1, 0);
	for(int i = 1; i <= n; ++i) cin >> b[i], b[i] += b[i - 1];
	for(int i = 1; i <= n; ++i) cin >> w[i], w[i] += w[i - 1];
	for(int i = 1; i <= n; ++i) cin >> t[i];
	if(n > 3000) return;
	vector<vector<int>> dp(n + 1, vector<int>(2, 2e9));
	dp[0][0] = dp[0][1] = 0;
	/*
	struct range{
		int l, r, id;
		range(int _l, int _r, int _i): l(_l), r(_r), id(_i){}
	};
	deque<range> dq[2];
	dq[0].pb(range(0, n, 0));
	dq[1].pb(range(0, n, 0));
	*/
	int ans = 2e9;
	for(int i = 1; i <= n; ++i){
		int tmp = 0;
		for(int j = i - 1; j >= 0; --j){
			tmp = max(tmp, w[j] + t[j]);
			dp[i][0] = min(dp[i][0], dp[j][1] + tmp - (j == 0 ? 0 : w[j - 1]));
		}
		tmp = 0;
		for(int j = i - 1; j >= 0; --j){
			tmp = max(tmp, b[j] + t[j]);
		   	dp[i][1] = min(dp[i][1], dp[j][0] + tmp - (j == 0 ? 0 : b[j - 1]));	
		}
		ans = min(ans, dp[i][0] + b[n] - b[i - 1]);
		ans = min(ans, dp[i][1] + w[n] - w[i - 1]);
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
