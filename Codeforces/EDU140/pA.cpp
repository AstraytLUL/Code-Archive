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

void solve(){
	pii p[3];
	for(auto &[x, y]:p) cin >> x >> y;
	bool ok = 1;
	sort(p, p + 3);
	if(p[0].ff == p[1].ff && (p[0].ss == p[2].ss || p[1].ss == p[2].ss)) ok = 0;
	if(p[1].ff == p[2].ff && (p[0].ss == p[1].ss || p[0].ss == p[2].ss)) ok = 0;
	cout << (ok ? "YES" : "NO") << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
