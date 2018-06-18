#include <bits/stdc++.h>
using namespace std;

string tmp, out;
stack<int> st;
int f, f1, n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
//	freopen("d:\\a.txt", "r", stdin);
	cin >> n;
	while (cin >> tmp) {
		if (tmp == "pair") {
			if (!st.empty() && st.top() == 2) {
				out.push_back('>');
				st.pop();
			}
			if (!st.empty() && st.top() == 1) {
				out.push_back(',');
			}
			if (!st.empty()) {
				int t = st.top();
				st.pop();
				st.push(t + 1);
			}
			st.push(0);
			out.append("pair<");
		} else {
			if (!st.empty() && st.top() == 2) {
				out.push_back('>');
				st.pop();
			}
			if (!st.empty() && st.top() == 1) {
				out.push_back(',');
			}
			int t = st.top();
			st.pop();
			st.push(t + 1);
			out.append("int");
		}
	}
	while (!st.empty() && st.top() == 2) {
		out.push_back('>');
		st.pop();
	}
	if (!st.empty()) {
		cout << "Error occurred";
		return 0;
	}
	cout << out;
}
