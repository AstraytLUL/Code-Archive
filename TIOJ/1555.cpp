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
#define maxn 5005
#define mod 1000000007

int dp[maxn][maxn];

void solve(){
	int n, m; cin >> n >> m;
	int ans = 0, ans2 = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			char c; cin >> c;
			if(c == '1') dp[i][j] = 0;
			else {
				dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
				ans2 = max(ans2, dp[i][j]);
				ans += dp[i][j];
			}
		}
	}
	cout << ans << ' ' << ans2 << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
