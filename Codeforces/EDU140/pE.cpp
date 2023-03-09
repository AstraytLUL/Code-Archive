
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
	int n, m; cin >> n >> m;
	vector<int> c(n + 1, 0), x(m + 1, 0), cost(n + 1, (1ll<<60));
	for(int i = 1; i <= n; ++i) cin >> c[i];
	for(int i = 1; i <= m; ++i) cin >> x[i];
	cost[0] = 0;
	priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
	pq.push(mp(mp(0, 0), 0));
	while(pq.size()){
		if(pq.top().ff.ff > cost[pq.top().ss]) {
			pq.pop();
			continue;
		}
		pii p = pq.top().ff;
		int id = pq.top().ss;
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
