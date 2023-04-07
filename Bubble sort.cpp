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

const int maxN = 5005;
int arr[maxN], n; 

int main() {
      //freopen("1.inp", "r", stdin);
      //freopen("1.out", "w", stdout);
    cin >> n;

    foru(j, 0, n - 1){
        cin >> arr[j];
    }

    foru(i, 0, n - 1){
        foru(j, 0, n - 2){
            if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }

}
