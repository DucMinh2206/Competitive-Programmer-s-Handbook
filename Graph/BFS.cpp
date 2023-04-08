//#include "bits/stdc++.h"
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef stack<int> stk;
typedef vector<ll> vl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end() 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; j++)
#define ford(j ,a, b) for(int j= a; j >= b; j--)
#define ld long double

const int maxN = 1e4 + 5;
int n, a, b, visited[maxN], dis[maxN], near;
vector<int> g[maxN];

void bfs_func(int start){
    queue<int> bfs;

    dis[start] = 0;
    visited[start] = true;
    bfs.push(start);

    while(!bfs.empty()){
        int num = bfs.front();
        bfs.pop();
        cout << num << endl;

        foru(j, 0, g[num].size() - 1){
            near = g[num][j];
            if(!visited[near]){
                 bfs.push(near);
                 dis[near] = dis[num] + 1;
                 visited[near] = true;
            }

        }
    }
    return;

}

signed main(){
    IOS
    
    //freopen("dropin.txt", "r", stdin);
    //freopen("dropout.txt", "w", stdout);
    cin >> n;

    foru(j, 0, n - 1){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    bfs_func(1);

    foru(j, 1, 6) cout << dis[j] << " ";
    
}
/*
6
1 2 
2 3
2 5
3 6
5 6
1 4
*/
