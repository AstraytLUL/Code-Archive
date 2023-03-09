
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
	vector<int> v(m);
	for(auto &x:v) cin >> x;
	vector<int> p(n);
	for(int i = 0; i < n; ++i) p[i] = i + 1;
	int pos = -1;
	for(int i = 0; i < m; ++i){
		if(i == 0) pos = v[i];
		else if(v[i] == v[i - 1] + 1){
			continue;
		}else{
			reverse(p.begin() + pos - 1, p.begin() + v[i - 1] + 1);
			pos = v[i];
		}
	}
	if(pos != -1) reverse(p.begin() + pos - 1, p.begin() + v[m - 1] + 1);
	for(auto x:p) cout << x << ' ';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
