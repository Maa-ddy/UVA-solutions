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
const ll mod = 1000000;

int main(){
	FASTIO;
	ll n, m; cin >> n >> m;
	while (n + m) {
		ll dp[n + 1][m + 1];
		for ( int k = 0; k <= n; k++ ){
			dp[k][1] = 1;
		}
		for ( int k = 2; k <= m; k++ ){
			ll pref[n + 1];
			pref[0] = dp[0][k - 1];
			for ( int j = 1; j <= n; j++ ){
				pref[j] = pref[j - 1] + dp[j][k - 1];
				pref[j] %= mod;
			}
			for ( int j = 0; j <= n; j++ ){
				dp[j][k] = pref[j];
			}
		}
		cout << dp[n][m] << "\n";
		cin >> n >> m;
	}
	return 0;
}
