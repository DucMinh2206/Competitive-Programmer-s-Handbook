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

const int maxN = 2e5 + 5;
const int mod = 2e9;
const int inf = 1e6;


int n;
vector<int> g[maxN];
vector<pair<int, int>> tour;
bool visited[maxN];
pair<int, int> sparse_tb[22][maxN];

int log_2(int value){
	return 31 - __builtin_clz(value);
}

void dfs(int s, int depth){
	tour.push_back(mp(depth, s));
	for(int j = 0; j + 1 <= g[s].size(); j++){
		int v = g[s][j];
		if(visited[v]) continue;

		visited[v] = true;
		dfs(v, depth + 1);

		tour.push_back(mp(depth, s));
	}
	
}
void build(){
	foru(j, 0, tour.size() - 1){
		sparse_tb[0][j] = tour[j];
	}

	int sai = tour.size();
	foru(i, 1, 10){
		if(i + (1 << (i - 1)) > sai - 1) break;

		foru(j, 0, sai - 1){
			sparse_tb[i][j] = min(sparse_tb[i - 1][j], sparse_tb[i - 1][j + (1 << (i - 1))]);
		}
	}

}
int get_LCA(int l, int r){
	int luy_thua = log_2(r - l + 1);
	pair<int, int> x = min(sparse_tb[luy_thua][l], sparse_tb[luy_thua][r - luy_thua + 1]);
   return x.second;
}

signed main(){
	IOS
    //freopen("PANDA.inp", "r", stdin);
	//freopen("PANDA.out", "w", stdout);
	//auto start = high_resolution_clock::now();

	cin >> n;
	for(int j = 1; j + 1 <= n; j++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	visited[1] = true;
	dfs(1, 0);
	build();
	cout << get_LCA(4, 5);
	
	return 0;

	// auto stop = high_resolution_clock::now();
	// auto diff = stop - start;
	// cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

}
