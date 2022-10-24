#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;
int main() {
	fast;
	vector<string> room;
	string a;
	for (int i = 0; i < 101; i++) a += ' ';
	for (int i = 0; i < 101; i++) room.push_back(a);
	int X = 50, Y = 50;
	room[X][Y] = '.';
	int length;
	cin >> length;
	vector<char> Array;
	char Rotate;
	for (int i = 0; i < length; i++) {
		cin >> Rotate;
		Array.push_back(Rotate);
	}
	char Ro[4] = {'S','W','N','E'};
	int Su = 0;
	for (int i = 0; i < length; i++) {
		if (Array[i] == 'L') {
			Su--;
			if (Su < 0) Su = 3;
		}
		else if (Array[i] == 'R') {
			Su++;
			if (Su % 4 == 0) Su = 0;
		}
		else {
			if (Ro[Su] == 'S') X++;
			else if (Ro[Su] == 'W') Y--;
			else if (Ro[Su] == 'N') X--;
			else Y++;
			room[X][Y] = '.';
		}
	}
	int Xx1, Yy1, flag = 0;
	int Xx2, Yy2;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (room[i][j] == '.') {
				if (flag == 0) {
					Xx1 = i;
					Yy1 = j;
					Xx2 = i;
					Yy2 = j;
					flag = 1;
				}
				if (j < Yy1) Yy1 = j;
				if (i > Xx2) Xx2 = i;
				if (j > Yy2) Yy2 = j;
			}
		}
	}
	for (int i = Xx1; i <= Xx2; i++) {
		for (int j = Yy1; j <= Yy2; j++) {
			if (room[i][j] != '.') cout << '#';
			else cout << room[i][j];
		}
		cout << endl;
	}
}