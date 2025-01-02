#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define un unsigned
#define all(a) a.begin(),a.end()
#define I128 __int128//if NewCode or Codeforce
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define frep(i, a, b) for(int i = b; i >= a; i--)
//#define int long long;
//提交：ZT
//参考了羊神的代码写的……太菜了……
using namespace std;
typedef unsigned us;
typedef long long ll;
const int N = 1e3 + 5;

int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
char dic[4] = {'D', 'L', 'R', 'U'};

int n, m, k;
int rX, rY;
char mp[N][N];
int dis[N][N];
struct node{
	int x, y;
};
queue<node> que;

bool poscheck(int x, int y){
	if(mp[x][y] == '*')return false;
	else if(x < 1 || y < 1 || x > n || y > m)return false;
	return true;
}

void bfs(int X, int Y){
	int l = 0, r = 1;
	que.push({X, Y});
	dis[X][Y] = 0;
	while(l < r){
		int x = que.front().x, y = que.front().y;
		l++;
		rep(i, 0, 3){
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if(poscheck(nx, ny) && dis[nx][ny] == -1){
				dis[nx][ny] = dis[x][y] + 1;
				que.push({nx, ny});
				r++;
			}
		}
		que.pop();
	}
	
	bool flag = false;
	while(k){
		rep(i, 0, 3){
			int nx = rX + dir[i][0], ny = rY + dir[i][1];
			if(poscheck(nx, ny) && dis[nx][ny] <= k - 1){
				cout << dic[i];
				flag = true;
				rX = nx, rY = ny;
				break;
			}
		}
		if(!flag){
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		k--;
	}
}

void solve() {
	cin >> n >> m >> k;
	memset(dis, -1, sizeof(dis));
	rep(i, 1, n){
		rep(j, 1, m){
			cin >> mp[i][j];
//			dis[i][j] = -1;
			if(mp[i][j] == 'X')rX = i, rY = j;
		}
	}	
	if(k & 1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	bfs(rX, rY);
}

int main() {
	ios;
	int T = 1;
	//cin >> T; 
	while (T--)
	solve();
	return 0;
}
