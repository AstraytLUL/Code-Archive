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
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 600005
#define mod 1000000007

struct shop{
    int x, y, r, w;
};

struct query{
    int l, r, w, t;
};

struct SegmentTree{
    int val[4 * maxn], tag[4 * maxn];
    inline void push(int i){
        int ls = 2 * i, rs = 2 * i + 1;
        tag[ls] += tag[i], tag[rs] += tag[i];
        val[ls] += tag[i], val[rs] += tag[i];
        tag[i] = 0;
    }
    void modify(int l, int r, int ql, int qr, int i, int x){
		if(ql > qr) return;
        if(ql <= l && r <= qr){
            tag[i] += x;
            val[i] += x;
            return;
        }
        push(i);
        int mid = (l + r) / 2, ls = 2 * i, rs = 2 * i + 1;
        if(ql <= mid) modify(l, mid, ql, qr, ls, x);
        if(mid < qr) modify(mid + 1, r, ql, qr, rs, x);
        val[i] = max(val[ls], val[rs]);
    }
}seg;

void solve(){
    int n, h = 0; cin >> n;
    vector<shop> v(n);
    vector<query> Q(2 * n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].x >> v[i].y >> v[i].r >> v[i].w;
        h = max(h, v[i].x + v[i].r + v[i].y);
    }
    vector<int> ls(2 * n, 0), ls2(2 * n, 0);
    for(int i = 0; i < n; ++i){
        Q[i].t = v[i].x + v[i].y - v[i].r;
        Q[i + n].t = v[i].x + v[i].y + v[i].r + 1;
        // y = x + xi - r
        // y = -x + h
        Q[i].l = Q[i + n].l = h + v[i].y - v[i].x + v[i].r;
        Q[i].r = Q[i + n].r = h + v[i].y - v[i].x - v[i].r;
		if(Q[i].l % 2) Q[i].l++, Q[i + n].l++;
		if(Q[i].r % 2) Q[i].r--, Q[i + n].r--;
        Q[i].w = v[i].w;
        Q[i + n].w = -v[i].w;
        ls[i] = Q[i].l, ls[i + n] = Q[i].r;
        ls2[i] = Q[i].t; ls2[i + n] = Q[i + n].t;
    }
    sort(Q.begin(), Q.end(), [](query a, query b){return a.t < b.t;});
    sort(ls.begin(), ls.end());
    sort(ls2.begin(), ls2.end());
    ls.resize(unique(ls.begin(), ls.end()) - ls.begin());
    ls2.resize(unique(ls2.begin(), ls2.end()) - ls2.begin());
    for(int i = 0; i < 2 * n; ++i){
        Q[i].t = 1 + (lower_bound(ls2.begin(), ls2.end(), Q[i].t) - ls2.begin());
        Q[i].l = 1 + (lower_bound(ls.begin(), ls.end(), Q[i].l) - ls.begin());
        Q[i].r = 1 + (lower_bound(ls.begin(), ls.end(), Q[i].r) - ls.begin());
        swap(Q[i].l, Q[i].r);
    }
    int ans = 0, m = ls.size();
    for(int i = 0, j = 0; i < 2 * n; i = j){
        while(j < 2 * n && Q[j].t == Q[i].t){
            seg.modify(1, m, Q[j].l, Q[j].r, 1, Q[j].w);
            j++;
        }
        ans = max(ans, seg.val[1]);
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
