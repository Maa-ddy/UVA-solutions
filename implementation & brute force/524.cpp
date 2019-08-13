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
short used[20];
short prime[35] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0};
vector<int> cand;
vector<string> ans[20];

void f(int start, int max, int step){
	if (start > max){ return; }
	//cout << start << endl;
	if (step == max && prime[start + 1]){
		string temp = "";
		for (int e : cand){
			temp += to_string(e) + " ";
		}temp += to_string(start);
		ans[max].push_back(temp);
		//cout << temp << endl;
		return;
	}
	used[start] = 1;
	cand.push_back(start);
	for ( int k = 2; k < 20; k++ ){
		if (!used[k] && prime[k + start] ){
			f(k, max, step + 1);
		}
	}
	cand.pop_back();
	used[start] = 0;
}


int main(){
	FASTIO;
	for ( int k = 2; k < 20; k += 2 ){
		f(1, k, 1);
	}
	ll n;
	ll c = 1;
	ans[1].push_back("1");
	while (cin >> n){
		if (c != 1){ cout << "\n";}
		cout << "Case " << c++ << ":\n";
		for (string s : ans[n]){
			cout << s << '\n';
		}
	}
	return 0;
}
