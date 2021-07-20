#include <iostream>
using namespace std;
void selection_sort(int arr[]) {
	int indexMin, temp;
	for (int i = 0; i < 5 - 1; i++) { 
		indexMin = i;
		for (int j = i + 1; j < 5; j++) {
			if (arr[j] < arr[indexMin]) {
				indexMin = j;
			}
		}
		temp = arr[indexMin];
		arr[indexMin] = arr[i];
		arr[i] = temp;
	}
}
/*최솟값을 찾아서 가져오는데
* 비교는 값끼리.
* Index 저장해서 교환하도록 함.
* 인덱스가 총 3개 필요함.
* 시간복잡도 O(n^2)
* 자료가 많아지면 버블이나 이거나 차이가 없음.
*/
int main() {
	int arr[5] = { 9,6,7,3,5 };
	selection_sort(arr);
	for (int q = 0; q < 5; q++) {
		cout << arr[q] << endl;;
	}
}