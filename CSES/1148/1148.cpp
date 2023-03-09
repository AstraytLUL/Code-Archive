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
#define maxn 1005
#define mod 1000000007
char G[maxn][maxn];
void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> G[i][j];
		}
	}
	vector<int> dp(m + 1, 0);
	vector<vector<pii>> ans(n + 1, vector<pii> (m + 1, mp(0, 0)));
	vector<vector<int>> cnt(n + 2, vector<int> (m + 2, 0)), dp2(n + 2, vector<int> (m + 2, 0)), anss(n + 2, vector<int> (m + 2, 0));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(G[i][j] == '*') dp[j] = 0;
			else dp[j]++;
		}
		stack<pii> stk;
		for(int j = 1; j <= m; ++j){
			if(stk.empty()){
				stk.push(mp(j, dp[j]));
				continue;
			}
			if(dp[j] > stk.top().ss) stk.push(mp(j, dp[j]));
			else{
				while(stk.size() && stk.top().ss >= dp[j]){
					int lb, rb = j, h = stk.top().ss, cur = stk.top().ff;
					stk.pop();
					lb = (stk.size() ? stk.top().ff + 1 : 1);
					ans[i][cur] = mp(h, rb - lb);
				}
				stk.push(mp(j, dp[j]));
			}
		}
		while(stk.size()){
			int lb, rb = m + 1, h = stk.top().ss, cur = stk.top().ff;
			stk.pop();
			lb = (stk.size() ? stk.top().ff + 1 : 1);
			ans[i][cur] = mp(h, rb - lb);
		}
		for(int j = 1; j <= m; ++j){
			int x = ans[i][j].ff, y = ans[i][j].ss;
			cnt[x][y]++;
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cout << cnt[i][j] << ' ';
		}
		cout << '\n';
	}
}

signed main(){
    starburst
	int t = 1; //cin >> t;
    while(t--) solve();
}
