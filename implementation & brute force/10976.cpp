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


int main(){
	FASTIO;
	ll n;
	unordered_set<ll> ans;
	while (cin >> n){
		ans.clear();
		ll bound = 2*n;
		ll x = n + 1;
		ll cnt = 0;
		while (x <= bound){
			if ((x*n)%(x - n) == 0){ if (ans.find(x) == ans.end()){ ans.insert(x); cnt++; ans.insert((n*x)/(x - n)); } }
			x++;
		}
		cout << cnt << endl;
		for ( int k = 0; k < 20010; k++ ){
			if (ans.find(k) != ans.end()){
				ll y = (k*n)/(k - n);
				ans.erase(y);
				cout << "1/" << n << " = 1/" << y << " + 1/" << k << "\n";
			}
		}
	}
	return 0;
}
