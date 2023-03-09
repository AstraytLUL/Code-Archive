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

struct bit{
	int val[maxn];
	void modify(int p, int x){
		for(; p < maxn; p += (p & -p)) val[p] += x;
	}
	int query(int p){
		int ret = 0;
		for(; p; p -= (p & -p)) ret += val[p];
		return ret;
	}
}bit1, bit2;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(n), ls, id(n);
	map<int, int> cnt;
	for(auto &x:v) cin >> x, ls.pb(x), cnt[x] = 0;
	sort(ls.begin(), ls.end());
	for(int i = 0; i < n; ++i) id[i] = 1 + (lower_bound(ls.begin(), ls.end(), v[i]) - ls.begin()) + cnt[v[i]], cnt[v[i]]++;
	for(int i = 0; i < m; ++i){
		bit1.modify(id[i], v[i]);
		bit2.modify(id[i], 1);
	}
	int lb = 1, rb = n;
	while(lb != rb){
		int mid = (lb + rb) / 2;
		if(bit2.query(mid) < k) lb = mid + 1;
		else rb = mid;
	}
	cout << bit1.query(lb);
	for(int i = m; i < n; ++i){
		int j = i - m;
		bit1.modify(id[j], -v[j]);
		bit1.modify(id[i], v[i]);
		bit2.modify(id[j], -1);
		bit2.modify(id[i], 1);
		lb = 1, rb = n; 
		while(lb != rb){
			int mid = (lb + rb) / 2;
			if(bit2.query(mid) < k) lb = mid + 1;
			else rb = mid;
		}
		cout << " " << bit1.query(lb);
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
