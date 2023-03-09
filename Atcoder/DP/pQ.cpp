#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define maxn 200005
#define ls (2 * i)
#define rs (2 * i + 1)
#define mid ((l + r) / 2)

struct SegmentTree{
	int val[maxn * 4];
	void modify(int l, int r, int i, int p, int x){
		if(l == r){
			val[i] = x;
			return;
		}
		if(p <= mid) modify(l, mid, ls, p, x);
		else modify(mid + 1, r, rs, p, x);
		val[i] = max(val[ls], val[rs]);
	}
	int query(int l, int r, int i, int ql, int qr){
		if(ql <= l && r <= qr){
			return val[i];
		}
		int ret = 0;
		if(ql <= mid) ret = max(ret, query(l, mid, ls, ql, qr));
		if(mid < qr) ret = max(ret, query(mid + 1, r, rs, ql, qr));
		return ret;
	}
}seg;

void solve(){
	int n; cin >> n;
	vector<int> dp(n, 0), h(n, 0), a(n, 0);
	for(auto &x:h) cin >> x;
	for(auto &x:a) cin >> x;
	for(int i = 0; i < n; ++i){
		dp[i] = (h[i] == 1 ? 0 : seg.query(1, n, 1, 1, h[i] - 1)) + a[i];
		seg.modify(1, n, 1, h[i], dp[i]);
	}
	cout << *max_element(dp.begin(), dp.end());
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
