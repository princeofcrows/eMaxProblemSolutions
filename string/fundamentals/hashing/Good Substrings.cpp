#include <bits/stdc++.h>

using namespace std;
map <long long, bool> dat1[1501];

int main(){
	//freopen("in.txt", "r", stdin);
	string str, alp, str2;
	long long int i, j, k, ans, c;
	cin >> str >> alp >> k;

	ans = 0;
	long long int po1 = 563;
	long long int m1 = 200000029763;
	long long int val1 = 0;

	for(i=0; i<str.length(); i++) {
		c = 0;
		val1 = 0;

		for(j=i; j<str.length(); j++) {
			int cn = 0;
			val1 = (str[j]+val1*po1)%m1;

			if(alp[str[j]-'a']=='0') c++;
			if(c>k) break;
			if(!dat1[j-i][val1]) cn++;
			if(cn) ans++;

			dat1[j-i][val1] = 1;
		}
	}

	cout << ans;
	return 0;
}
