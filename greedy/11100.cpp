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
ll n;

int main(){
	FASTIO;
	cin >> n;
	while (n) {
		ll a[n]; parseArray(a, n);
		sort(a, a + n);
		ll max_rep = 1, cur_rep = 1;
		for ( int k = 1; k < n; k++ ){
			if (a[k] == a[k - 1]) cur_rep++;
			else {
				max_rep = max(max_rep, cur_rep);
				cur_rep = 1;
			}
		}
		max_rep = max(max_rep, cur_rep);
		vector<ll> ans[max_rep];
		for ( int k = 0; k < n; k++ ){
			ans[k % max_rep].pb(a[k]);
		}
		cout << max_rep << "\n";
		for ( int k = 0; k < max_rep; k++ ){
			for ( int j = 0; j < sz(ans[k]) - 1; j++ )
				cout << ans[k][j] << " ";
			cout << ans[k][sz(ans[k]) - 1] << "\n";
		}cout << "\n";
		cin >> n;
	}
	return 0;
}
