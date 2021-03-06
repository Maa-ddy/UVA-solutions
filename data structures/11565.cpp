#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define llmin(a,b) ((a)<(b)?(a):(b))
#define llmax(a,b) ((a)>(b)?(a):(b))
#define llabs(a) ((a)>0?(a):-(a))
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ scanf( "%lld",A+K ); } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
ll mod = 1000000007;



int main(){
	FASTIO;
	ll a,b,c,n;
	cin >> n;
	while ( n-- ){
		cin >> a >> b >> c;
		unordered_set<string> ans;
		for ( ll x = -100; x < 101; x++ ){
			for ( ll y = -100; y < 101; y++ ){
				ll z = a - x - y;
				if ( x == y || y == z || x == z || x*x + y*y + z*z != c || x*y*z != b ){ continue; }
				ll xx = llmin(llmin(x,y),z);
				ll yy = llmax(llmax(x,y),z);
				ll zz = x + y + z - xx - yy;
				ans.insert(to_string(xx)+" "+to_string(zz) + " " + to_string(yy));
			}
		}
		if ( ans.size() == 0 ){
			cout << "No solution." << endl;
		}else{
			vector<string> res;
			for (auto tr : ans){ res.push_back(tr); }
			sort(res.begin(), res.end());
			for ( auto p : res ){
				//cout << p.first << " " << p.first<< " " << a - p.second - p.first << endl;
				cout << p << endl;
			}
		}
	}
	return 0;
}

