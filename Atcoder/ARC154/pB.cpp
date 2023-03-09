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
	string s, t; cin >> s >> t;
	string ts = s, tt = t;
	sort(ts.begin(), ts.end());
	sort(tt.begin(), tt.end());
	if(ts != tt) {
		cout << -1;
		return;	
	}
	string str = t + "#" + s;
	vector<int> fail(2 * n + 1, 0);
	for(int i = 1; i < 2 * n + 1; ++i){
		int cur = fail[i - 1];
		while(cur != 0 && str[i] != str[cur]) cur = fail[cur - 1];
		if(str[i] == str[cur]) fail[i] = cur + 1;
	}
	cout << n - fail[2 * n];
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
