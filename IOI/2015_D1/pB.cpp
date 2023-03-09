#include <bits/stdc++.h>
#include "scales.h"
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define All(x) x.begin(), x.end()

vector<int> adj[7];
int t, deg[7];

void init(int T){
	t = T;
   	for(int i = 1; i <= 6; ++i) deg[i] = 0;
}

void orderCoins(){
   	for(int i = 1; i <= 6; ++i){
   		adj[i].clear();
   	}
	int a = getHeaviest(1, 2, 3), b = getMedian(1, 2, 3);
   	for(int i = 1; i <= 6; ++i){
   		for(int j = i + 1; j <= 6; ++j){
   			for(int k = j + 1; k <= 6; ++k){
   				int a = getHeaviest(i, j, k), b = getMedian(i, j, k), c;
   				if((a == i && b == j) || (a == j && b == i)) c = k;
   				else if((a == i && b == k) ||( a == k && b == i)) c = j;
   				else c = i;
   				adj[a].pb(b), adj[b].pb(c);
   				deg[b]++, deg[c]++;
   			}
   		}
   	}
   	queue<int> bfs;
   	vector<int> top;
	for(int i = 1; i <= 6; ++i){
   		if(deg[i] == 0) bfs.push(i);
	}
	while(bfs.size()){
		int u = bfs.front();
		bfs.pop();
		top.pb(u);
		for(auto v:adj[u]){
			deg[v]--;
			if(deg[v] == 0) bfs.push(v);
		}
	}
	reverse(top.begin(), top.end());
	int ans[6];
	for(int i = 0; i < 6; ++i) ans[i] = top[i];
	answer(ans);
	return;
}
