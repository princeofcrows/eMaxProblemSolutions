// Unsolved

#include <bits/stdc++.h>

using namespace std;

#define mx 100005
//#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define sil(x) scanf("%lld", &x)
#define si(x) scanf("%d", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vector<int> > dp[26];

vector<int> prefixFunction(string s) {
	int n = (int)s.length();

	vector<int> pi(n);

	for (int i = 1; i < n; i++) {
		int j = pi[i-1];

		while (j > 0 && s[i] != s[j])
			j = pi[j-1];

		if (s[i] == s[j])
			j++;

		pi[i] = j;
	}

	return pi;
}

vector<vector<int> > computeAutomaton(string s) {
	s += '#';
	int n = s.size();

	vector<int> pi = prefixFunction(s);

	vector<vector<int> > aut;
	aut.assign(n, vector<int>(26));

	for (int i = 0; i < n; i++) {
		for (int c = 0; c < 26; c++) {
			if (i > 0 && 'a' + c != s[i])
				aut[i][c] = aut[pi[i-1]][c];
			else
				aut[i][c] = i + ('a' + c == s[i]);
		}
	}

	return aut;
}

int rec(int idx, int jdx, int last, string &p,  string &s, vector<vector<int> > &aut) {
	int m = p.length();
	int n = s.length();

	if(idx >= n) return 0;
	if(dp[last][idx][jdx] != -1) return dp[last][idx][jdx];

	int ret = 0;

	if (jdx < m && p[jdx] == s[idx]) {
		ret = rec(idx+1, jdx+1, s[idx] - 'a', p, s, aut);
	}

	if (jdx == m) {
		cout << idx << " " << jdx << " " << last << endl << aut[jdx-1][p[jdx-1] - 'a'] << endl;
		ret = max(ret, rec(idx, aut[jdx-1][p[jdx-1] - 'a'], last, p, s, aut) + 1);

	} else if (idx < n && p[jdx] != s[idx]) {
		if (jdx != 0)
			ret = max(ret, rec(idx, aut[jdx-1][last], last, p, s, aut));
		else {
			if(s[idx] != '?')
				ret = max(ret, rec(idx + 1, jdx, last, p, s, aut));
			else {
				for(int i=0; i<26; i++) {
					ret = max(ret, rec(idx + 1, jdx, i, p, s, aut));
				}
			}
		}
	}

	return dp[last][idx][jdx] = ret;

}

void init(int n, int m) {
	for(int l=0; l<26; l++) {
		vector <vector <int> > v;

		for(int i=0; i<=n; i++) {
			vector <int> res;
			for(int j=0; j<=m; j++) {
				res.pb(-1);
			}

			v.pb(res);
		}

		dp[l] = v;
	}
}

int kmpPatternSearch(string p, string s){
	vector<vector<int> > aut = computeAutomaton(s);
	init(s.length(), p.length());

	return rec(0, 0, 0, p, s, aut);
}

void solve(string s, string t) {
	cout << kmpPatternSearch(t, s) << endl;
}

int32_t main(){
	read();
	//write();
	fst;

	string s, t;
	while(cin >> s >> t) {
		solve(s, t);
	}
	return 0;
}
