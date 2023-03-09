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
#define maxn 300005
#define mod 998244353

int fac[maxn], inv[maxn];

int fastpow(int a, int b){
	int ret = 1;
	for(; b; b >>= 1){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
	}
	return ret;
}

int C(int n, int m){
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve(){
	int n; cin >> n;
	fac[0] = inv[0] = 1;
	vector<int> w(n);
	for(int i = 0; i < n; ++i){
		cin >> w[i];
		fac[i + 1] = fac[i] * (i + 1) % mod;
		inv[i + 1] = fastpow(fac[i + 1], mod - 2);
	}
	int ans = 1;
	for(int i = 0; i < n; i += 3){
		int a = w[i] + w[i + 1], b = w[i + 1] + w[i + 2], c = w[i] + w[i + 2];
		int mx = max({a, b, c}), cnt = 0;
		for(auto x:{a, b, c}){
			if(x == mx) cnt++;
		}
		ans = ans * cnt % mod;
	}
	ans = ans * C(n / 3, n / 6) % mod;
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
