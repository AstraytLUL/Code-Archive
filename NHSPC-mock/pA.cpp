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
	int n, L; cin >> n >> L;
	vector<int> w(n), mxL(n);
	for(int i = 0; i < n; ++i) cin >> w[i];
	sort(w.begin(), w.end());
	reverse(w.begin(), w.end());
	double ans = 0;
	vector<double> x(n, 0.0);
	x[0] = 1.0 * L
	double sump = 1.0 * w[0] * x[0], sumw = w[0];
	for(int i = 1; i < n; ++i){
		sumw += w[i];
		double d = 1.0 * sumw * L / 2.0 - sump;
		cout << d << ' ';
		x[i] = d / (1.0 * w[i]);
		ans += x[i];
		sump += 1.0 * w[i] * x[i];
	}
	ans += x[0];
	for(auto a:x) cout << a << ' ';
	cout << fixed << setprecision(9) << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
