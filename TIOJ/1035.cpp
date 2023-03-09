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
	string s, t; cin >> s >> t;
	string str = s + "$" + t;
	int n = str.size(), ans = 0;
	vector<int> fail(n, 0);
	for(int i = 1; i < n; ++i){
		int cur = fail[i - 1];
		while(cur != 0){
			if(str[cur] != str[i]) cur = fail[cur];
			else break;
		}
		if(str[cur] == str[i]) fail[i] = cur + 1;
		else fail[i] = cur;
	}
	cout << fail[n - 1] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
