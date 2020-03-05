/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//dp + datastructures + greedy + binary search
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
	vector<ll> v; ll x;
	while (cin >> x) v.pb(x);
	ll n = sz(v);
	stack<pair<ll, ll>> dp[n];
	ll ans = 1;
	dp[0].push({v[0], 0});
	for ( int k = 1; k < n; k++ ){
		ll l = 0, h = ans - 1;
		ll pos = ans;
		while (l <= h) {
			ll mid = (l + h) / 2;
			if (dp[mid].top().first >= v[k])
				h = mid - 1, pos = mid;
			else
				l = mid + 1;
		}
		if (pos == ans)
			ans++;
		dp[pos].push({v[k], k});
	}
	cout << ans << "\n-\n";
	ll last = dp[ans - 1].top().second;
	vector<ll> res;
	while (ans--) {
		while (dp[ans].top().second > last)
			dp[ans].pop();
		last = dp[ans].top().second;
		res.pb(dp[ans].top().first);
	}
	reverse(all(res));
	for (ll e: res)
		cout << e << "\n";
	return 0;
}
