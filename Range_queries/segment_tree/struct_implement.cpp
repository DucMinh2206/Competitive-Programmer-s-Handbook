//#include "bits/stdc++.h"
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define forp(j, a, b) for(int j = a; j + 1 <= b; ++j)
#define endl '\n'
typedef long double ld; 
const int maxN = 1e6 + 5;
const int mod = 2e9;
const int inf = 1e9;
struct Node{
    int value, lazy;
    Node (){};

    Node(int vl, int lz){
        value = vl;
        lazy = lz;
    }

    Node operator +(const Node &num){
        Node ans;
        ans.value += num.value + value;
        ans.lazy += num.lazy + lazy;
        return ans;
    }

}st[4 * maxN];
int arr[maxN];

void build(int id, int l, int r){

    if(l == r){
        st[id].value = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].value = st[id * 2].value + st[id * 2 + 1].value;
}

void push_down(int id){
    if(st[id].lazy != 0){
        int vl = st[id].lazy;

        st[id * 2].value += vl;
        st[id * 2].lazy += vl;

        st[id * 2 + 1].value += vl;
        st[id * 2 + 1].lazy += vl;

        st[id].lazy = 0;
    }
}

void update(int id, int l, int r, int ql, int qr, int val){
    if(ql <= l && r <= qr){
        st[id].value += val;
        st[id].lazy += val;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(id);
    update(id * 2, l, mid, ql, qr, val);
    update(id * 2 + 1, mid + 1, r, ql, qr, val);
}
int get(int id, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return st[id].value;
    }

    int mid = (l + r) >> 1;
    push_down(id);
    return get(id * 2, l, mid, ql, qr) + get(id * 2 + 1, mid + 1, r, ql, qr);
}
int n;
signed main(){
    cin >> n;

    foru(j, 1, n){
        cin >> arr[j];
    }
    build(1, 1, n);
    update(1, 1, n, 1, 2, 2);
    cout << get(1, 1, n, 1, n);
}
