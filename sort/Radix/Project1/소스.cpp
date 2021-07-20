#include <iostream>
#include <queue>
using namespace std;
int get_radixsort(int* arr, int size) {
	int max = 0;
	for (int i = 0; i < size; i++) { //젤큰거찾기
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	int jaresu = 1;
	while ((max / 10) > 0) {
		max = max / 10;
		jaresu*=10;
	}
	//자릿수 세기
	return jaresu;
}
void radixsort(int* arr, int size) {
	int new_arr[30] = { 0, };
	int output = 0; // 출력
	int max_jaresu = get_radixsort(arr, size);
	cout << endl  << "max" << max_jaresu << endl;

	queue<int> Q[10]; // queue 에 열개나 집어넣기

	for (int i = 1; i <= max_jaresu; i*=10) { // 10씩 곱하면서 max_jaresu까지.
		for (int j = 0; j < size; j++) { //배열 Index
			int q = 0; //num
			if (arr[j] >= i) {
				q = (arr[j] / i) % 10; // 10씩 나누기. 나머지는 버림.
			}
			Q[q].push(arr[j]); // 맞는지 보고 집어넣기.
		}
		output = 0; /*
					
					*/
		for (int e = 0; e < 10; e++) { //새로 돌리면서
			while (!Q[e].empty()) { //큐가 빌 때 까지
				arr[output] = Q[e].front(); //처음꺼 빼고
				Q[e].pop(); //지워주는것.
				output++;
			}
		}
	}
}
int main() {
	int arr[] = { 123,12,15,145,13,15,21,354,15,48,53,12,53,12,45,8,56,35,15,45,32,15,18,563,2,15,24,15,78,65 };
	int size = sizeof(arr)/4; //이번엔 여기문제 아닌데..
	radixsort(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}