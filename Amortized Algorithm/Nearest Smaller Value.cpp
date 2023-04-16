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
int n, arr[maxN], x;
int ans[maxN];
signed main(){
	IOS
    //freopen("EXP.inp", "r", stdin);
	//freopen("EXP.out", "w", stdout);
    stack<int> num;
    cin >> n;

    foru(j, 1, n){
        cin >> arr[j];
    }
    ans[1] = -1; num.push(arr[1]);

    foru(j, 2, n){
        while(!num.empty() && num.top() >= arr[j]){
            num.pop();
        }    
        if(num.empty()) ans[j] = -1;
        else  ans[j] = num.top();

        num.push(arr[j]);
    }
    
    foru(j, 1, n){
        cout << ans[j] << endl;
    }
    
}
// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1
