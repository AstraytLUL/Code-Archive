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
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 2000005
#define mod 1000000007

void solve(){
	string s; cin >> s;
	if(s.size() != 8) {
		cout << "No\n";
		return;
	}
	bool ok = 1;
	if(!('A' <= s[0] && s[0] <= 'Z')) ok = 0;
	if(!('A' <= s[7] && s[7] <= 'Z')) ok = 0;
	int k = 0;
	for(int i = 1; i < 7; ++i){
		k *= 10;
		k += (s[i] - '0');
	}
	if(!(k >= 100000 && k <= 999999)) ok = 0;
	cout << (ok ? "Yes\n" : "No\n");
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
