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



const int maxN = 1e6; 
struct Trienode{
	struct Trienode *child[27];

	int count = -1;

};

struct Trienode *new_node (void){
	struct Trienode *node_new = new Trienode;

	node_new->count = 0;

	up0(j, 26){
		node_new -> child[j] = NULL;
	}

	return node_new;
};

void insert(struct Trienode* root, string s){
	struct Trienode *current_node = root;


	up0(j, s.size()){
		if(current_node -> child[s[j] - 'a'] == NULL){
			current_node -> child[s[j] - 'a'] = new_node();
		}
		current_node = current_node -> child[s[j] - 'a'];
	}
	current_node -> count ++;

}

bool search(struct Trienode *root, string key){
	struct Trienode * current_node = root;

	up0(j, key.size()){
		if(current_node -> child[key[j] - 'a'] == NULL){
			return false;
		}
		current_node = current_node -> child[key[j] - 'a'];
		
	}
	return (current_node -> count > 0);
}

void delete_str(struct Trienode *root, string s){
	struct Trienode *current_node = root;

	// ca - common ancestor
	
	Trienode *ca_node = NULL;

	char ca_char = 'a';

	up0(j, s.size()){
		if(current_node -> child[s[j] - 'a'] == NULL){
			return;
		}
		int cnt = 0;
		up0(j, 26){ 
			if(current_node -> child[j] != NULL){
				cnt++;
			}
		}

		// find ca
		if(cnt > 1){
			ca_node = current_node;
			ca_char = s[j];
		}
		current_node = current_node -> child[s[j]- 'a'];

	}

	// check xem no co phai prefix cua thang nao ko
	int cnt = 0;
	for(int j=0; j < 26; j++){
		if(current_node -> child[j] != NULL){
			cnt++;
		}
	}

	if(cnt > 0){
		current_node -> count--;
		return;
	}

	// neu no co la >= 2 cua thang nao ko
	if(ca_node != NULL){
		ca_node -> child[ca_char] = NULL;
		return;
	}
	else{
		root -> child[s[0] - 'a'] = NULL;
		return;
	}
	return;

}


int main(){
	IOS

	struct Trienode *root = new_node();

	string in, out;

	cin >> in >> out;

	insert(root, in);

	delete_str(root, out);

	if(search(root, out) == true){
		cout << "yes";
	}
	else cout << "no";

}