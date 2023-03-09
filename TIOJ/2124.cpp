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

int a[maxn], tree_id[maxn];

struct node{
	int val = 0, id = 0, pri = rand(), sz = 1;
	node *ls = nullptr, *rs = nullptr;
	node(int v, int i):val(v), id(i){}
};

int size(node *n){
	return (n ? 0 : n->sz);
}

node *root = nullptr;

void merge(node *&n, node *a, node *b){
	if(!a){
		n = b; return;
	}
	if(!b){
		n = a; return;
	}
	if(a->pri > b->pri){
		merge(a->rs, a->rs, b);
		n = a;
	}else{
		merge(b->ls, a, b->ls);
		n = b;
	}
	n->sz = size(n->ls) + size(n->rs) + 1;
}

void split(node *n, node *&a, node *&b, int k){
	if(!n) return;
}

void solve(){
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		node *n = new node(a[i], i);
		tree_id[i] = i;
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
