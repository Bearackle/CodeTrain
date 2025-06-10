#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<int> a;


vector<int> get_ans(const vector<int>& A, int K) {
	map<int, int> Hash;
	vector <int> t;
	for (int i = 0; i < A.size(); i++)
	{
		Hash[A[i]]++;
	}
	int n = Hash.size();
	if (k <= n)
	{
		for (auto i : Hash)
		{
			t.push_back(i.first);
			--i.second;
			--k;
			if (!k) break;
		}
	}
	else
	{
		for (auto &i : Hash)
		{
			t.push_back(i.first);
			--i.second;
			--k;
		}
		for (auto i : Hash)
		{
			while (i.second > 0)
			{
				t.push_back(i.first);
				--i.second;
				--k;
				if (!k) return t;
			}
		}
	}
	return t;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> k;

	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans = get_ans(a, k);

	for (const int& x : ans) cout << x << ' ';
	return 0;
}
