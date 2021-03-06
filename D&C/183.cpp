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
char s[50000];
short m[300][300];
ll r,c;

string B(ll left, ll right, ll up, ll down){
	if (left > right || up > down){ return ""; }
	if (up == down && left == right){
		return m[up][left]?"1":"0";
	}
	ll midH = (left + right)/2;
	ll midV = (up + down)/2;
	string a = B(left, midH, up, midV);
	string b = B(midH + 1, right, up, midV);
	string e = B(left, midH, midV + 1, down);
	string f = B(midH + 1, right, midV + 1, down);
	string ans = a + b + e + f;
	if (ans.length() > 4){ return "D" + ans; }
	if (ans.length() <= 4){
		for ( int k = 1; (unsigned long)k < ans.length(); k++ ){
			if (ans[k] != ans[0]){ return "D" + ans; }
		}
	}
	return ans[0]=='0'?"0":"1";
}
ll idx;

void D(ll left, ll right, ll up, ll down){
	if (left > right || up > down){ return; }
	char c; cin >> c;
	if (c != 'D'){
		for ( int k = up; k <= down; k++ ){
			for ( int j = left; j <= right; j++ ){
				m[k][j] = c - '0';
			}
		}
		return;
	}
	idx++;
	ll midH = (left + right)/2;
	ll midV = (up + down)/2;
	D(left, midH, up, midV);
	D(midH + 1, right, up, midV);
	D(left, midH, midV + 1, down);
	D(midH + 1, right, midV + 1, down);
}

int main(){
	FASTIO;
	char op; cin >> op;
	while (op != '#'){
		cin >> r >> c;
		memset(m, 0, sizeof m);
		ll cnt = r*c;
		ll cur = 0;
		char cc;
		
		if (op == 'B'){
			while (cur < cnt){
				cin >> cc;
				s[cur++] = cc;
			}
			for ( int k = 0; k < r; k++ ){
				for ( int j = 0; j < c; j++ ){
					m[k][j] = s[j + c*k] - '0';
				}
			}
		}
		/*
		for ( int k = 0; k < r; k++ ){
			for ( int j = 0; j < c; j++ ){
				cout << m[k][j];
			}cout << endl;
		}
		*/
		if (op == 'B'){
			cout << "D" << right << setw(4) << r << right << setw(4) << c << '\n';//adjust the output in columns of 4 characters
			string res = B(0, c - 1, 0, r - 1);
			for ( int k = 0; (unsigned long)k < res.length(); k++ ){
				if (k && k%50 == 0){ cout << '\n';}
				cout << res[k];
			}cout << endl;
		}else{
			idx = 0;
			D(0, c - 1, 0, r - 1);
			cout << "B" << right << setw(4) << r << right << setw(4) << c << '\n';
			for ( int k = 0; k < r; k++ ){
				for ( int j = 0; j < c; j++ ){
					if ((k*c + j)>0 && (k*c + j)%50 == 0){ cout << '\n';}
					cout << m[k][j];
				}
			}cout << endl;
		}
		cin >> op;
	}
	return 0;
}
