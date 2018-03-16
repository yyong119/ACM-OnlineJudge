#include<iostream>
#include<cstring>
using namespace std;
char text[110][2010], c, Tmp[110], u[2010];
int num1 = 0, num2 = 0, num3 = 0, order_flag = 1, L = 0;

// int strcmp(const char* str1, const char* str2) {
// 	int ret = 0;
// 	while (!(ret = *(unsigned char*)str1 - * (unsigned char*)str2) && *str1) {
// 		str1++;
// 		str2++
// 	}
// 	if (ret < 0)
// 		return -1;
// 	else if (ret > 0)
// 		return 1;
// 	return 0;
// }

void quit() {

	for (int i = 0; i < L; i++) cout << text[i] << endl;
}
void list(int num1, int num2) {

	for (int i = (num1 - 1); i <= (num2 - 1); i++) cout << text[i] << endl;
}
void ins(int num1, int num2, char *tmp) {

	for (int i = (strlen(text[num1 - 1]) - 1); i >= (num2 - 1); i--)
		text[num1 - 1][i + strlen(tmp)] = text[num1 - 1][i];
	for (int i = 0; i < strlen(tmp); i++)
		text[num1 - 1][i + num2 - 1] = tmp[i];
}
void del(int num1, int num2, int num3) {

	int R = strlen(text[num1 - 1]);
	for (int i = 0; i < (strlen(text[num1 - 1]) - num3 - num2 + 1); i++)
		text[num1 - 1][i + num2 - 1] = text[num1 - 1][i + num3 + num2 - 1];
	for (int i = 0; i < num3; i++)
		text[num1 - 1][R - 1 - i] = NULL;
}
int main() {

	for (int i = 0; i < 110; i++) {
		cin.getline(text[i], 2000);
		L++;
		if (strcmp(text[i], "******") == 0) {
			L--;
			break;
		}
	}
	while (true) {
		cin >> Tmp;
		if (strcmp(Tmp, "list") == 0) {
			cin >> num1 >> num2;
			if (num1 > num2 || num1 < 1 || num2 < 1 || num2 > L || num1 > L)
				cout << "Error!" << endl;
			else
				list(num1, num2);
		}
		else if (strcmp(Tmp, "ins") == 0) {
			char tmp[100];
			cin >> num1 >> num2;
			c = cin.get(); cin.getline(tmp, 100);
			if (num1 < 1 || num2 < 1 || num1 > L || (num2 > (strlen(text[num1 - 1]) + 1)))
				cout << "Error!" << endl;
			else
				ins(num1, num2, tmp);
		}
		else if (strcmp(Tmp, "del") == 0) {
			cin >> num1 >> num2 >> num3;
			if (num1 < 1 || num2 < 1 || num1 > L || num2 > strlen(text[num1 - 1]) || (num2 + num3) > (strlen(text[num1 - 1]) + 1))
				cout << "Error!" << endl;
			else
				del(num1, num2, num3);
		}
		else if (strcmp(Tmp, "quit") == 0)
			break;
	}
	quit();
	return 0;
}