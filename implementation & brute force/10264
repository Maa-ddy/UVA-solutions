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

int main(){
	FASTIO;
	ll a[1<<17];
	ll sum[1<<17];
	ll ans;
	while (cin >> n) {
		for ( int k = 0; k < (1 << n); k++ ){
			cin >> a[k];
		}
		for ( int k = 0; k < (1 << n); k++ ){
			sum[k] = 0;
			for ( int i = 0; i < n; i++ ){
				sum[k] += a[k ^ (1 << i)];
			}
		}
		ans = 0;
		for ( int k = 0; k < (1 << n); k++ ){
			ll s = 0;
			for ( int i = 0; i < n; i++ ){
				s = max(s, sum[k ^ (1 << i)]);
			}
			ans = max(ans, s + sum[k]);
		}
		cout << ans << "\n";
	}
	return 0;
}
