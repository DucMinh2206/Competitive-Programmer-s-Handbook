#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define forp(j, a, b) for(int j = a; j + 1 <= b; ++j)
#define endl '\n'
const int maxN = 100;
const int mod = 2e9;
const int inf = 1e7;

int parent[maxN]; // for tracing the augmenting path..
vector<int> g[maxN];
int capacity[maxN][maxN]; // maximum flow
int n, m, min_capa;
int BFS(int s, int t){
    memset(parent, -1, sizeof(parent));
    parent[s] = -2;

    queue<pair<int, int>> bfs;
    bfs.push(mp(s, inf)); // first for node and second for the minimum of the maximum flow can throw in 

    while(!bfs.empty()){
        int u = bfs.front().first;
        int flow = bfs.front().second;
        bfs.pop();

        for(int j = 0; j + 1 <= int(g[u].size()); ++j){
            int v = g[u][j];
            if(parent[v] == -1 && capacity[u][v]){
                min_capa = min(capacity[u][v], flow);
                parent[v] = u;

                if(v == t){
                    return min_capa;
                }
                bfs.push(mp(v, min_capa));                
            }
        }

    }
    return 0;
}
int max_flow(int s, int t){
    int previous, value, sum = 0, the_next;
    while((value = BFS(s, t))){
        sum += value;
        //cout << value << endl; 
        the_next = t;
        // the_next != s because if we choose previous, there is one edge is not updated.
        while(the_next != s){
            previous = parent[the_next];
            capacity[previous][the_next] -= value;
            capacity[the_next][previous] += value;
            // error
            the_next = previous;
        }
    }
    return sum;
}

signed main(){
    cin >> n >> m;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        capacity[a][b] = c; 
        capacity[b][a] = 0;
    }
    cout << max_flow(1, 6);


}
