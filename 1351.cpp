#include <cstdio>
#include <cmath>

bool IsPrime(int number) {

	int max_limit = (int)sqrt(number);
	for(int i = 2; i <= max_limit; ++i)
		if(number % i == 0)
			return false;
	return true;
}

int main() {

	int number, res1, res2;
	scanf("%d", &number);
	if(number % 2 == 0) {
		for(res1 = res2 = number / 2; true; --res1, ++res2)
			if(IsPrime(res1) && IsPrime(res2)) {
				printf("%d %d", res1, res2);
				return 0;
			}
	}
	else if(IsPrime(number - 2))
			printf("%d %d", 2, number - 2);
		else
			printf("NO");
	return 0;
}