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
		if(b & 1) ret *= a, ret %= mod;
		a *= a, a %= mod;
	}
	return ret;
}

int fac[205], inv[205];

void solve(){
	int l, r; cin >> l >> r;
	int k = 0, ans = 0;
	while(l * (1<<k) <= r) k++;
	cout << k << ' ';
	k--;
	for(int pw2 = k; pw2 >= 0; --pw2){
		int pw3 = k - pw2, x = fastpow(2, pw2) * fastpow(3, pw3);
		if(l * x > r) break;
		int lb = l - 1, rb = r;
		while(lb != rb){
			int mid = 1 + (lb + rb) / 2;
			if(mid * x > r) rb = mid - 1;
			else lb = mid;
		}
		int add = lb - l + 1;
		add = add * fac[k] % mod * inv[pw2] % mod * inv[pw3] % mod;
		ans = (ans + add) % mod;
	}
	cout << ans << '\n';
}

signed main(){
    starburst
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= 200; ++i){
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = fastpow(fac[i], mod - 2);
	}
    int t = 1; cin >> t;
    while(t--) solve();
}
