#include <bits/stdc++.h>
#define mx 200005
using namespace std;

string str, str1;

int pi[mx], ara[mx], vis[mx];
vector <pair <int, int> > v;

void prefixfunc(){
	int n = str.length();
	int now = -1;
	pi[0] = -1;

	for(int i=1; i<n; i++) {
		while(now!=-1&&str[i]!=str[now+1]) {
			now = pi[now];
		}

		if(str[now+1]==str[i]) pi[i] = ++now;
		else pi[i] = now = -1;
	}

	memset(vis, 0, sizeof vis);
	int l;

	for(int j=0; j<n; j++) {
		ara[j+1] = 1;
	}

	for(int j=n-1; j>=0; j--) {
		l = j;
		ara[pi[l]+1] += ara[l+1];
	}

	l = n-1;
	while(pi[l]!=-1) {
		vis[pi[l]+1] = 1;
		l = pi[l];
	}

	int ans = 0;
	for(int i=1; i<mx; i++) if(ara[i]&&vis[i]) ans++;
	cout << ans+1 << endl;

	for(int i=1; i<mx; i++) if(ara[i]&&vis[i]) cout << i << " " << ara[i] << endl;
	cout << n << " " << 1 << endl;
}

int main(){
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> str) {
		prefixfunc();
	}
	return 0;
}
