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

ll R[1005][1005], G[1005][1005], B[1005][1005], C[1005][1005];

void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; ++i){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		if(x1 == x2 || y1 == y2) continue;
		int r, g, b; cin >> r >> g >> b;
		for(int i = x1; i < x2; ++i){
			R[i][y1] += r, R[i][y2] -= r;
			B[i][y1] += b, B[i][y2] -= b;
			G[i][y1] += g, G[i][y2] -= g;
			C[i][y1]++, C[i][y2]--;
		}
	}
	unordered_map<ll, ll> cnt;
	int cntmx = 0;
	int ar = 0, ag = 0, ab = 0;
	for(int i = 0; i <= 1000; ++i){
		for(int j = 1; j <= 1000; ++j){
			C[i][j] += C[i][j - 1];
			R[i][j] += R[i][j - 1];
			G[i][j] += G[i][j - 1];
			B[i][j] += B[i][j - 1];
		}
		for(int j = 0; j <= 1000; ++j){
			if(C[i][j] == 0) continue;
			R[i][j] = ceil(1.0 * R[i][j] / C[i][j]);
			G[i][j] = ceil(1.0 * G[i][j] / C[i][j]);
			B[i][j] = ceil(1.0 * B[i][j] / C[i][j]);
			cnt[R[i][j] *  1000000 + 1000 * G[i][j] + B[i][j]]++;
			if(cnt[R[i][j] * 1000000 + 1000 * G[i][j] + B[i][j]] > cntmx){
				cntmx = cnt[R[i][j] * 1000000 + 1000 * G[i][j] + B[i][j]];
				ar = R[i][j], ag = G[i][j], ab = B[i][j];
			}
		}
	}
	cout << ar << ' ' << ag << ' ' << ab << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
