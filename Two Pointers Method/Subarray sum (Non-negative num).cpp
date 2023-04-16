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
const int maxN = 200005;
const int mod = 1e9;
const int inf = -1e9;
int n, arr[maxN], t, mex;
int i, j, sum, k, ans;
signed main(){
	IOS
    //freopen("EXP.inp", "r", stdin);
	//freopen("EXP.out", "w", stdout);
    cin >> n >> k;
    foru(j, 0, n - 1){
        cin >> arr[j];
    }
    while(i <= n - 1 && j <= n - 1){
        if(arr[j] + sum <= k){
            sum += arr[j];
            j++;

            if(sum == k) ans++;
        }
        else{
            sum -= arr[i];
            i++;
        }
        // At pos n - 1, (i or j) > n - 1.
        // If k = 0 or have negative number, the code is wrong.
    }
    cout << ans;

}    
    
	
