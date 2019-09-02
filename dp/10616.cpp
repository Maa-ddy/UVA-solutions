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
void debug(vector<ll> a, ll n) { for ( int k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }
ll n, q, d, m;
vector<ll> a;
ll memo[200][50][11];
ll dp(ll idx, ll mod, ll left) {
	if (left == 0) return mod == d;
	if (idx >= n) return 0;
	if (memo[idx][mod][left] != -1) return memo[idx][mod][left];
	ll temp = (mod - d + a[idx]) % d;
	if (mod - d + a[idx] < 0) temp = -(-(mod - d+ a[idx]) % d);
	ll ans = dp(idx + 1, temp + d, left - 1) + dp(idx + 1, mod, left);
	return memo[idx][mod][left] = ans;
}

int main(){
	FASTIO;
	cin >> n >> q;
	ll st = 1;
	while (n && q) {
		a.resize(n);
		for ( int k = 0; k < n; k++ ){ cin >> a[k]; }
		cout << "SET " << st++ << ":\n";
		for ( int p = 1; p <= q; p++ ){
			cin >> d >> m;
			memset(memo, -1, sizeof memo);
			cout << "QUERY " << p << ": ";
			cout << dp(0, d, m) << "\n";
		}
		cin >> n >> q;
	}
	return 0;
}
