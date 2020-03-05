/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b); }
ld dist(ld x, ld y, ld a, ld b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
void debug(ll* a, ll n) { for ( ll k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }
#define PI 3.14159265358979323846

int main(){
	FASTIO;
	ll n, m; cin >> n >> m;
	ll t = 1;
	while (n | m) {
		ll a[n]; parseArray(a, n);
		ll e; cin >> e;
		map<ll, ll> common;
		for ( int k = 0; k < e; k++ ){
			ll x; cin >> x;
			ll b[x]; parseArray(b, x);
			ll y; cin >> y;
			int id = 0;
			for ( int j = 0; j < x; j++ )
				id |= 1 << (b[j] - 1);
			common[id] += y;
		}
		ll ans = 0, mask = 0;
		for ( int k = 0; k < (1 << n); k++ ){
			if (__builtin_popcount(k) != m)
				continue;
			ll tmp = 0;
			for ( ll j = 0; j < n; j++ )
				if (k&(1 << j))
					tmp += a[j];
			for (pair<ll, ll> p: common)
				if (p.first&k)
					tmp -= p.second * (__builtin_popcount(p.first&k) - 1);
			if (tmp > ans)
				ans = tmp, mask = k;
		}
		cout << "Case Number  " << t++ << "\n"
			<< "Number of Customers: " << ans << "\n"
			<< "Locations recommended: ";
		vector<ll> locations;
		for ( int k = 0; k < n; k++ )
			if (mask&(1 << k))
				locations.pb(k + 1);
		for ( int k = 0; k < sz(locations) - 1; k++ )
			cout << locations[k] << " ";
		cout << locations.back();
		cout << "\n\n";
		cin >> n >> m;
	}
	return 0;
}
