#include <bits/stdc++.h>
using namespace std;
#define starbrust ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define maxn 

set<int> adj[maxn];

void Solve(int N){
	for(int i = 1; i <= 2 * N; ++i){
		for(int j = i + 1; j <= 2 * N; ++j){
			vector<int> v(2, 0);
			v[0] = i, v[1] = j;
			if(Query(v) == 1) adj[i].insert(j);
		}
	}
	for(int i = 1; i <= 2 * N; ++i){
		for(int j = i + 1; j <= 2 * N; ++j){
			if(adj[i].find(j) != adj[i].end() && adj[j].find(i) != adj[j].end()) Answer(i, j);
		}
	}
}

signed main(){
	starburst
	int t = 1; //cin >> t;
	while(t--) solve();
}
