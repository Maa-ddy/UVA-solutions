#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
long double dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
ll mod = 1000000007;
ll m[1025][1025];

int main(){
	FASTIO;
	ll T; cin >> T;
	ll d,n,x,y,z, ans;
	while (T--){
		cin >> d;
		cin >> n;
		memset(m, 0, sizeof m);
		for ( int k = 0; k < n; k++ ){
			cin >> x >> y >> z;
			for ( int j = max(0LL, x - d); j <= min(1024LL, x + d); j++ ){
				for ( int i = max(0LL, y - d); i <= min(1024LL, y + d); i++ ){
					m[j][i] += z;
				}
			}
		}
		ans = m[0][0]; x = y = 0;
		for ( int k = 0; k < 1025; k++ ){
			for ( int j = 0; j < 1025; j++ ){
				if (m[k][j] > ans){
					ans = m[k][j];
					x = k; y = j;
				}
			}
		}
		cout << x << " " << y << " " << ans << endl;
	}
	return 0;
}
