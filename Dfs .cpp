#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
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
int n, a, b, visited[maxN];
vector<int> g[maxN];
void dfs(int s){
    if(visited[s])return;

    visited[s] = true;
    //cout << s << endl;
    foru(j, 0, g[s].size() - 1){
        dfs(g[s][j]);
    }

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
    dfs(1);

}