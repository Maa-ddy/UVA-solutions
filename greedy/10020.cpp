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
	ll T; cin >> T;
	ll m, x, y, n, bound;
	bool flag;
	while (T--){
		cin >> m;
		vector< pair<ll, ll> > v;
		cin >> x >> y;
		while (x != 0 || y != 0){
			v.pb(mp(x,y));
			cin >> x >> y;
		}
		sort(v.begin(), v.end());
		x = y = 0;
		n = v.size();
		bound = 0;
		vector< pair<ll, ll> > ans;
		flag = 0;
		while (y < n){
			x = y;
			while (y < n && v[y].first <= bound){
				if (v[y].second > v[x].second){ x = y; }
				y++;
			}
			if (v[x].first > bound){ break; }
			bound = v[x].second;
			ans.pb(v[x]);
			if (bound >= m){ flag = 1; break; }
		}
		if (flag){
			cout << ans.size() << '\n';
			for (auto e : ans){ cout << e.first << " " << e.second << '\n'; }
		}else { cout << "0\n"; }
		if (T) { cout << '\n'; }
	}
	return 0;
}
