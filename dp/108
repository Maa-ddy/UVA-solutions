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
ll pref[111][111];

ll seg_sum(ll line, ll start, ll end) { return pref[line][end] - (start == 0?0:pref[line][start - 1]); }

int main(){
	FASTIO;
	cin >> n;
	ll a[n][n];
	for ( int k = 0; k < n; k++ ){
		for ( int j = 0; j < n; j++ ){
			cin >> a[k][j];
		}
	}
	for ( int k = 0; k < n; k++ ){
		pref[k][0] = a[k][0];
		for ( int i = 1; i < n; i++ ){
			pref[k][i] = pref[k][i - 1] + a[k][i];
		}
	}
	ll ans = a[0][0];
	for (int start = 0; start < n; start++) {
		for (int end = start; end < n; end++) {
			ll current_max = seg_sum(0, start, end);
			ll current_run = current_max;
			for ( int k = 1; k < n; k++ ){
				current_run = max(seg_sum(k, start, end) + current_run, seg_sum(k, start, end));
				current_max = max(current_max, current_run);
			}
			ans = max(ans, current_max);
		}
	}
	cout << ans << endl;
	return 0;
}
