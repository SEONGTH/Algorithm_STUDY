#include <iostream>
using namespace std;


void bubblesort(int arr[]) {
	int temp = 0;

	for (int i = 0; i < 5; i++) { //n
		for (int j = 0; j < i; j++) { //n-1
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
/*
* 처음엔 n개를 비교함.
* 그다음엔 n-1개 비교함.
* ...
* O(n^2)
*/
int main() {
	int arr[5] = { 7,4,5,1,3 };
	bubblesort(arr);
	for (int w = 0; w < 5; w++) {
		cout << arr[w];
	}
}