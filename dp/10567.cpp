/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//dp
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
	string s; cin >> s;
	ll n = s.length();
	int nxt[n][60]; memset(nxt, -1, sizeof nxt);
	nxt[n - 1][s[n - 1] - 'A'] = n - 1;
	for ( int k = n - 2; k >= 0; k--){
		for ( char c = 'A'; c <= 'z'; c++ )
			nxt[k][c - 'A'] = nxt[k + 1][c - 'A'];
		nxt[k][s[k] - 'A'] = k;
	}
	ll q; cin >> q;
	for ( int k = 0; k < q; k++ ){
		string t; cin >> t;
		ll m = t.length();
		ll cur = 0;
		bool flag = true;
		for ( int j = 0; j < m; j++ ){
			cur = nxt[cur][t[j] - 'A'];
			if (cur == -1) {
				cout << "Not matched\n";
				flag = false;
				break;
			}
			cur++;
			if (cur == n) {
				cout << "Not matched\n";
				flag = false; break;
			}
		}
		if (flag)
			cout << "Matched " << nxt[0][t[0] - 'A'] << " " << cur - 1 << "\n";
	}
	return 0;
}
