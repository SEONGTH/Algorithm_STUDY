#include <iostream>
using namespace std;

int n = 0;
int arr[1000001];
int *sorted;

void marge(int left, int right){
	int mid = (left + right) / 2;
	int i, j, k;
	i = left;
	j = mid+1;
	k = left;

	while(i<=mid && j<=right){
		//left�� mid�� �������ų�
		//mid+1�� right������ �������� ������ 
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }
    if(i>mid){
        for(int x = j ; x<=right; x++){
            sorted[k++] = arr[x];
        }
    }
    else{
        for(int x = i; x <=mid; x++){
            sorted[k++] = arr[x];
        }
    }
    //sorted�� left ���� right������ ��� ���� �� ������.
    for(int x= left; x <= right; x++){
        arr[x] = sorted[x];//�ٽ� ���� �迭�� �纹��.
    }
}

void margesort(int left, int right){
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		margesort(left, mid);
		margesort(mid + 1, right);
		marge(left,right);
	}
}
int main() {
	cin >> n;
	sorted = new int[n];
	
	for (int i = 0; i < n; i++) {	
		cin >> arr[i];
	}
		
	margesort(0, n-1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	
    delete[] sorted;
	return 0;
}
