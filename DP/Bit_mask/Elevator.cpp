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
#define endl '\n'
const int maxN = 22 ;
const int mod = 2e9;
const int inf = 330;

void open(){
    freopen("distance4.in", "r", stdin);
    freopen("distance4.out", "w", stdout); 
}

pair<int, int> ans[1 << maxN];
pair<int, int> options;
int arr[maxN], n, k;

signed main(){
 	IOS
	cin >> n >> k;
	foru(j, 0, n - 1) cin >> arr[j];	

	ans[0] = {1, 0};
	foru(i, 1, (1 << n) - 1){
		// the worst case like INF.
		ans[i] = mp(n + 1, 0);

		foru(j, 0, n - 1){
			// if there is person j in elevator (person j is using)
			if(i & (1 << j)){
				options = ans[i ^ (1 << j)];
				// enough for caring that person
				if(options.second + arr[j] <= k){
					options.second += arr[j];
				} // not enough
				else{
					options.first ++;
					options.second = arr[j];
				}
				// Consider to all persons who are in elevator.
				ans[i] = min(ans[i], options);
			}
		}

	}

	cout << ans[(1 << n) - 1].first;
}


// i am duc minh nguyen, nice to meet you.
