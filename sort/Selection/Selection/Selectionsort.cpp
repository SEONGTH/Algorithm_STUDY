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
/*�ּڰ��� ã�Ƽ� �������µ�
* �񱳴� ������.
* Index �����ؼ� ��ȯ�ϵ��� ��.
* �ε����� �� 3�� �ʿ���.
* �ð����⵵ O(n^2)
* �ڷᰡ �������� �����̳� �̰ų� ���̰� ����.
*/
int main() {
	int arr[5] = { 9,6,7,3,5 };
	selection_sort(arr);
	for (int q = 0; q < 5; q++) {
		cout << arr[q] << endl;;
	}
}