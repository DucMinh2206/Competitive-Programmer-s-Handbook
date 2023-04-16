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
int n, arr[maxN], sum, ans, target, i, j;
map<int, vector<int>> pos;
signed main(){
	IOS
    //freopen("EXP.inp", "r", stdin);
	//freopen("EXP.out", "w", stdout);
  
    cin >> n >> target;
    foru(j, 1, n){

        cin >> arr[j];
        pos[arr[j]].push_back(j);
    }
    
    sort(arr, arr + n + 1);
    if(target <= arr[0]) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    i = 1;
    j = n;
    
    while(j > i && i != j){
        sum = arr[i] + arr[j];
        
        if(sum > target){
            sum -= arr[j];
            j--;
        }
        else if(sum < target){
            sum -= arr[i];
            i++;
        }
        else {
            if(arr[i] == arr[j]) cout << pos[arr[i]][0] << " " << pos[arr[j]][1];
            else cout << pos[arr[i]][0] << " " << pos[arr[j]][0];

            return 0; 
        }
    }
    cout << "IMPOSSIBLE";
}

//https://cses.fi/problemset/task/1640
   
