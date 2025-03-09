#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define frep(i, a, b) for(int i = b; i >= a; i--)
#define pb push_back
#define Deb(a) cout << a << endl;
#define lo(x) -x & x
#define mem(a, b) memset(a, b, sizeof(a));
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<int, long> pil;
typedef pair<long, int> pli;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
using un = unsigned;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int N = 1e6 + 5;
const int M = 1e6 + 2;
const ll Linf = 0x3f3f3f3f3f3f3f3f;
const int Iinf = 0x3f3f3f3f;
int __ = 1;
//#define int ll
//#define double 	long double
ll ksm(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1)res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int k, mx, n;
//char s[N];
string s;
vector<pii> v;

bool check(int mid){
	if(mid < mx)return false;
	int cnt = 1;
	vector<pii> len;
	len.pb(v[0]);
	for(int i = 1; i < n; i++){
		if(len.back().first + v[i].first > mid){
			cnt++; len.pb(v[i]);
		} else{
			len.back().first += v[i].first; 
		}
	}
	return cnt <= k;
}

void solve(){
	cin >> k;
	cin.ignore();
	getline(cin, s);
	int siz = 0, sta = 0;
	for(int i = 0; i <= 1e6 + 2; i++){
		siz = i; if(s[i] == 0)break;
	}
	for(int i = 0; i <= siz; i++){
		if(s[i] == '-' || s[i] == ' ' || s[i] == 0){
			int len = i - sta + 1;
			if(i == siz)len--;
			sta = i + 1;
			mx = max(mx, len);
			if(s[i] == '-')v.pb({len, 1});
			else if(s[i] == ' ')v.pb({len, -1});
			else v.pb({len, 0});
		}
	}
	
	n = v.size();
	int l = 0, r = 1e6 + 5;
	int ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid))r = mid - 1;
		else		  l = mid + 1;
	}
	
	cout << l << '\n';
}

signed main(){
	ios;
//	cin >> __;
	while(__--)
		solve();
	return 0;
}
