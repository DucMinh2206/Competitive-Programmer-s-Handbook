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
const int mod = 1e9 + 7;
const int inf = -1e9;
int n, arr[maxN], sum, ans;
signed main(){
	IOS
    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    sum = inf;
    ans = inf;

    cin >> n;
    foru(j, 0, n - 1){
        cin >> arr[j];
    }
    foru(j, 0, n - 1){
        sum = max(arr[j], arr[j] + sum); // dp[k] = max(dp[k - 1] + arr[k], arr[k]);
        ans = max(ans, sum); // ans = max(ans, dp[k]);
    }
    cout << ans;
}    
    
	
// O(n)
