#include <iostream>
using namespace std;
# define max 100
void counting_sort(int* arr, int size) { //배열과 배열크기를 넘겨받음
	int count[max] = { 0, }; //100개까지만 받겠슴
	for (int i = 0; i < max; i++) {
		count[i] = 0; // 초기화 
	}
	for (int i = 0; i < size; i++) {
		count[arr[i]]++; // 갯수세기 
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << " "<< i;
		} // 출력
	}
}
int main() {
	int arr[] = { 1,1,0,1,0,2,3,4,5,1,1,5,4,3,2,5,4,1,1,4,5,2,3,3,2,1,4,4,1,2 };
	int size = sizeof(arr)/4 ; //크기 는 배열크기 입니다.
	//sizeof(arr) -> 메모리크기
	//cout << size << endl;
	counting_sort(arr, size);
	return 0;
}