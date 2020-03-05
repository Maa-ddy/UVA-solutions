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
ll n;
vector<pair<ll, ll>> nodes;
ld memo[8][(1 << 8)];

ld dis(ll x, ll y) { return dist(nodes[x].first, nodes[x].second, nodes[y].first, nodes[y].second); }

ld dp(ll node, ll mask) {
	if (mask == (1 << n) - 1) return memo[node][mask] = 0;
	if (memo[node][mask] != -1) return memo[node][mask];
	ld ans = 1e18;
	for ( int k = 0; k < n; k++ ){
		if ((mask & (1 << k)) == 0) {
			ans = min(ans, dis(node, k) + dp(k, mask | (1 << k)));
		}
	}
	return memo[node][mask] = ans;
}

void print_dp(ll node, ll mask) {
	for ( int k = 0; k < n; k++ ){
		if (k == node) continue;
		if (memo[node][mask] == dis(node, k) + memo[k][mask | (1 << k)]) {
			cout << fixed << setprecision(2) << "Cable requirement to connect (" << nodes[node].first << "," << nodes[node].second << ") to (" << nodes[k].first << "," << nodes[k].second << ") is "
			<< dis(node, k) + 16 << " feet.\n";
			print_dp(k, mask | (1 << k));
			break;
		}
	}
}

int main(){
	FASTIO;
	cin >> n;
	ll x, y;
	ll cnt = 1;
	while (n) {
		nodes.clear();
		for ( int k = 0; k < n; k++ ){
			for ( int j = 0; j < (1 << n); j++ ){
				memo[k][j] = -1;
			}
		}
		for ( int k = 0; k < n; k++ ){
			cin >> x >> y;
			nodes.pb({x, y});
		}
		ld ans = 1e18; ll idx = 0;
		for ( int k = 0; k < n; k++ ){
			if (dp(k, (1 << k)) < ans) {
				ans = dp(k, (1 << k));
				idx = k;
			}
		}
		cout << "**********************************************************\n";
		cout << "Network #" << cnt++ << "\n";
		print_dp(idx, (1 << idx));
		cout << fixed << setprecision(2) << "Number of feet of cable required is " << ans + (n - 1) * 16 << ".\n";
		cin >> n;
	}
	return 0;
}
