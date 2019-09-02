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

ll n, m;
const ll inf = 1e9;
vector<pair<ll, ll>> a;
ll memo[100][10500];

ll dp(ll idx, ll moeny) {
	if (moeny > 2000 && moeny > m + 200) return -inf;
	if (moeny > 2000 && moeny == m + 200) return 0;
	if (idx >= n) return moeny <= 2000 ? (moeny <= m ? 0 : -inf) : (moeny <= m + 200 ? 0 : -inf);
	if (memo[idx][moeny] != -1) return memo[idx][moeny];
	ll ans = max(dp(idx + 1, moeny + a[idx].first) + a[idx].second, dp(idx + 1, moeny));
	return memo[idx][moeny] = ans;
}

int main(){
	FASTIO;
	ll x, y;
	while (cin >> m) {
		cin >> n;
		a.clear();
		for ( int k = 0; k < n; k++ ){ cin >> x >> y; a.pb(mp(x, y)); }
		for ( int k = 0; k < n; k++ ){
			for ( int j = 0; j < max(m + 201, 2001LL); j++ ){
				memo[k][j] = -1;
			}
		}
		memset(memo, -1, sizeof memo);
		cout << dp(0, 0) << "\n";
	}
	return 0;
}
