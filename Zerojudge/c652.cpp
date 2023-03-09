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
#define mod 1000000007
#define ls (2*i)
#define rs (2*i+1)
#define mid ((l+r)/2)

struct SegmentTree{
	int val[maxn*4], all_one[maxn*4];
	void give_val(int l, int r, int i, int p, int x){
		if(l == r){
			val[i] = x;
			if(val[i] == 1) all_one[i] = 1;
			return;
		}
		if(p <= mid) give_val(l, mid, ls, p, x);
		else give_val(mid + 1, r, rs, p, x);
		val[i] = val[ls] + val[rs];
		all_one[i] = all_one[ls] & all_one[rs];
	}
	void modify(int l, int r, int i, int ql, int qr){
		if(l == r){
			val[i] = sqrt(val[i]);
			all_one[i] = (val[i] == 1ll);
			return;
		}
		if(all_one[i]) return;
		if(ql <= mid) modify(l, mid, ls, ql, qr);
		if(mid < qr) modify(mid + 1, r, rs, ql, qr);
		val[i] = val[ls] + val[rs];
		all_one[i] = (all_one[ls] & all_one[rs]);
	}
	int query(int l, int r, int i, int ql, int qr){
		if(ql <= l && r <= qr){
			return val[i];
		}
		int ret = 0;
		if(ql <= mid) ret += query(l, mid, ls, ql, qr);
		if(mid < qr) ret += query(mid + 1, r, rs, ql, qr);
		return ret;
	}
}seg;

void solve(){
	int n, q; cin >> n >> q;
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; ++i) cin >> a[i], seg.give_val(1, n, 1, i, a[i]);
	for(; q; q--){
		int op, l, r; cin >> op >> l >> r;
		if(op == 0){
			cout << seg.query(1, n, 1, l, r) << '\n';
		}else{
			seg.modify(1, n, 1, l, r);
		}
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
