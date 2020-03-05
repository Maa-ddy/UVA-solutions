/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//codeforces
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

ll n; 
bool g[101][101];
vector<vector<ll>> gg;
bool vis[101];
bool reachable[101];
void dfs(ll v, ll u) {
	vis[v] = 1;
	for (ll e : gg[v]) {
		if (!vis[e] && e != u)
			dfs(e, u);
	}
}

int main(){
	FASTIO;
	ll t; cin >> t;
	ll c = 1;
	while (t--) {
		cin >> n;
		gg.clear();
		gg.resize(n);
		for ( int k = 0; k < n; k++ ) {
			for ( int j = 0; j < n; j++ ) {
				cin >> g[k][j];
				if (g[k][j]) 
					gg[k].pb(j);
			}
		}
		short ans[n][n]; memset(ans, 0, sizeof ans);
		memset(vis, 0, sizeof vis);
		dfs(0, 0);
		for ( int k = 0; k < n; k++ ) {ans[0][k] = vis[k]; reachable[k] = vis[k]; }
		for ( int k = 1; k < n; k++ ){
			memset(vis, 0, sizeof vis);
			if (!reachable[k]) continue;
			dfs(0, k);
			for ( int j = 0; j < n; j++ )
				if (!vis[j] && reachable[j])
					ans[k][j] = 1;
		}
		cout << "Case " << c++ << ":\n";
		for ( int k = 0; k < n; k++ ){
			cout << "+"; for ( int i = 0; i < 2 * n - 1; i++ ) cout << "-"; cout << "+\n";
			for ( int j = 0; j < n; j++ ){
				cout << "|" << (ans[k][j] ? "Y" : "N");
			}cout << "|\n";
		}
		cout << "+"; for ( int i = 0; i < 2 * n - 1; i++ ) cout << "-"; cout << "+\n";
	}
	return 0;
}
