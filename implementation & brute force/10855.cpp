#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define llmin(a,b) ((a)<(b)?(a):(b))
#define llmax(a,b) ((a)>(b)?(a):(b))
#define llabs(a) ((a)>0?(a):-(a))
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ scanf( "%lld",A+K ); } }
ll n, m;
int main() {
	cin >> n >> m;
	while ( n || m ){
		char a[n+10][n+10];
		char d[m+10][m+10];
		ll k,j;
		for ( k = 0; k < n; k++){
			scanf("%s", a[k]);
		}
		for ( k = 0; k < m; k++){
			scanf("%s", d[k]);
		}
		int c;
		ll ans[4]; memset(ans, 0, sizeof ans);
		char b[m+10][m+10];
		for ( k = 0; k < m; k++){
			for ( j = 0; j < m; j++){
				b[k][j] = d[k][j];
			}
		}
		for ( c = 0; c < 4; c++){
			for ( k = 0; k <= n-m; k++){
				for ( j = 0; j <= n-m; j++){
					ll x,y;
					short flag = 1;
					for ( x = 0; x < m; x++){
						for ( y = 0; y < m; y++){
							if ( a[x+k][y+j] != b[x][y] ){
								flag = 0;
								break;
							}
						}
						if ( !flag ){ break; }
					}
					if ( flag ){ ans[c]++; }
				}
			}
			//rotate:
			for ( k = 0; k < m; k++){
				for ( j = 0; j < m; j++){
					b[k][j] = d[m-1-j][k];
				}
			}for ( k = 0; k < m; k++){
				for ( j = 0; j < m; j++){
					d[k][j] = b[k][j];
				}
			}
		}
		for ( k = 0; k < 3; k++){
			cout << ans[k] << " ";
		}cout << ans[3] << endl;
		cin >> n >> m;
	}
	return 0;
}
