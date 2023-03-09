
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

struct SegmentTree{
	int node[4*maxn];
	void modify(int l, int r, int i, int p, int x){
		if(l == r){
			node[i] = x;
			return;
		}
		int mid = (l + r) / 2, ls = 2 * i, rs = 2 * i + 1;
		if(p <= mid) modify(l, mid, ls, p, x);
		else modify(mid + 1, r, rs, p, x);
		node[i] = node[ls] + node[rs];
	}
	int query(int l, int r, int i, int ql, int qr){
		if(ql <= l && r <= qr){
			return node[i];
		}
		int ret = 0, mid = (l + r) / 2, ls = 2 * i, rs = 2 * i + 1;
		if(ql <= mid) ret += query(l, mid, ls, ql, qr);
		if(mid < qr) ret += query(mid + 1, r, rs, ql, qr);
		return ret;
	}
}seg;

void solve(){
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		int ai; cin >> ai;
		seg.modify(1, n, 1, i, ai);
	}
	for(; q; q--){
		int op; cin >> op;
		if(op == 1){
			int l, r; cin >> l >> r;
			cout << seg.query(1, n, 1, l, r) << '\n';
		}else {
			int p, x; cin >> p >> x;
			seg.modify(1, n, 1, p, x);
		}
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
