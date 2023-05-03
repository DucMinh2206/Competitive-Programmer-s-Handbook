#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define forp(j, a, b) for(int j = a; j + 1 <= b; ++j)
typedef pair<ll, ll> pii;
#define ld long double
const int maxN = 500005;
const int mod = 2e9;
const int inf = 330;
#define endl '\n'

int arr[maxN], different[maxN], n, prefix_sum[maxN];
void update(int l, int r, int value){
		different[l] += value; // add value and the previous l number is not changing
		different[r + 1]  -= value; // the previous value r + 1 is changing and the value r + 1 is not changing
}

signed main(){
	IOS
	//freopen("minh.txt", "r", stdin);
	//freopen("minh.txt", "w", stdout);
	cin >> n;

	foru(j, 1, n){
		cin >> arr[j];
		different[j] = arr[j] - arr[j - 1];
	}
	update(1, 4, 1);
	
	foru(j, 1, n){
		if(j == 1){
			arr[j] = different[j];
		}
		else arr[j] = different[j] + arr[j - 1];

		cout << arr[j] << " " ; 
	}

}
// get value in O(N) and update in O(1).
