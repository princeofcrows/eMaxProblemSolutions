#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<int> slidingWindow(vector<int>  listOfNumbers, int k){
	deque<int> q;
	vector<int> res;
	int n = listOfNumbers.size();

	for (int i = 0; i < k; i++) {
		while ((!q.empty()) && listOfNumbers[i] >= listOfNumbers[q.back()]) {
			q.pop_back();
		}

		q.push_back(i);
	}


	for (int i=k; i < n; i++) {
		res.push_back(listOfNumbers[q.front()]);

		while ((!q.empty()) && q.front() <= i - k) {
			q.pop_front();
		}


		while ((!q.empty()) && listOfNumbers[i] >= listOfNumbers[q.back()]) {
			q.pop_back();
		}

		q.push_back(i);
	}

	res.push_back(listOfNumbers[q.front()]);

	return res;
}

int solve(vector<int> v, int k) {
	vector<int> res = slidingWindow(v, k);

	int ret = 100000000;

	for(auto u: res) ret = min(ret, u);

	return ret;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);

	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	while(q--) {
		int k;
		cin >> k;

		cout << solve(v, k) << "\n";
	}
}
