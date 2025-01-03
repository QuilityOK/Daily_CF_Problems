#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define frep(i, a, b) for(int i = b; i >= a; i--)
typedef long long ll;
using un = unsigned;
const int N = 2e5 + 5;


int sit = 0;
struct node{
	int x, y;
	char c;
	bool operator<(const node &t){
		if(x == t.x)return y > t.y;
		else return x > t.x;
	}
};
node a[4], b[4];//first->min, secon->max;

int check(){
	if(a[1].x == a[2].x + a[3].x && a[2].y == a[3].y && a[1].x == a[1].y + a[2].y)return 3;
	else if(a[1].x == a[1].y + a[2].x && a[1].x == a[2].y + a[3].y && a[2].x == a[3].x)return 4;
	else if(a[1].x == a[2].x && a[1].x == a[3].x && a[1].y + a[2].y + a[3].y == a[1].x)return 1;
	else if(a[1].x == a[1].y + a[3].x && a[1].x == a[2].x + a[3].y)return 2;
	else return 0;
}

void solve(){
	rep(i, 1, 3){
		cin >> a[i].x >> a[i].y;
		a[i].c = 'A' + i - 1;
		if(a[i].x < a[i].y)swap(a[i].x, a[i].y);
		b[i] = a[i];
	}
	sort(a + 1, a + 4);
	
//	rep(i, 1, 3){
//		cout << a[i].x << ' ' << a[i].y << ' ' << a[i].c << endl;
//	}
	
	sit = check();
	if(sit == 0){
		cout << -1 << endl;
	}
	else if(sit == 1){
		cout << a[1].x << endl;
		rep(i, 1, 3) a[i] = b[i];
		rep(i, 1, 3){
			rep(j, 1, a[i].y){
				rep(k, 1, a[i].x){
					cout << a[i].c;
				}
				cout << endl;
			}
		}
	}
	else{
		cout << a[1].x << endl;
		if(sit == 4 && a[2].c > a[3].c)swap(a[2], a[3]);
		rep(i, 1, a[1].y){
			rep(j, 1, a[1].x) cout << a[1].c;
			cout << endl;
		}
		rep(i, 1, a[1].x - a[1].y){
			rep(j, 1, a[1].x){
				if(sit != 4 && j <= a[2].x)cout << a[2].c;
				else if(sit == 4 && j <= a[2].y)cout << a[2].c;
				else cout << a[3].c;
			}
			cout << endl;
		}
	}
}

signed main(){
	ios;
	int T = 1;
	//cin >> T;
	while(T--)
		solve();
	return 0;
}
