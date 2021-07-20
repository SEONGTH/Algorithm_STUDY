#include <iostream>
using namespace std;
# define max 100
void counting_sort(int* arr, int size) { //�迭�� �迭ũ�⸦ �Ѱܹ���
	int count[max] = { 0, }; //100�������� �ްڽ�
	for (int i = 0; i < max; i++) {
		count[i] = 0; // �ʱ�ȭ 
	}
	for (int i = 0; i < size; i++) {
		count[arr[i]]++; // �������� 
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << " "<< i;
		} // ���
	}
}
int main() {
	int arr[] = { 1,1,0,1,0,2,3,4,5,1,1,5,4,3,2,5,4,1,1,4,5,2,3,3,2,1,4,4,1,2 };
	int size = sizeof(arr)/4 ; //ũ�� �� �迭ũ�� �Դϴ�.
	//sizeof(arr) -> �޸�ũ��
	//cout << size << endl;
	counting_sort(arr, size);
	return 0;
}