
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
	int ans; cin >> ans;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i < n; ++i){
		int x; cin >> x;
		pq.push(x);
	}
	while(pq.size()){
		while(pq.size() && pq.top() <= ans) pq.pop();
		if(pq.size() == 0) break;
		int k = ans + pq.top();
		pq.pop();
		if(k & 1) ans = k / 2 + 1;
		else ans = k / 2;
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
