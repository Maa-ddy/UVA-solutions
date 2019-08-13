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
ld p, q, r, s, t, u;

ld f(ld x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + x * x * t + u;
}

int main(){
	FASTIO;
	while (cin >> p) {
		cin >> q >> r >> s >> t >> u;
		if (f(0) * f(1) > 0) { cout << "No solution\n"; continue; }
		ld lo = 0.0, hi = 1.0, mid;
		ld err = 1, v;
		while (err > 1e-6) {
			mid = (lo + hi) / 2;
			v = f(mid);
			err = abs(v);
			if (v > 0) { lo = mid; } else { hi = mid; }
		}
		cout << fixed << setprecision(4) << mid << "\n";
	}
	return 0;
}
