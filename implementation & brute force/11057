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
ld dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }

int main(){
	FASTIO;
	ll n, m, x;
	ll a[10010];
	int s[10000100];
	while (cin >> n) {
		memset(s, 0, sizeof s);
		for ( ll k = 0; k < n; k++ ){
			cin >> a[k];
			s[a[k]]++;
		}
		cin >> m;
		x = -1;
		for ( ll k = 0; k < n; k++ ){
			if (a[k] < m && ((s[m - a[k]] && m - a[k] != a[k]) || (m - a[k] == a[k] && s[m - a[k]] > 1))) {
				if (x == -1){
					x = a[k];
				}else {
					if (abs(2*a[k] - m) < abs(2*x - m)){ x = a[k]; }
				}
			}
		}
		cout << "Peter should buy books whose prices are " << min(x, m - x) << " and " << max(x, m - x) << ".\n\n";
	}
	return 0;
}
