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
	int n, ans = -1e18; cin >> n;
	vector<vector<int>> a(n);
	vector<int> p(n, 0), s(n, 0), tot(n, 0);
	int poss = 0, pos = 0;
	for(int i = 0; i < n; ++i){
		int k; cin >> k;
		a[i].resize(k);
		int dp = -1e18, dp2 = -1e18;
		for(int j = 0; j < k; ++j) cin >> a[i][j], dp = max(a[i][j], dp + a[i][j]), dp2 = max(dp, dp2), pos |= (a[i][j] > 0);
		for(int j = 0, pre = 0; j < k; ++j) pre += a[i][j], p[i] = max(p[i], pre);
		for(int j = k - 1, suf = 0; j >= 0; --j) suf += a[i][j], s[i] = max(s[i], suf), tot[i] += a[i][j];
		if(tot[i] > 0) poss += tot[i];
		ans = max(ans, dp2);
	}
	if(!pos){
		cout << ans << '\n';
		return;
	}
	int tosmx = 0, topmx = 0;
	for(int i = 0; i < n; ++i){
		int tos = (tot[i] > 0 ? s[i] - tot[i] : s[i]), topp = (tot[i] > 0 ? p[i] - tot[i] : p[i]);
		ans = max(ans, max(poss + topp + tosmx, poss + tos + topmx));
		topmx = max(topmx, topp);
		tosmx = max(tosmx, tos);
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
