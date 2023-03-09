
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

const int inf = 1e9;

void solve(){
	int n, ans = 0; cin >> n;
	vector<pii> v(n);
	set<pii> st;
	for(auto &[x, y]:v) cin >> x >> y, st.insert(mp(x, y));
	for(auto [x, y]:st){
		int cnt1 = 1, cnt2 = 1, cnt3 = 1, cnt4 = 1;
		int f1 = 1, f2 = 1, f3 = 1, f4 = 1;
		for(int i = 1; i <= 1000; ++i){
			if(st.find(mp(x + i, y + i)) == st.end()){
				f1 = 0;
			}else if(f1) cnt1++;
			if(st.find(mp(x + i, y)) == st.end()){
				f2 = 0;
			}else if(f2) cnt2++;
			if(st.find(mp(x + i, y - i)) == st.end()){
				f3 = 0;
			}else if(f3) cnt3++;
			if(st.find(mp(x, y + i)) == st.end()){
				f4 = 0;
			}else if(f4) cnt4++;
			if(cnt1 > 1) ans = max(ans, cnt1);
			if(cnt2 > 1) ans = max(ans, cnt2);
			if(cnt3 > 1) ans = max(ans, cnt3);
			if(cnt4 > 1) ans = max(ans, cnt4);
		}
	}
	cout << ans;
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
