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
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define ld long double

const int maxN = 1e8;
int n, num, max_num;
vector<int> number;
int arr[maxN], output[maxN];
int main() {
      //freopen("1.inp", "r", stdin);
      //freopen("1.out", "w", stdout);
    cin >> n;
    foru(j, 0, n - 1){
        cin >> arr[j];
        max_num = max(max_num, arr[j]);
    }

    int counting[max_num + 1];
    memset(counting, 0, sizeof(counting));
    foru(j, 0, n - 1){
        counting[arr[j]]++;
    }

    // To place right position for smaller value element.
    foru(j, 1, max_num){
        counting[j] += counting[j - 1];
    }

    foru(i, 0, n - 1){
        output[-- counting[arr[i]]] = arr[i];
    }
    foru(i, 0, n - 1){
        cout << output[i] << " ";
    }
    
   

}
