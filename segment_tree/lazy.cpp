#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define forp(j, a, b) for(int j = a; j + 1 <= b; ++j)

const int maxN = 1e5 + 5;
const int mod = 2e9;
const int inf = 330;
#define int ll
int n, q;
int st[maxN * 4], arr[maxN], lazy[maxN * 4];
void build(int id, int l, int r){
	if(l == r){
		st[id] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;

	build(id * 2, l , mid);
	build(id * 2 + 1, mid + 1, r);

	st[id] = st[id * 2] + st[id * 2 + 1];

}
void push(int id, int l, int r){
	if(!lazy[id]) return;

	st[id] = lazy[id];

	//if not leaf
	if(l != r){
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
	}	

	lazy[id] = 0;

} 

void update(int id, int l, int r, int i, int value){
	push(id, l, r);
	if(i > r || i < l) return;

	if(l == r){
		lazy[id] = value;
		push(id, l, r);
		return; 
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, i, value);
	update(id * 2 + 1, mid + 1, r, i, value);

	st[id] = st[id * 2] + st[id * 2 + 1];

}

int get_value(int id, int l, int r, int ql, int qr){
	if(l > qr || r < ql) return 0;

	if( ql <= l && r <= qr){
		return st[id];
	}
	int mid = (l + r) >> 1;
	return get_value(id * 2, l, mid, ql, qr) + get_value(id * 2 + 1, mid + 1, r, ql, qr);
}
signed main(){
	IOS
    //freopen("PANDA.inp", "r", stdin);
	//freopen("PANDA.out", "w", stdout);
	cin >> n >> q;
	foru(j, 1, n) arr[j] = 0;

	build(1, 1, n);

	foru(j, 0, q - 1){
		int type;
		cin >> type;

		if(type == 1){
			int value, pos;
			cin >> pos >> value;
			update(1, 1, n, pos, value);

		}
		else{
			int l, r;
			cin >> l >> r;
			cout << get_value(1, 1, n, l, r) << endl;

		}
	}

}



