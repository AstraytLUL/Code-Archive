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
	int n, m; cin >> n >> m;
	vector<int> v(n + 1, 0), p(n + 1, 0);
	map<int, int> pos;
	pos[0] = 0;
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
		p[i] = p[i - 1] + v[i];
		pos[p[i]] = i;
	}
	for(int x = 1; x <= m; ++x){
		int ans = 1e18;
		int y = p[n] - x;
		for(int i = 1; i <= n; ++i){
			if(p[i] < x) continue;
			if(pos.find(p[i] - x) == pos.end()) continue;
			int cnt = 0;
			if(pos[p[i] - x] != 0) cnt++;
			if(i != n) cnt++;
			ans = min(ans, cnt);
		}
		for(int i = 1; i <= n; ++i){
			if(p[i] < y) continue;
			if(pos.find(p[i] - y) == pos.end()) continue;
			ans = min(ans, 1ll);
		}
		if(ans == 1e18) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
