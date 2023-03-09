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
	vector<int> v(n);
	for(auto &x:v) cin >> x;
	stack<int> stk;
	int ans = 0;
	for(auto x:v){
		if(stk.empty()) stk.push(x);
		else{
			if(stk.top() > x) stk.push(x);
			else {
				while(stk.size() && stk.top() <= x){
					stk.pop();
					ans += (stk.size() ? min(x, stk.top()) : x);
				}
				stk.push(x);
			}
		}
	}
	while(stk.size()){
		stk.pop();
		int k = 0;
		if(stk.size()) k = stk.top();
		ans += k;
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
