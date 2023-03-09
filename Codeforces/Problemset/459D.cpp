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
#define maxn 1000005
#define mod 1000000007

struct FenwickTree{
	int val[maxn];
	void modify(int p, int x){
		for(; p < maxn; p += (p & -p)) val[p] += x;
	}
	int query(int p){
		int ret = 0;
		for(; p; p -= (p & -p)) ret += val[p];
		return ret;
	}
}BIT;

void solve(){
	int n; cin >> n;
	vector<int> a(n), b;
	for(auto &x:a) cin >> x;
	b = a;
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
	vector<int> f1(n + 1, 0), f2(n + 1, 0);
	for(int i = 0; i < n; ++i){
		a[i] = 1 + (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
		cnt1[a[i]]++;
		f1[i] = cnt1[a[i]];
	}
	for(int i = n - 1; i > 0; --i){
		cnt2[a[i]]++;
		f2[i] = cnt2[a[i]];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += i - BIT.query(f2[i]);
		BIT.modify(f1[i], 1);
	}
	cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
