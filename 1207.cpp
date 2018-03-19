#include <cstdio>
using namespace std;

class queue {
private:
	int *data, front, back, maxSize;

	void doubleSpace() {
		int *tmp = new int[maxSize << 1];
		for (int i = 1; i < maxSize; ++i)
			tmp[i] = data[(front + i) % maxSize];
		front = 0;
		back = maxSize - 1;
		maxSize <<= 1;
		delete [] data;
		data = tmp;
	}
public:
	queue(int initSize = 10) : maxSize(initSize), front(0), back(0) {
		data = new int[maxSize];
	}
	~queue() {
		delete [] data;
	}
	void enQueue(int n) {
		if ((back + 1) % maxSize == front) doubleSpace();
		back = (back + 1) % maxSize;
		data[back] = n;
	}
	int deQueue() {
		front = (front + 1) % maxSize;
		return data[front];
	}
	int getHead() {
		return data[(front + 1) % maxSize];
	}
	bool isEmpty() {
		return front == back;
	}
};

int main() {

	int N; scanf("%d", &N);
	queue q0, q1;
	int carType, arriveTime;
	int sum0 = 0, sum1 = 0, cnt0 = 0, cnt1 = 0, timer = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &carType, &arriveTime);
		if (carType == 0) {
			q0.enQueue(arriveTime);
			++cnt0;
		}
		else {
			q1.enQueue(arriveTime);
			++cnt1;
		}
	}
	for (timer = 0; !q0.isEmpty() || !q1.isEmpty(); timer += 10) {
		int ship = 0;
		for (; ship < 8 && !q0.isEmpty() && q0.getHead() <= timer; ++ship)
			sum0 += timer - q0.deQueue();
		for (; ship < 10 && !q1.isEmpty() && q1.getHead() <= timer; ++ship)
			sum1 += timer - q1.deQueue();
		for (; ship < 10 && !q0.isEmpty() && q0.getHead() <= timer; ++ship)
			sum0 += timer - q0.deQueue();
	}
	printf("%.3f %.3f\n", double(sum0) / cnt0, double(sum1) / cnt1);
	return 0;
}
