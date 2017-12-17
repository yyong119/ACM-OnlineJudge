#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 10010;

struct Unit {
	char name[25];
	int food, wood, level;
} units[11];
int unitNumber, timeNumber;
int food[SIZE], wood[SIZE], farmer = 0, resource, foodStart = 0, woodStart = 0, foodEnd = 0, woodEnd = 0, totalFood = 0, totalWood = 0;
char type[5];

bool cmp(const Unit &unit1, const Unit &unit2) {
	return unit1.level < unit2.level;
}

int main() {
	scanf("%d", &unitNumber);
	for(int i = 0; i < unitNumber; ++i)
		scanf("%s%d%d%d", &units[i].name, &units[i].food, &units[i].wood, &units[i].level);
	sort(units, units + unitNumber, cmp);
	scanf("%d", &timeNumber);
	for(int i = 1; i <= timeNumber; ++i) {
		scanf("%s%d", &type, &resource);
		resource += farmer;
		if(type[0] == 'f'){
			totalFood += resource;
			food[foodEnd++] = resource;
		}
		else if(type[0] == 'w'){
			totalWood += resource;
			wood[woodEnd++] = resource;
		}
		for(int j = unitNumber - 1; j >= 0; --j)
			if(units[j].food <= totalFood && units[j].wood <= totalWood){
				for(int remainFood = units[j].food; remainFood > 0; remainFood -= food[foodStart], totalFood -= food[foodStart++]);
				for(int remainWood = units[j].wood; remainWood > 0; remainWood -= wood[woodStart], totalWood -= wood[woodStart++]);
				if(!strcmp(units[j].name, "farmer"))
					++farmer;
				printf("#%d: a %s was created.\n", i, units[j].name);
				break;
			}
	}
	printf("food: %d, wood: %d\n", totalFood, totalWood);
	return 0
}