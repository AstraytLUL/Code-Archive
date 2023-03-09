
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
	int n; cin >> n;
	vector<int> a(n + 1, 0), b(n + 1, 0), p(n + 1, 0);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int j = 1; j <= n; ++j) cin >> b[j], p[j] = p[j - 1] + b[j];
	vector<int> ans(n + 1, 0), bound(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		int l = i - 1, r = n;
		while(l != r){
			int mid = (l + r) / 2 + 1;
			if(p[mid] - p[i - 1] > a[i]) r = mid - 1;
			else l = mid;
		}
		if(l == i - 1){
			ans[i] += a[i];
			a[i] = 0;
			continue;
		}
		bound[i] = l;
		a[i] -= p[l] - p[i - 1];
		if(l != n) ans[l + 1] += a[i];
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 1; i <= n; ++i){
		if(bound[i] != 0){
			pq.push(mp(bound[i], i));
		}
		int sz = pq.size();
		ans[i] += sz * b[i];
		while(pq.size() && pq.top().ff == i){
			pq.pop();
		}
	}
	for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
