// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define number first
// #define price second
// const int SIZE = 21000;
// int byNumberprice_to_modify[SIZE], stockNumber, commandNumber, numberToModify, priceToModify;
// pair<int, int> byRanking[SIZE];
// bool Cmp(const pair<int, int> & stock1, const pair<int, int> & stock2) {
// 	if(stock1.price == stock2.price)
// 		return (stock1.number < stock2.number);
// 	return (stock1.price > stock2.price);
// }
// int main(){
// 	ios::sync_with_stdio(false);
// 	cin >> stockNumber;
// 	for(int i = 0; i < stockNumber; ++i)
// 		cin >> byNumberprice_to_modify[i];
// 	cin >> commandNumber;
// 	char command;
// 	for(int i = 0; i < commandNumber; ++i) {
// 		cin >>command;
// 		if(command == 'M') {
// 			cin >> numberToModify>> priceToModify;
// 			byNumberprice_to_modify[numberToModify - 1] = priceToModify;
// 		}
// 		else {
// 			for(int i = 0; i < stockNumber; ++i) {
// 				byRanking[i].number = i;
// 				byRanking[i].price = byNumberprice_to_modify[i];
// 			}
// 			sort(byRanking, byRanking + stockNumber, Cmp);
// 			int request_number, number_to_cout;
// 			cin >> request_number;
// 			for(int i = 0; i < request_number; ++i) {
// 				cin >> number_to_cout;
// 				cout << byRanking[number_to_cout - 1].number + 1 << ' ';
// 			}
// 			cout << '\n';
// 		}
// 	}
// 	return 0
// }