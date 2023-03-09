#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define maxn 200005
#define mid ((l+r)/2)
#define ls (2*i)
#define rs (ls+1)

struct SegmentTree{
	struct Node{
		int pre, suf, sum, mx;
	}node[maxn * 4];
	void update(int x, int i){
		node[i].pre = node[i].suf = node[i].sum = node[i].mx = x;
	}
	void pull(Node &cur, Node L, Node R){
		cur.pre = max(L.pre, L.sum + R.pre);
		cur.suf = max(R.suf, R.sum + L.suf);
		cur.sum = L.sum + R.sum;
		cur.mx = max(max(L.mx, R.mx), L.suf + R.pre);
	}
	void modify(int l, int r, int i, int p, int x){
		if(l == r){
			update(x, i);
			return;
		}
		if(p <= mid) modify(l, mid, ls, p, x);
		else modify(mid + 1, r, rs, p, x);
		pull(node[i], node[ls], node[rs]);
	}
}seg;

void solve(){
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		seg.modify(1, n, 1, i, x);
	}
	for(; q; q--){
		int k, x; cin >> k >> x;
		seg.modify(1, n, 1, k, x);
        cout << max(0ll, seg.node[1].mx) << '\n';
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}

