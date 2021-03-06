//https://www.acmicpc.net/problem/10815
#include <iostream>
using namespace std;
int *sorted;
int *answer;
int arr[50]; //상근이 숫자카드
int n, m;

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }
    if(i > mid){
        for(int q = j; q <= right; q++){
            sorted[k++] = arr[q];
        }
    }
    else{
        for(int w = i; w<= mid; w++){
            sorted[k++] = arr[w];
        }
    }
    for(int x = left; x <=right; x++){
        arr[x] = sorted[x];
    }
}

void merge_sort(int arr[],int left,int right){
	if (left<right){
		int mid = (left+right)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int search(int key){
    int first = 0;
    int end = n-1;
    int mid = 0;
    int ret = 0;

    while(first <= end){
        mid = (first + end)/2;
        if(key == arr[mid]){
            ret = 1;
            break;
        }
        else{
            if(key < arr[mid]){
                end = mid -1;
            }
            else{
                first = mid + 1;
            }
        }
    }
    return ret;
}

int main(){
    cin >> n;
    sorted = new int[n];

    int arrA[50] = {0,};//문제의 숫자카드
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;
    answer = new int[m];
    for(int j = 0; j < m; j++){
        cin >> arrA[j];
    }
    merge_sort(arr, 0, n-1);

    for(int k = 0; k < m; k++){
        answer[k] = search(arrA[k]);
    }
    for(int q = 0; q < m; q++){
        cout << answer[q] << " ";
    }
    delete sorted;
    delete answer;
    return 0;
}
/*
//https://www.acmicpc.net/problem/10815
#include <iostream>
using namespace std;
int *sorted;

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }
    if(i > mid){
        for(int q = j; x <= mid; x++){
            sorted[k++] = arr[x];
        }
    }
    else{
        for(int w = i; w<= mid; w++){
            sorted[k++] = arr[x];
        }
    }
    for(int x = left; x <=right; x++){
        arr[x] = sorted[x];
    }
}

void mergesort(int arr[], int left, int right){
    int mid;
    if(left < right){
        mid = (left + right)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
int main(){
    int n, m, *arrA, *arrB;
    cin >> n;
    arrA = new int[a];
    arrB = new int[b];
    for(int i = 0; i < n ; i++){
        cin>>arrA[i];
    }
    cin >> m;
    for(int j = 0; j < m ; j++){
        cin>>arrB[i];
    }
    mergesort(arrA, 0, n-1);
    mergesort(arrB, 0, m-1);

    for(int i = 0; i < m; i++){
        int first = 0;
        int end = n - 1;

        while(first <= end){
            int mid = (first + end) / 2;
            if(arrA[mid] == b[i]){
                sorted[i] = 1;
                break;
            }
            if(a[mid] > b[i]){
                end = mid - 1;
            }
            else{
                first = mid + 1;
            }
        }
    }
    for(int i = 0; i < m ; i++){
        cout << sorted[i] << ' ';
    }
    cout << '\n';
    return 0;
}
*/
