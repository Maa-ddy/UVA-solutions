#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
long double dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
ll mod = 1000000007;
short ans[32][32];
char c;

void f(int l, int r, int u, int d){
	cin >> c;
	if (c != 'p'){
		for ( int j = u; j <= d; j++ ){
			for ( int k = l; k <= r; k++ ){
				ans[j][k] += c=='e'?0:1;
			}
		}
		return;
	}
	f((l+r)/2 + 1, r, u, (u+d)/2);
	f(l, (l+r)/2, u, (u+d)/2);
	f(l, (l+r)/2, (u+d)/2 + 1, d);
	f((l+r)/2 + 1, r, (u+d)/2 + 1, d);
}

int main(){
	FASTIO;
	ll T; cin >> T;
	while (T--) {
		memset(ans, 0, sizeof ans);
		f(0,31,0,31);
		f(0,31,0,31);
		ll rez = 0;
		for ( int k = 0; k < 32; k++ ){
			for ( int j = 0; j < 32; j++ ){
				rez += ans[k][j] > 0;
			}
		}
		cout << "There are " << rez << " black pixels.\n";
	}
	return 0;
}
