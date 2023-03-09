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


signed main(){
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	int val = 0;
	for(int i = 0; i < m; ++i){
		val = (val * 41 + t[i]) % mod;
	}
	int tmp = 1;
	for(int i = 1; i <= m; ++i) tmp = tmp * 41 % mod;
	vector<pair<char, int>> stk(1, mp('a', 0));
	for(int i = 0; i < n; ++i){
		int x = (stk.back().ss * 41 + s[i]) % mod;
		stk.pb(mp(s[i], x));
		if(stk.size() > m){
			int id = stk.size() - m - 1;
			if((x - stk[id].ss * tmp % mod + mod) % mod == val){
				for(int k = 0; k < m; ++k) stk.pop_back();
			}
		}
	}
	for(int i = 1; i < stk.size(); ++i) cout << stk[i].ff;
	cout << endl;
}
