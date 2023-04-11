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
vector<int> ans;
mii counting; mii::iterator it;
int arr[maxN], n, value, frequency, mid, pos, num;

void counting_sort(int arr[], int n, vector<int> &a){
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
int binary_search(int l, int r, int num){

    if(r >= l){
        mid = (l + r)/2;
        if(arr[mid] == num) return mid;
        //cout << mid << " " << l << " " << r << endl;
        else if(arr[mid] < num)  return binary_search(mid + 1, r, num);
        
        else return binary_search(l, mid - 1, num);
    }

    return -1;
}

int main() {
    IOS
    //freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
    cin >> n >> num;
    foru(j, 1, n){
        cin >> arr[j];
    }
    counting_sort(arr, n, ans);

    cout << binary_search(1, n, num);
    
}
// time complexity O(n + logn)
