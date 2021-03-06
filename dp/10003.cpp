/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b); }
ld dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
void debug(ll* a, ll n) { for ( int k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }
ll n, m;
ll a[55];
ll memo[55][55];
ll dp(ll l, ll r) {
	if (memo[l][r] != -1) return memo[l][r];
	if (r - l == 1) { return memo[l][r] = 0; }
	ll ans = 1e12;
	for ( int k = l + 1; k < r; k++ ){
		ans = min(ans, dp(l, k) + dp(k, r));
	}
	return memo[l][r] = ans + a[r] - a[l];
}

int main(){
	FASTIO;
	cin >> m;
	while (m) {
		cin >> n;
		a[0] = 0;
		for ( int k = 1; k <= n; k++ ){ cin >> a[k]; } a[n + 1] = m;
		memset(memo, -1, sizeof memo);
		cout << "The minimum cutting is " << dp(0, n + 1) << ".\n";
		cin >> m;
	}
	return 0;
}
