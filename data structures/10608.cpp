//codeforces1150C
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

//__________________disjoint set____________________
ll size, numComp;
ll sz[30020], id[30020];
void build(ll N) {
	size = numComp = N;
	for ( ll k = 0; k < N; k++ ){
		sz[k] = 1;
		id[k] = k;
	}
}

ll find(ll p) {
	ll root = p;
	while (root != id[root]){ root = id[root]; }
	while (p != root){
		ll temp = id[p];
		id[p] = root;
		p = temp;
	}
	return root;
}

bool connected(ll p, ll q) { return find(p) == find(q); }
ll componentSize(ll p) { return sz[find(p)]; }

void unify(ll p, ll q) {
		ll root1 = find(p);
		ll root2 = find(q);
		if (root1 == root2) return;
		if (sz[root1] < sz[root2]) {
			sz[root2] += sz[root1];
			id[root1] = root2;
		} else {
			sz[root1] += sz[root2];
			id[root2] = root1;
		}
		numComp--;
}
//__________________________________________________



int main(){
	FASTIO;
	ll T; cin >> T;
	ll n,m;
	ll x,y;
	ll ans;
	while (T--) {
		cin >> n >> m;
		build(n + 1);
		for ( ll k = 0; k < m; k++ ){
			cin >> x >> y;
			unify(x,y);
		}
		ans = 0;
		for ( ll k = 0; k <= n; k++ ){
			ans = max(ans, sz[k]);
		}
		cout << ans << '\n';
	}
	return 0;
}
