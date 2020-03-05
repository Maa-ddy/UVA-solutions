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
ld dist(ld x, ld y, ld a, ld b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
void debug(ll* a, ll n) { for ( ll k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }
#define PI 3.14159265358979323846

const int seg[] = {
	0b1111110,
	0b0110000,
	0b1101101,
	0b1111001,
	0b0110011,
	0b1011011,
	0b1011111,
	0b1110000,
	0b1111111,
	0b1111011
};

int main(){
	FASTIO;
	ll n; cin >> n;
	while (n) {
		vector<int> v;
		int err[n]; memset(err, 0, sizeof err);
		for ( int k = 0; k < n; k++ ){
			string s; cin >> s; reverse(all(s));
			int x = 0;
			for ( int j = 0; j < 7; j++ )
				if (s[j] == 'Y')
					x |= (1 << j);
			v.pb(x);
		}
		err[n - 1] = v[n - 1];
		for ( int k = n - 2; k >= 0; k--)
			err[k] = v[k] | err[k + 1];
		for ( int k = 0; k < n; k++ )
			err[k] = (~err[k])&0x7F;
		//for ( int k = 0; k < n; k++ ) cout << bitset<7>(err[k]) << "\n"; cout << endl;
		bool flag;
		for ( int k = 9; k >= 0; k--){
			flag = true;
			for ( int j = 0; j < n; j++ ) {
				if (k - j < 0 || ((v[j] | err[j]) ^ (seg[k - j] | err[j]))) {
					flag = false; break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			cout << "MATCH\n";
		else
			cout << "MISMATCH\n";
		cin >> n;
	}
	return 0;
}
