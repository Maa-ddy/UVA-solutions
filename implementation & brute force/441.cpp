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
ll a[100];

int main(){
	FASTIO;
	ll n; cin >> n;
	while (n){
		for ( int k = 0; k < n; k++ ){ cin >> a[k]; }
		sort(a, a + n);
		for ( int k = 0; k < n - 5; k++ ){
			for ( int j = k + 1; j < n - 4; j++ ){
				for ( int i = j + 1; i < n - 3; i++ ){
					for ( int l = i + 1; l < n - 2; l++ ){
						for ( int m = l + 1; m < n - 1; m++ ){
							for ( int p = m + 1; p < n; p++ ){
								cout << a[k] << " " << a[j] << " " << a[i] << " " << a[l] << " " << a[m] << " " << a[p] << '\n';
							}
						}
					}
				}
			}
		}
		cin >> n;
		if (n){ cout << '\n'; }
	}
	return 0;
}
