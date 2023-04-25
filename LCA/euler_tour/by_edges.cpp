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
bool visited[maxN];
vector<int> tour;
void dfs(int s){
	tour.push_back(s);
	for(int j = 0; j + 1 <= g[s].size(); j++){
		int v = g[s][j];
		if(visited[v]) continue;

		visited[v] = true;
		dfs(v);

		tour.push_back(s);
	}
	
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
	dfs(1);

	foru(j, 0, tour.size() - 1) cout << tour[j] << " ";


	// auto stop = high_resolution_clock::now();
	// auto diff = stop - start;
	// cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

// 1 2 4 2 5 2 1 3 1
}
