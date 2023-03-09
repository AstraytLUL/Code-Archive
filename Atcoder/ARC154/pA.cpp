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
#define mod 998244353

int fastpow(int a, int b){
	int ret = 1;
	for(; b; b >>= 1){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
	}
	return ret;
}

void solve(){
	int n; cin >> n;
	string s, t; cin >> s >> t;
	for(int i = 0; i < n; ++i){
		if(s[i] > t[i]) swap(s[i], t[i]);
	}
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int A = 0, B = 0;
	for(int i = 0; i < n; ++i){
		A += fastpow(10, i) * (s[i] - '0'), A %= mod;
		B += fastpow(10, i) * (t[i] - '0'), B %= mod;
	}
	cout << A * B % mod;
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
