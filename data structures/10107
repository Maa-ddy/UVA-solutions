#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define llmin(a,b) ((a)<(b)?(a):(b))
#define llmax(a,b) ((a)>(b)?(a):(b))
#define llabs(a) ((a)>0?(a):-(a))
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
ll mod = 1000000007;



int main(){
	FASTIO;//in java, use TreeSet, with methods first() and last(), add() and remove()
	ll n;
	set<pair<ll,ll>> l,r;
	ll c = 0;
	while (cin >> n){
		set<pair<ll,ll>>::iterator x;
		if (r.empty() || n <= (*r.begin()).first){ l.insert(make_pair(n,c++)); }
		else{ r.insert(make_pair(n,c++)); }
		if ((ll)l.size() - (ll)r.size() > 1){ x = l.end(); x--; r.insert(*x); l.erase(*x); }
		else if ((ll)r.size() - (ll)l.size() > 1){ l.insert(*r.begin()); r.erase(*r.begin()); }
		if (l.size() - r.size() == 1){
			x = l.end(); x--;
			cout << (*x).first;
		}else if (r.size() - l.size() == 1){
			cout << (*r.begin()).first;
		}else{
			x = l.end(); x--;
			cout << ((*x).first + (*r.begin()).first)/2;
		}cout << '\n';
		
	}
	return 0;
}
