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
	string s; cin >> s;
	int n = s.size();
	stack<int> stk;
	for(int i = 0; i < n; ++i){
		if(s[i] == '0') stk.push(0);
		if(s[i] == '1') stk.push(1);
		if(s[i] == 'B' && stk.size()) stk.pop();
	}	
	string ans = "";
	while(stk.size()){
		if(stk.top()) ans += "1";
		else ans += "0";
		stk.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
