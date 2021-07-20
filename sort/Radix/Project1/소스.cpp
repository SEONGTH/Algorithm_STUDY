#include <iostream>
#include <queue>
using namespace std;
int get_radixsort(int* arr, int size) {
	int max = 0;
	for (int i = 0; i < size; i++) { //��ū��ã��
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	int jaresu = 1;
	while ((max / 10) > 0) {
		max = max / 10;
		jaresu*=10;
	}
	//�ڸ��� ����
	return jaresu;
}
void radixsort(int* arr, int size) {
	int new_arr[30] = { 0, };
	int output = 0; // ���
	int max_jaresu = get_radixsort(arr, size);
	cout << endl  << "max" << max_jaresu << endl;

	queue<int> Q[10]; // queue �� ������ ����ֱ�

	for (int i = 1; i <= max_jaresu; i*=10) { // 10�� ���ϸ鼭 max_jaresu����.
		for (int j = 0; j < size; j++) { //�迭 Index
			int q = 0; //num
			if (arr[j] >= i) {
				q = (arr[j] / i) % 10; // 10�� ������. �������� ����.
			}
			Q[q].push(arr[j]); // �´��� ���� ����ֱ�.
		}
		output = 0; /*
					
					*/
		for (int e = 0; e < 10; e++) { //���� �����鼭
			while (!Q[e].empty()) { //ť�� �� �� ����
				arr[output] = Q[e].front(); //ó���� ����
				Q[e].pop(); //�����ִ°�.
				output++;
			}
		}
	}
}
int main() {
	int arr[] = { 123,12,15,145,13,15,21,354,15,48,53,12,53,12,45,8,56,35,15,45,32,15,18,563,2,15,24,15,78,65 };
	int size = sizeof(arr)/4; //�̹��� ���⹮�� �ƴѵ�..
	radixsort(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}