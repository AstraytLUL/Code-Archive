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
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 2000005
#define mod 1000000007

void solve(){
	int n, m, q; cin >> n >> m >> q;
	int mx = -1, cnt = 0;
	vector<int> v(n), cc(maxn, 0);
	for(auto &x:v) {
		cin >> x;
		mx = max(mx, x);
		cc[x]++;
		if(x == m) cnt++;
	}
	sort(v.begin(), v.end());
	vector<int> ans(mx + 1, 0);
	for(int i = 2; i <= mx; ++i){
		for(int j = m; j <= mx; j += (i - 1)){
			int k = j, t = 0;
			while(k) t += k % i, k /= i;
			if(t == m) ans[i] += cc[j];
		}
	}
	for(; q; q--){
		int b; cin >> b;
		if(b > mx){
			cout << cnt << '\n';
			continue;
		}
		cout << ans[b] << '\n';
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
