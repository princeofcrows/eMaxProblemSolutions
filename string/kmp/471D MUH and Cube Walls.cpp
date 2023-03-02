#include <bits/stdc++.h>

using namespace std;

#define mx 300005
#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define f first
#define s second

int ara[mx], S[mx], T[mx], pi[mx];


void pf(int n){
	int now;
	pi[0] = now = -1;

	int l = n;

	for(int i=1; i<l; i++) {
		while(now!=-1 && S[now+1]!=S[i]) now = pi[now];

		if(S[now+1]==S[i]) pi[i] = ++now;
		else pi[i] = now = -1;
	}
}

int kmp(int n, int m){
	int now, ans;
	now = -1;
	pf(n);

	int k = m;
	ans = 0;

	for(int i=0; i<k; i++) {
		while(now!=-1 && S[now+1]!=T[i]) now = pi[now];

		if(S[now+1]==T[i]) ++now;
		else now = -1;

		if(now==n-1) {
			ans++;
			now = pi[now];
		}
	}
	return ans;
}

int32_t main(){
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;

	while(cin >> n >> m ) {
		for(int i=0; i<n; i++) {
			cin >> ara[i];
		}
		for(int i=0; i<(n-1); i++) {
			T[i] = ara[i+1] - ara[i];
		}
		for(int i=0; i<m; i++) {
			cin >> ara[i];
		}
		for(int i=0; i<(m-1); i++) {
			S[i] = ara[i+1] - ara[i];
		}
		if(m==1) {
			cout << n << endl;
			continue;
		}
		cout << kmp(m-1, n-1);
	}
	return 0;
}
