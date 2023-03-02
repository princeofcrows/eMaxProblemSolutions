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

int dp[88][88];
string str;

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

vector<int> kmpPatternSearch(string p, string s){
	int m = p.length();
	int n = s.length();

	vector<int> pi = prefixFunction(p);
	vector<int> res;

	int i = 0;
	int j = 0;

	while (i < n) {
		if (p[j] == s[i]) {
			j++; i++;
		}

		if (j == m) {
			res.push_back(i - j);
			j = pi[j - 1];
		}

		else if (i < n && p[j] != s[i]) {
			if (j != 0)
				j = pi[j - 1];
			else
				i = i + 1;
		}
	}

	return res;
}


string gen(string alp, int sh, string word) {
	map <char, char> mappedAlphabet;
	string shiftedString = "";

	for(int i=0; i<alp.length(); i++) {
		mappedAlphabet[alp[i]] = alp[(i + sh) % alp.length()];
	}

	for(auto c: word) shiftedString += mappedAlphabet[c];

	return shiftedString;
}

void solve(string a, string s, string w) {
	vector <int> res;

	for(int sh=0; sh<a.length(); sh++) {
		string shiftedString = gen(a, sh, w);

		vector <int> pos = kmpPatternSearch(shiftedString, s);

		if(pos.size() == 1) res.pb(sh);
	}

	if(res.size() == 1) {
		cout << "unique:";

		for(auto u: res) cout << " " << u;
	} else if(res.size() > 1) {
		cout << "ambiguous:";

		for(auto u: res) cout << " " << u;
	} else {
		cout << "no solution";
	}

	cout << "\n";
}

int32_t main(){
	//read();
	//write();

	fst;
	int t;
	cin >> t;
	while(t--) {
		string w, s, a;
		cin >> a >> w >> s;

		solve(a, s, w);
	}
	return 0;
}
