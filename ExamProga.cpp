#include <iostream>
#include <sstream>
template <typename T>
void swap(T &a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void Heapify(int* arr, size_t n, size_t idx) {
	while (true) {
		size_t top = idx;
		size_t chado1 = idx * 2 + 1;
		size_t chado2 = idx * 2 + 2;
		if (chado1 < n && arr[top] < arr[chado1]) {
			top = chado1;
		}
		if (chado2 < n && arr[top] < arr[chado2]) {
			top = chado2;
		}
		if (top == idx) {
			break;
		}
		swap(arr[top], arr[idx]);
		idx = top;
	}
}
void HeapSort(int* arr, size_t n) {
	for (int i = (n / 2) - 1; i >= 0; --i) {
		Heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; --i) {
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}
int main() {
	int* arr = new int[10] {10, 2, 7, 4, 1, 3, 8, 6, 5, 9};
	HeapSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		std::cout << arr[i] << " ";
	}
	return 0;
}