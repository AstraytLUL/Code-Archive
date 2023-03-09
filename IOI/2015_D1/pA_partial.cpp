#include <bits/stdc++.h>
using namespace std;

ll delivery(int N, int K, int L, int pos[]){
	if(K == 1){
		long long ret = 0;
		for(int i = 0; i < N; ++i){
			int dist = min(pos[i], L - pos[i]);
			ret += 2ll * dist;
		}
		return ret;
	}
}
