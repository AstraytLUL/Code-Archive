
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

int dp[maxn][4];

void solve(){
	int n; cin >> n;
	vector<int> v(n + 1, 0);
	for(int i = 1; i <= n; ++i) cin >> v[i];
	for(int i = 0; i < 4; ++i){
		if(i & 1) dp[2][i] += v[2];
		if(i & 2) dp[2][i] += v[1];
	}
	for(int i = 3; i <= n; ++i){
		for(int s = 0; s < 4; ++s){
			if(s == 0) dp[i][s] = max(dp[i - 1][0], dp[i - 1][2]);
			if(s == 1) dp[i][s] = dp[i - 1][0] + v[i];
			if(s == 2) dp[i][s] = max(dp[i - 1][1], dp[i - 1][3]);
			if(s == 3) dp[i][s] = dp[i - 1][1] + v[i];
		}
	}
	int ans = *max_element(dp[n], dp[n] + 4);
	cout << ans;
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
