
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
	vector<vector<int>> v(m);
	for(auto &st:v){
		int c; cin >> c;
		st.assign(c, 0);
		for(auto &x:st) cin >> x;
	}
	int ans = 0;
	for(int i = 0; i < (1<<m); ++i){
		set<int> st;
		for(int j = 0; j < m; ++j){
			if(i & (1<<j)){
				for(auto x:v[j]) st.insert(x);
			}
		}
		if(st.size() == n) ans++;
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
