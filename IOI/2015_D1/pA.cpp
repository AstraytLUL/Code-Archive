#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define All(x) x.begin(), x.end()

ll delivery(int N, int K, int L, int pos[]){
	ll ans = 0;
	vector<ll> lp, rp;
	for(int i = 0; i < N; ++i){
		if(pos[i] == 0) continue;
		if(pos[i] <= L / 2) lp.pb(pos[i]);
		else rp.pb(L - pos[i]);
	}
	reverse(rp.begin(), rp.end());
	int lN = (int) lp.size(), rN = (int) rp.size();
	vector<ll> dpl(lN + 1, 0), dpr(rN + 1, 0);
	for(int i = 1; i <= lN; ++i){
		if(i - K < 0) dpl[i] = lp[i - 1] * 2;
		else dpl[i] = dpl[i - K] + lp[i - 1] * 2;
	}
	for(int i = 1; i <= rN; ++i){
		if(i - K < 0) dpr[i] = rp[i - 1] * 2;
		else dpr[i] = dpr[i - K] + rp[i - 1] * 2;
	}
	ans = dpl[lN] + dpr[rN];
	for(int i = 0; i <= K; ++i){
		int iL = lN - i, iR = rN - K + i;
		ll lc = (iL >= 0 ? dpl[iL] : 0), rc = (iR >= 0 ? dpr[iR] : 0);
		ans = min(ans, lc + rc + 1ll * L);
	}
	return ans;
}

void solve(){
	int n, k, l; cin >> n >> k >> l;
	int pos[n];
	for(auto &x:pos) cin >> x;
	cout << delivery(n, k, l, pos) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) solve();
}
