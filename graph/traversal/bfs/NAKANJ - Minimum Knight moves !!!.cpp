#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 10000007
#define inf 1e18+19
#define pb push_back
#define sil(x) scanf("%lld", &x)
#define si(x) scanf("%d", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dis [] = {2, 1, -2, -1};

int bfs(string s, string d) {
	map <string, int> mp;
	map <string, int> vis;

	queue <string> q;
	q.push(s);
	mp[s] = 0;
	vis[s] = true;

	while(!q.empty()) {
		string cur = q.front();
		q.pop();

		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				int x = dis[i];
				int y = dis[j];

				if(abs(x+y) % 2 == 0) continue;

				char a = (char) (cur[0] + x);
				char b = (char) (cur[1] + y);

				if(a >= 'a' && a <= 'h' && b >= '1' && b <= '8') {
					string to = ""; to += a; to += b;
					//cout << to << endl;
					if(!vis[to]) {
						vis[to] = true;
						mp[to] = mp[cur] + 1;
						q.push(to);
					}
				}
			}
		}
	}

	return mp[d];
}


int32_t main(){
	//read();
	//write();
	//fst;
	int t;
	cin >> t;
	while(t--) {
		string s, d;
		cin >> s >> d;

		cout << bfs(s, d) << endl;
	}

	return 0;
}
