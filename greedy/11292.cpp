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

int main(){
	FASTIO;
	ll n, m;
	cin >> n >> m;
	while (n || m) {
		ll a[n]; parseArray(a, n);
		ll b[m]; parseArray(b, m);
		sort(a, a + n);
		sort(b, b + m);
		ll ans = 0;
		ll cur = 0;
		for ( int k = 0; k < n; k++ ){
			while (cur < m && b[cur] < a[k]) cur++;
			if (cur == m) { ans = -1; break; }
			ans += b[cur++];
		}
		if (ans == -1) cout << "Loowater is doomed!\n";
		else cout << ans << "\n";
		cin >> n >> m;
	}
	return 0;
}
