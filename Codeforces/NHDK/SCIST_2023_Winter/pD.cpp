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
	string op;
	queue<string> customer;
	stack<int> pancake[1005];
	while(cin >> op){
		if(op == "customer"){
			string name; cin >> name;
			customer.push(name);
		}
		else if(op == "pancake"){
			int id, num; cin >> id >> num;
			pancake[id].push(num);
		}
		else if(op == "sell"){
			int id; cin >> id;
			if(customer.size() == 0){
				cout << "no customer\n"; continue;
			}else if(pancake[id].empty()){
				cout << "sold out\n"; continue;
			}else{
				cout << pancake[id].top() << ' ' << customer.front() << '\n';
				pancake[id].pop();
				customer.pop();
			}
		}else {
			break;
		}
	}
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
