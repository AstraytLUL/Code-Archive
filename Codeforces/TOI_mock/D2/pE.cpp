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

pair<int, pii> min(pair<int, pii> a, pair<int, pii> b){
	if(a.ff > b.ff) return b;
	else return a;
}

void solve(){
	int n, s; cin >> n >> s;
	vector<int> d(n - 1);
	int tot = 0;
	for(int &x:d) cin >> x, tot += x;
	int k = s % n;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	vector<vector<pair<int, pii>>> dp2(n, vector<pair<int, pii>> (n, mp(1e18, mp(0, 0))));
	dp[0][0] = 1;
	dp2[0][0] = mp(0, mp(0, 0));
	for(int i = 0; i < n - 1; ++i){
		for(int j = 0; j < n; ++j){
			int take = (j + d[i]) % n;
			dp[i + 1][take] |= dp[i][j];
			dp2[i + 1][take] = min(dp2[i + 1][take], mp(dp2[i][j].ff, mp(j, 1)));
			dp[i + 1][j] |= dp[i][j];
			dp2[i + 1][j] = min(dp2[i + 1][j], mp(max(dp2[i][j].ff, d[i]), mp(j, 0)));
		}
	}
	vector<int> ans(n);
	if(dp[n - 1][k] == 0 || dp2[n - 1][k].ff > s / n) {
		cout << "-1\n";
		return;
	}
	int b = s / n;
	ans[n - 1] = b;
	int cur = (k - b) % n + n;
	for(int i = n - 1; i > 0; --i){
		cur %= n;
		cout << cur << ' ';
		if(dp2[i][cur].ss.ss) cout << "1\n", ans[i - 1] = b + d[i - 1];
		else cout << "0\n", ans[i - 1] = b - d[i - 1];
		cur = (dp2[i][cur].ss.ff - b) % n + n;
	}
	for(auto x:ans) cout << x << ' ';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
