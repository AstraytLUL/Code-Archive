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
	int n, c, q; cin >> n >> c >> q;
	vector<int> v(n + 1), used(n + 1, 0);
	int tot = 0;
	for(int i = 1; i <= n; ++i){
		cin >> v[i], tot += v[i];
	}
	int sz = tot / c, rem = tot % c;
	set<pii> use;
	set<pii, greater<pii>> nouse;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(use.size() < sz){
			used[i] = 1;
			use.insert(mp(v[i], i));
			continue;
		}
		if(use.size() && v[i] > (*use.begin()).ff){
			auto [val, id] = (*use.begin());
			use.erase(use.begin());
			nouse.insert(mp(val, id));
			use.insert(mp(v[i], i));
			ans += val;
			used[id] = 0;
			used[i] = 1;
		}else{
			nouse.insert(mp(v[i], i));
			ans += v[i];
		}
	}
	cout << ans - (rem == 0 ? 0 : min(rem, (*nouse.begin()).ff)) << '\n';
	for(; q; q--){
		int x, val; cin >> x >> val;
		tot = tot - v[x] + val, sz = tot / c, rem = tot % c;
		if(used[x]){
			use.erase(use.find(mp(v[x], x)));
			ans += val, used[x] = 0;
		}else{
			nouse.erase(nouse.find(mp(v[x], x)));
			ans -= v[x], ans += val;
		}
		nouse.insert(mp(val, x));
		v[x] = val;
		while(use.size() > sz){
			auto [ev, id] = (*use.begin());
			ans += ev;
			used[id] = 0;
			use.erase(use.begin());
			nouse.insert(mp(ev, id));
		}
		while(use.size() < sz){
			auto [nv, id] = (*nouse.begin());
			used[id] = 1;
			ans -= nv;
			nouse.erase(nouse.begin());
			use.insert(mp(nv, id));
		}
		while(use.size() && nouse.size() && (*use.begin()).ff < (*nouse.begin()).ff){
			pii p1 = *use.begin(), p2 = *nouse.begin();
			ans -= p2.ff, ans += p1.ff;
			use.erase(use.begin()); nouse.erase(nouse.begin());
			use.insert(p2); nouse.insert(p1); 
			used[p1.ss] = 0, used[p2.ss] = 1;
		}
		cout << ans - (rem == 0 ? 0 : min(rem, (*nouse.begin()).ff)) << '\n';
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}


