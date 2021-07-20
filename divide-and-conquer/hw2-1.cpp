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
		//left가 mid와 같아지거나
		//mid+1이 right끝까지 가버리면 끝내기 
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
    //sorted의 left 부터 right까지는 모두 정렬 된 상태임.
    for(int x= left; x <= right; x++){
        arr[x] = sorted[x];//다시 원래 배열로 재복사.
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
