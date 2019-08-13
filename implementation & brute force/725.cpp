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
	ll n; cin >> n;
	while (n){
		ll flag = 0;
		vector<string> ans;
		for ( int a = 0; a < 10; a++ ){
			flag |= (1<<a);
			for ( int b = 0; b < 10; b++ ){
				if ( flag&(1<<b) ){ continue;}
				flag |= (1<<b);
				for ( int c = 0; c < 10; c++ ){
					if ( flag&(1<<c) ){ continue;}
					flag |= (1<<c);
					for ( int d = 0; d < 10; d++ ){
						if ( flag&(1<<d) ){ continue;}
						flag |= (1<<d);
						for ( int e = 0; e < 10; e++ ){
							if ( flag&(1<<e) ){ continue;}
							flag |= (1<<e);
							ll denom = a*10000 + 1000*b + 100*c + 10*d + e;
							ll num = denom*n;
							if ( num > 99999 ){
								flag ^= (1<<e);
								continue;
							}
							ll x = 0;
							ll temp = num;
							while ( temp ){
								x |= (1<<(temp%10));
								temp /= 10;
							}
							if ( (x|flag) != 1023 ){
								flag ^= (1<<e);
								continue;
							}
							string snum = to_string(num);
							string sdenom = to_string(denom);
							int t1 = snum.length();
							for ( int k = 0; k < 5 - t1; k++ ){snum = "0"+snum;}
							t1 = sdenom.length();
							for ( int k = 0; k < 5 - t1; k++ ){sdenom = "0"+sdenom;}
							ans.push_back(snum+" / "+sdenom+" = "+to_string(n));
							flag ^= (1<<e);
						}
						flag ^= (1<<d);
					}
					flag ^= (1<<c);
				}
				flag ^= (1<<b);
			}
			flag ^= (1<<a);
		}
		sort(ans.begin(), ans.end());
		if ( ans.size() == 0 ){ cout << "There are no solutions for " << n << "." << "\n"; }
		else{
			for (string s : ans) cout << s << "\n";
		}
		cin >> n;
		if ( n ){ cout << "\n";}
	}
	return 0;
}

