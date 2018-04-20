#include <cstdio>
#include <iostream>
#define SIZE 200000
using namespace std;
int total_node_number, branch_number, heap[SIZE], zero_number, heap_size, node_number, tmp;
long long result = 0;

void UpdateHead() {
	for (int i = 1, j = 2; j < heap_size; i = j, j = i << 1) {
		if (j + 1 < heap_size && heap[j + 1] < heap[j]) ++j;
		if (heap[j] >= heap[i]) break;
		heap[i] ^= heap[j] ^= heap[i] ^= heap[j];
	}
}

void UpdateTail() {

	for (int j = heap_size - 1, i = j >> 1; j > 1 && heap[i] > heap[j]; j = i, i >>= 1)
		heap[i] ^= heap[j] ^= heap[i] ^= heap[j];
}

int main() {

	scanf("%d%d", &total_node_number, &branch_number);
	zero_number = ((branch_number - 1) - (total_node_number - 1) % (branch_number - 1)) % (branch_number - 1);
	for (heap_size = 1; heap_size <= zero_number; ++heap_size)
		heap[heap_size] = 0;
	for (int k = 0; k < total_node_number; ++k) {
		scanf("%d", &heap[heap_size++]);
		UpdateTail();
	}
	while (heap_size > 2) {
		node_number = 0;
		for (int k = 0; k < branch_number; ++k) {
			node_number += heap[1];
			heap[1] = heap[--heap_size];
			UpdateHead();
		}
		result += node_number;
		heap[heap_size++] = node_number;
		UpdateTail();
	}
	cout << result;
	return 0;
}
