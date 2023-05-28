// unsolved

#include <bits/stdc++.h>

using namespace std;

#define mx 200005
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

struct suffix {
	int idx;
	int rank[2];
};

int comp(suffix a, suffix b) {
	return (a.rank[0] == b.rank[0]) ?
	       (a.rank[1] < b.rank[1] ? 1 : 0) :
	       (a.rank[0] < b.rank[0] ? 1 : 0);
}

vector <int> buildSuffixArray(string str) {
	int n = str.length();
	suffix suffixes[n];

	for (int i = 0; i < n; i++) {
		suffixes[i].idx = i;
		suffixes[i].rank[0] = str[i] - 'a';
		suffixes[i].rank[1] = ((i + 1) < n) ? (str[i + 1] - 'a') : -1;
	}

	sort(suffixes, suffixes + n, comp);

	int ind[n];
	for (int j = 4; j < 2 * n; j = j * 2) {
		int rank = 0;
		int prevR = suffixes[0].rank[0];

		suffixes[0].rank[0] = rank;
		ind[suffixes[0].idx] = 0;

		for (int i = 1; i < n; i++) {
			if (suffixes[i].rank[0] == prevR &&
			    suffixes[i].rank[1] == suffixes[i - 1].rank[1]
			    ) {
				prevR = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			} else {
				prevR = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}

			ind[suffixes[i].idx] = i;
		}

		for (int i = 0; i < n; i++) {
			int nextIdx = suffixes[i].idx + j / 2;
			suffixes[i].rank[1] = (nextIdx < n) ?
			                      suffixes[ind[nextIdx]].rank[0] : -1;
		}

		sort(suffixes, suffixes + n, comp);
	}

	vector <int> sa;
	for (int i = 0; i < n; i++)
		sa.push_back(suffixes[i].idx);

	return sa;
}


vector <int> kasai(string txt, vector <int> sa) {
	int n = sa.size();
	vector <int> lcp(n, 0);
	vector <int> inverseSuff(n, 0);

	for (int i = 0; i < n; i++)
		inverseSuff[sa[i]] = i;

	int k = 0;

	for (int i = 0; i < n; i++) {
		if (inverseSuff[i] == n - 1) {
			k = 0;
			continue;
		}

		int j = sa[inverseSuff[i] + 1];

		while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
			k++;

		lcp[inverseSuff[i]] = k;

		if (k > 0)
			k--;
	}

	return lcp;
}

void solve(string s, string t, int l) {
	string txt = s + "#" + t;
	vector <int> sa = buildSuffixArray(txt);
	vector <int> lcp = kasai(txt, sa);

	int n = s.length();
	vector <int> cntS(l+1, 0), cntT(l+1, 0);
	set <int> ss, st;

	for(int i=1; i<sa.size(); i++) {
		int j = sa[i-1];
		int x = lcp[i];

		if(x==0) {
			for(auto y: ss) {
				for(int i=min(y, l); i>=0; i--) {
					cntS[i]++;
				}
			}

			for(auto y: st) {
				for(int i=l; i>=0; i--) {
					if(i >= y)
						cntT[y] += cntS[i];
					else
						cntT[i] += cntS[i];
				}
			}

			for(int i=0; i<=l; i++) cntS[i] = 0;

			ss.clear();
			st.clear();
		} else {
			if(j < n ) {
				ss.insert(j);
			} else {
				st.insert(j);
			}
		}
	}

	for(auto y: ss) {
		for(int i=min(y, l); i>=0; i--) {
			cntS[i]++;
		}
	}

	for(auto y: st) {
		for(int i=l; i>=0; i--) {
			if(i >= y)
				cntT[y] += cntS[i];
			else
				cntT[i] += cntS[i];
		}
	}


	for(int i=1; i<=l; i++) {
		if(i > n) cout << 0 << " ";
		else cout << cntT[i] <<  " ";
	}

	cout << "\n";
}

int32_t main(){
	read();
	//write();
	fst;
	int q;
	cin >> q;

	while(q--) {
		string s, t;
		int l;
		cin >> s >> t >> l;
		solve(s, t, l);
	}

	return 0;
}
