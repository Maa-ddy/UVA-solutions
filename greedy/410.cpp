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
ld dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }

int main(){
	ll c,s, a[10], t = 1;
	ld imb, avg;
	while (cin >> c){
		cin >> s;
		parseArray(a, s);
		for ( int k = s; k < 2*c; k++ ){
			a[k] = 0;
		}
		sort(a, a + 2*c);
		avg = 0;
		for ( int k = 0; k < 2*c; k++ ){
			avg += a[k];
		}
		avg /= c;
		cout << "Set #" << t++ << '\n';
		imb = 0;
		for ( int k = 0; k < c; k++ ){
			cout << " " << k << ":";
			if (a[2*c - k - 1]){cout << " " << a[2*c - k - 1];}
			if (a[k]){ cout << " " << a[k]; }
			imb += abs(avg - a[2*c - k - 1] - a[k]);
			cout << '\n';
		}
		printf("IMBALANCE = %.5lf\n\n", (double)imb);
	}
	return 0;
}
