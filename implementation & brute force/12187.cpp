#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define llmin(a,b) ((a)<(b)?(a):(b))
#define llmax(a,b) ((a)>(b)?(a):(b))
#define llabs(a) ((a)>0?(a):-(a))
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ scanf( "%lld",A+K ); } }
int main() {
	ll n, r, c, K; cin >> n >> r >> c >> K;
	int mat[111][111];
	int ans[111][111];
	while ( !( n == 0 && r == 0 && c ==0 && K == 0 ) ){
		for ( int k = 0; k < r; k++){
			for ( int j = 0; j < c; j++){
				scanf( "%d", &mat[k][j] );
			}
		}
		for ( int i = 0; i < K; i++ ){
			for ( int k = 0; k < r; k++){
				for ( int j = 0; j < c; j++){
					ans[k][j] = mat[k][j];
				}
			}
			for ( int k = 0; k < r; k++){
				for ( int j = 0; j < c-1; j++){
					if ( (mat[k][j+1] - mat[k][j] + n)%n == 1 ){
						ans[k][j+1] = mat[k][j];
					}if ( (mat[k][j] - mat[k][j+1] + n)%n == 1 ){
						ans[k][j] = mat[k][j+1];
					}

				}
			}
			for ( int k = 0; k < c; k++){
				for ( int j = 0; j < r-1; j++){
					if ( (mat[j+1][k] - mat[j][k] + n)%n == 1 ){
						ans[j+1][k] = mat[j][k];
					}if ( (mat[j][k] - mat[j+1][k] + n)%n == 1 ){
						ans[j][k] = mat[j+1][k];
					}
				}
			}
			for ( int k = 0; k < r; k++){
				for ( int j = 0; j < c; j++){
					mat[k][j] = ans[k][j];
				}
			}
		}
		for ( int k = 0; k < r; k++){
			for ( int j = 0; j < c-1; j++){
				printf( "%d ",ans[k][j] );
			}printf( "%d\n", ans[k][c-1] );
		}
		cin >> n >> r >> c >> K;
	}
	return 0;
}
