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
	int n; cin >> n;
	string s; cin >> s;
	vector<int> pos;
	for(int i = 1; i <= n; ++i){
		if(s[i - 1] == '1') pos.pb(i);
	}
	int sz = pos.size();
	if(pos.size() & 1) {
		cout << -1 << '\n';
		return;
	}
	if(s == "110" || s == "011") {
		cout << -1 << '\n';
		return;
	}
	if(s == "0110"){
		cout << 3 << '\n';
		return;
	}
	int cnt = 0;
	for(int i = 0; i < sz / 2; ++i) {
		int j = i + sz / 2;
		if(pos[i] + 1 == pos[j]) cnt++;
	}
	cout << cnt + sz / 2 << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
