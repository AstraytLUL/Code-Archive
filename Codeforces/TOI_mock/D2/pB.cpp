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
	int n, m, l, e; cin >> n >> m >> l >> e;
	vector<int> x(n + 1, 0), t(n + 1, 0);
	for(int i = 1; i <= n; ++i) cin >> x[i] >> t[i];
	double lb = 0, rb = 1e18;
	x.pb(0); t.pb(e);
	while(abs(rb - lb) / max((double)(1.0), min(lb, rb)) > 1e-12){
		double mid = (lb + rb) / 2;
		int lap = 0;
		bool ok = 1;
		for(int i = 1; i <= n + 1; ++i){
			double rem = (x[i] >= x[i - 1] ? x[i] - x[i - 1] : l - x[i - 1] + x[i]);
			if(rem / (t[i] - t[i - 1]) > mid){
				ok = 0;
				break;
			}
			if(lap >= m) continue;
			if(x[i] < x[i - 1]) lap++;
			double v = mid - rem / (t[i] - t[i - 1]), tmp = (double) (t[i] - t[i - 1]) / (double)l;
			lap += floor(v * tmp);
		}
		if(ok && lap >= m) rb = mid;
		else lb = mid + 1e-9;
	}
	cout << fixed << setprecision(9) << lb << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}

