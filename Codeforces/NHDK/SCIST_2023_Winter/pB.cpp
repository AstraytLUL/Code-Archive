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
	string a, b, c; cin >> a >> b >> c;
	string ans = "";
	for(int i = 0; i < (int) a.size(); i++){
		int x = a[i] - '0', y = b[i] - '0', ok = 0;
		for(auto z:{0, 1}){
			if(c[i] == '^' && ((x ^ z) == y)){
				ans += (char)(z + '0');
				ok = 1; break;
			}else if(c[i] == '&' && ((x & z) == y)){
				ans += (char)(z + '0');
				ok = 1; break;
			}
		}
		if(!ok) ans += "X";
	}
	cout << ans;
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}