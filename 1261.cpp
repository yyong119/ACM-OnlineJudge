#include <iostream>
#include <cstring>
using namespace std;

int T;
int X, O;
int mapX[4][4], mapO[4][4];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		memset(mapX, 0, sizeof(mapX));
		memset(mapO, 0, sizeof(mapO));
		int foundX = 0, foundO = 0, full = 1;
		char tmp;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				cin >> tmp;
				if (tmp == 'X' || tmp == 'T') mapX[i][j] = 1;
				if (tmp == 'O' || tmp == 'T') mapO[i][j] = 1;
				if (tmp == '.') full = 0;
			}
		// find X
		for (int i = 0; i < 4; ++i) {
			if (mapX[i][0] && mapX[i][1] && mapX[i][2] && mapX[i][3]) {
				foundX = 1;
				break;
			}
			if (mapX[0][i] && mapX[1][i] && mapX[2][i] && mapX[3][i]) {
				foundX = 1;
				break;
			}
		}
		if (mapX[0][0] && mapX[1][1] && mapX[2][2] && mapX[3][3]) foundX = 1;
		if (mapX[0][3] && mapX[1][2] && mapX[2][1] && mapX[3][0]) foundX = 1;
		// find O
		for (int i = 0; i < 4; ++i) {
			if (mapO[i][0] && mapO[i][1] && mapO[i][2] && mapO[i][3]) {
				foundO = 1;
				break;
			}
			if (mapO[0][i] && mapO[1][i] && mapO[2][i] && mapO[3][i]) {
				foundO = 1;
				break;
			}
		}
		if (mapO[0][0] && mapO[1][1] && mapO[2][2] && mapO[3][3]) foundO = 1;
		if (mapO[0][3] && mapO[1][2] && mapO[2][1] && mapO[3][0]) foundO = 1;
		// check
		if (foundX) cout << "X won" << endl;
		else if (foundO) cout << "O won" << endl;
		else if (full && !foundX && ! foundO) cout << "Draw" << endl;
		else cout << "Game has not completed" << endl;
	}
}
