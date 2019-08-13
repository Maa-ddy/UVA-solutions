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
ll n, m, T;
short a[10][100];

int main(){
	FASTIO;
	cin >> T;
	while (T--){
		cin >> n >> m;
		for ( int k = 0; k < n; k++ ){
			for ( int j = 0; j < m; j++ ){
				cin >> a[k][j];
			}
		}
		short flag = 1;
		set< pair<ll,ll> > g;
		for ( int k = 0; k < m; k++ ){
			ll x = 0, y = 0;
			ll cnt = 0;
			for ( int j = 0; j < n; j++ ){
				if (a[j][k]){
					if (x){ y = j + 1; }else{ x = j + 1; }
					cnt += a[j][k];
				}
			}
			if (x == 0 || y == 0 || cnt != 2){
				 cout << "No\n"; flag = 0; break;
			}
			pair<ll,ll> temp = mp(x,y);
			if (g.find(temp) == g.end()){
				g.insert(temp);
			}else {
				cout << "No\n"; flag = 0; break;
			}
		}
		if (flag){ cout << "Yes\n"; }
	}
	return 0;
}
