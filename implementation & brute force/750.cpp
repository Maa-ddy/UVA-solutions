#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
long double dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
ll mod = 1000000007;
ll x,y,h,d,dd;
set<string> ans;
string cand;
ll comb[9];

void solve(ll c){
	if (c == 9){
		cand = "";
		for ( int k = 1; k < 8; k++ ){
			cand += to_string(comb[k]) + " ";
		}cand += to_string(comb[8]);
		ans.insert(cand);
		return;
	}
	if (c == y){ solve(c + 1); return; }
	for ( int k = 1; k < 9; k++ ){
		if ((h&(1<<k)) == 0 
		    && (d&(1<<(k - c + 8))) == 0 
		    && (dd&(1<<(k - (9 - c) + 8))) == 0 ){
			h |= (1<<k);
			d |= (1<<(k - c + 8));
			dd |= (1<<(k - (9 - c) + 8));
			comb[c] = k;
			solve(c + 1);
			h ^= (1<<k);
			d ^= (1<<(k - c + 8));
			dd ^= (1<<(k - (9 - c) + 8));
		}
	}
	return;
}

int main(){
	FASTIO;
	ll n; cin >> n;
	while (n--){
		cin >> x >> y;
		h = d = dd = 0;
		h |= (1 << x);
		d |= (1 << (x - y + 8)); dd |= (1 << (x - (9 - y) + 8));
		ans.clear();
		comb[y] = x;
		solve(1);
		cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		ll cnt = 1;
		for (string s : ans){
			if (cnt < 10){cout << " ";} cout << cnt++ << "      " << s << "\n";
		}if (n)cout << "\n";
	}
	return 0;
}
