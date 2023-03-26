//#include "bits/stdc++.h"
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
 
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
#define up(j, n) for(int j=1; j <= (n); j++)
#define up0(j, n) for(int j=0; j < (n); j++)
#define down(j, n) for(int j= n; j >= 1; j--)
#define ld long double
ll random(ll l, ll r){
    ll x = l + rand() * rand() % (r - l + 1);
	if(x < 0) return -x;
	return x;
}

int main(){
    srand((ll)time(0));

	freopen("input.txt", "w", stdout);

	int t = random(1, 10);

	while(t--){
		int n = random(1, 20);
		cout << n << endl;

		up0(i, n){
			up0(j, n) cout << char ('a' + random(0, 25));

			cout << endl;
		}

		int q = random(1, 20);
		cout << q << endl;

		up0(j, q){
			
			cout << random(1, 3) ;
			
			
			int number_char = random(1, 20);
			up(k, number_char) cout << char ('a' + random(0, 25));

			cout << endl;
		}
	}
	
}
