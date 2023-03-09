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
	string a, b; cin >> a >> b;
	int n = a.size(), m = b.size();
	if(a[0] == b[0]){
		cout << "YES\n";
		cout << a[0] << "*\n";
		return;
	}else if(a[n - 1] == b[m - 1]){
		cout << "YES\n";
		cout << "*" << a[n - 1] << "\n";
		return;
	}
	if(n > m){
		swap(a, b);
		swap(n, m);
	}
	for(int l = 0; l + 1 < n; ++l){
		for(int i = 0; i + 1 < m; ++i){
			if(a[l] == b[i] && a[l + 1] == b[i + 1]){
				cout << "YES\n*" << a[l] << a[l + 1] << "*\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
