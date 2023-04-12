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
const int maxN = 5000;
int x;
mii counting; mii::iterator it;
int e, n, value, frequency, mid, pos, num;
vector<int> aa, ans;

void counting_sort(vector<int> arr, int n, vector<int> &a){
    foru(j, 0, n - 1){
        counting[arr[j]]++;
    }
    for(it = counting.begin(); it != counting.end(); ++it){
        value = it -> F;
        frequency = it -> S;

        foru(j, 0, frequency - 1){
            a.push_back(value);
        }
    }
    return;
    
}

int main() {
    IOS
    //freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
    cin >> n >> num;
    foru(j, 1, n){
        cin >> x;
        aa.push_back(x);
    }
    counting_sort(aa, n, ans);

    vector<int>::iterator it_first, it_second;

    it_first = lower_bound(ans.begin(), ans.end(), num);
    it_second = upper_bound(ans.begin(), ans.end(), num);
    cout << it_second - it_first;

// time complexity O(n + logn)
}
