#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 20000;
int stock[MAX_N + 5], query[1005];
struct stockInfo {
	int val, id;//val股价, id编号
} heap[MAX_N + 5];

void swap(stockInfo &p, stockInfo &q) {
	stockInfo tmp = p; p = q; q = tmp;
}

void adjustHeap(int index, int length) {

	for (int i = index << 1; i <= length; i <<= 1) {
		if (i + 1 <= length) {
			//右子树比左子树大
			if (heap[i].val < heap[i + 1].val) ++i;
			//或值相同右子树编号小
			else if (heap[i].val == heap[i + 1].val && heap[i].id > heap[i + 1].id) ++i;
		}
		//如果较大的子树比考察节点大,就交换
		if (heap[i].val > heap[index].val || heap[i].val == heap[index].val && heap[i].id < heap[index].id) {
			swap(heap[index], heap[i]);
			index = i;
		}
		else break;
	}
}

int main() {

	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &stock[i]);//股价
	int k; scanf("%d", &k);
	while (k--) {
		char command; scanf("\n%c", &command);
		if (command == 'M') {//修改
			int index, num; scanf("%d%d", &index, &num);
			stock[index] = num;
		}
		else {//查询
			int num, maxOrder = 0; scanf("%d", &num);
			for (int i = 1; i <= num; ++i) {
				scanf("%d", &query[i]);//读入要询问的序号
				maxOrder = max(maxOrder, query[i]);//询问中最小的数是第maxOrder大
			}
			for (int i = 1; i <= n; ++i) {
				heap[i].val = stock[i];//股价入堆
				heap[i].id = i;//编号入堆
			}

			for (int i = n >> 1; i > 0; --i) adjustHeap(i, n);//构建大根堆

			for (int i = n; i > n - maxOrder; --i) {//最小只求到第maxOrder个
				swap(heap[1], heap[i]);//把堆顶移出堆
				adjustHeap(1, i - 1);//调整为大根堆
			}

			for (int i = 1; i < num; ++i)
				printf("%d ", heap[n - query[i] + 1].id);
			printf("%d\n", heap[n - query[num] + 1].id);
		}
	}
	return 0;
}
