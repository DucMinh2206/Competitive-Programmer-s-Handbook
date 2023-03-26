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

const int maxN = 1e3 + 5;
const int INF = 1e9;
int grid[maxN][maxN], n, m, x, y, replace;
bool used[maxN][maxN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void floodfill(int x, int y, int current){
    if(x > n - 1 || y > m - 1 || x < 0 || y < 0 || used[x][y] || grid[x][y] != current) return;

    grid[x][y] = 10;

    foru(j, 0, 3){
        floodfill(x + dx[j], y + dy[j], current);
    }
    return;
}

signed main(){
    IOS
    
    //freopen("dropin.txt", "r", stdin);
    //freopen("dropout.txt", "w", stdout);
    cin >> n >> m >> x >> y;
    foru(i, 0, n - 1){
        foru(j, 0, m - 1){
            cin >> grid[i][j];
        }
    }

    floodfill(x, y, grid[x][y]);

    foru(i, 0, n - 1){
        foru(j, 0, m - 1){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
}
/*
4 4 1 2
1 1 0 0
2 3 2 2
3 2 2 2
1 1 1 1
*/