#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef stack<int> stk;
typedef vector<ll> vl;
typedef map<int, int> mii;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end() 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define ld long double
const int maxN = 100000;
const int inf = 1e7;
int n, m, u, v, w, a, b, c;
int dis[maxN];
vector<pair<int, int>> g[maxN];
bool visited[maxN];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minh;
    // greater do minh phai chon cac canh be(top la cai tren cung).
    foru(j, 1, n) dis[j] = inf;

    minh.push(mp(0, start)); // nguoc do sort theo priority_queue
    dis[start] = 0;

    while(!minh.empty()) {
        u = minh.top().S;
        minh.pop();
        visited[u] = true;
        //cout << u << endl;

        foru(j, 0, g[u].size() - 1){
            v = g[u][j].F;
            w = g[u][j].S;
            //cout << v << " " << w << " " << dis[v] << endl;
            if(visited[v]) continue;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                minh.push(mp(dis[v], v));
            }
        }

    }
    

}
    
int main(){
    IOS
    cin >> n >> m;
    foru(j, 0, m - 1){
        cin >> a >> b >> c;
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }

   dijkstra(1);
   cout << dis[n];
    
}
