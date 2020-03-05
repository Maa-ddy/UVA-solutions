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
vector<ll> constraint[8][8];
ll seat[8];
ll backtrack(ll idx) {
	if (idx >= n) return 1;
	ll ans = 0;
	for ( int k = 0; k < n; k++ ){
		if (seat[k] != -1) continue;
		bool flag = true;
		for ( int j = 0; j < n; j++ ){
			if (k == j) continue;
			if (seat[j] != -1) {
				for (ll e : constraint[idx][seat[j]]){
					if (e > 0 && abs(k - j) > e) {
						flag = false;
						break;
					}
					if (e < 0 && abs(k - j) < -e) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
		}
		if (flag) {
			seat[k] = idx;
			ans += backtrack(idx + 1);
			seat[k] = -1;
		}
	}
	return ans;
}

int main(){
	FASTIO;
	cin >> n >> m;
	while (n + m) {
		memset(constraint, 0, sizeof constraint);
		for ( int k = 0; k < m; k++ ){
			ll x, y, z; cin >> x >> y >> z;
			constraint[x][y].pb(z);
			constraint[y][x].pb(z);
		}
		memset(seat, -1, sizeof seat);
		cout << backtrack(0) << "\n";
		cin >> n >> m;
	}
	return 0;
}
