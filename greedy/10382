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
	ld l, w;
	ld x, y;
	while (cin >> n) {
		cin >> l >> w;
		pair<ld, ld> a[n];
		for ( int k = 0; k < n; k++ ){
			cin >> x >> y;
			a[k].first = x - sqrt(y * y - w * w / 4);
			a[k].second = x + sqrt(y * y - w * w / 4);
			if (y * 2 < w) a[k].first = l + 22;
		}
		sort(a, a + n);
		ll ans = 0;
		ld right = 0;
		ll cur = 0;
		while (cur < n && right < l) {
			ld cand = a[cur].second;
			if (a[cur].first > right) { ans = -1; break; }
			while (cur < n && a[cur].first <= right) {
			cand = max(cand, a[cur++].second); }
			right = cand;
			ans++;
		}
		if (right < l) ans = -1;
		cout << ans << "\n";
	}
	return 0;
}
