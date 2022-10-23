#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;
//1449 백준
int main() {
	fast;
	int N, L, A;
	cin >> N >> L;
	vector<int> Array;
	for (int i = 0; i < N; i++) {
		cin >> A;
		Array.push_back(A);
	}
	if (L == 1) {
		cout << N;
		return 0;
	}
	sort(Array.begin(), Array.end());
	int sum = 0, length;
	for (int i = 0; i < N;) {
		int j = 1;
		int flag = 0;
		if (i + j == N) {
			sum++;
			break;
		}
		while (1) {
			if (i + j == N) {
				sum++;
				flag = 1;
				break;
			}
			length = Array[i + j] - Array[i] + 1;
			if (length == L) {
				sum++;
				i += 1 + j;
				break;
			}
			else if (length > L) {
				sum++;
				i += j;
				break;
			}
			else j++;
		}
		if (flag == 1) break;
	}
	cout << sum;
}
