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
ll n, m, x, k, v;

int main(){
	FASTIO;
	while (cin >> n){
		cin >> m;
		vector<ll> p[1000100];
		for ( int k = 0; k < n; k++ ){
			cin >> x;
			p[x].push_back(k+1);
		}
		for ( int i = 0; i < m; i++ ){
			cin >> k >> v;
			if ((ll)p[v].size() < k){
				cout << "0\n";
			}else {
				cout << p[v][k-1] << '\n';
			}
		}
	}
	return 0;
}
