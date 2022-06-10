#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005
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

#include <string>
using namespace std;


vector<int> rabinKarp(string const& s, string const& t) {
	const int p = 31;
	const int m = 1e9 + 9;
	int sLen = s.length(), tLen = t.length();

	vector<long long> pPow(max(sLen, tLen));
	pPow[0] = 1;

	for (int i = 1; i < (int)pPow.size(); i++)
		pPow[i] = (pPow[i-1] * p) % m;

	vector<long long> h(tLen + 1, 0);
	for (int i = 0; i < tLen; i++)
		h[i+1] = (h[i] + (t[i] - 'a' + 1) * pPow[i]) % m;

	long long hashS = 0;
	for (int i = 0; i < sLen; i++)
		hashS = (hashS + (s[i] - 'a' + 1) * pPow[i]) % m;

	vector<int> occurences;
	for (int i = 0; i + sLen - 1 < tLen; i++) {
		long long cur_h = (h[i+sLen] + m - h[i]) % m;
		if (cur_h == hashS * pPow[i] % m)
			occurences.push_back(i+1);
	}

	return occurences;
}


void printRes(vector<int> v) {
	if( v.size() == 0) cout << "Not Found";
	else {
		cout << v.size() << "\n";
		for(auto u: v) cout << u << " ";
	}
	cout << "\n\n";
}

void solve(string s, string t) {
	printRes(rabinKarp(s, t));
}


int main() {
	//read();
	// write();
	int t;
	cin >> t;
	while(t--) {
		string s, t;
		cin >> t >> s;
		solve(s, t);
	}
}
