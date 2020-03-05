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
ld dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
void debug(ll* a, ll n) { for ( int k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }

ll g[111][111];
ll n;
bool vis[111][111];
ll valid(ll x, ll y) {
	return x < n && y < n && x >= 0 && y >= 0 && !vis[x][y];
}
ll bfs(ll x, ll y) {
	//cout << x << " " << y << endl;
	deque<pair<pair<ll, ll>, ll>> q;
	q.pb({{x, y}, 0});
	memset(vis, 0, sizeof vis);
	while (!q.empty()) {
		pair<pair<ll, ll>, ll> p = q.back(); q.pop_back();
		ll k = p.first.first, j = p.first.second, d = p.second;
		vis[k][j] = 1;
		if (valid(k, j + 1)) {
			if (g[k][j + 1] == 3) return d + 1;
			q.push_front({{k, j + 1}, d + 1});
			vis[k][j + 1] = 1;
		}
		if (valid(k, j - 1)) {
			if (g[k][j - 1] == 3) return d + 1;
			q.push_front({{k, j - 1}, d + 1});
			vis[k][j - 1] = 1;
		}
		if (valid(k + 1, j)) {
			if (g[k + 1][j] == 3) return d + 1;
			q.push_front({{k + 1, j}, d + 1});
			vis[k + 1][j] = 1;
		}
		if (valid(k - 1, j)) {
			if (g[k - 1][j] == 3) return d + 1;
			q.push_front({{k - 1, j}, d + 1});
			vis[k - 1][j] = 1;
		}
	}
	return 1000000000;
}
int main() {
	FASTIO
	while (cin >> n) {
		for ( int k = 0; k < n; k++ ){
			string s; cin >> s;
			for ( int j = 0; j < n; j++ )
				g[k][j] = s[j] - '0';
		}
		ll ans = 0;
		for ( int k = 0; k < n; k++ )
			for ( int j = 0; j < n; j++ )
				if (g[k][j] == 1)
					ans = max(ans, bfs(k, j));
		cout << ans << "\n";
	}
	return 0;
}
