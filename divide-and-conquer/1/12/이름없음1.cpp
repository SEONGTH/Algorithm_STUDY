#include<iostream>
using namespace std;

int *sorted;

//void merge(int*, int, int, int);


void merge(int arr[], int left, int mid, int right){
    int i, j , k, x;
    i =left; //sub1 start
    j =mid + 1; //sub2 start
    k =left; //sub1+sub2 start

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }
    if(i>mid){
        for(x = j ; x<=right; x++){
            sorted[k++] = arr[x];
        }
    }
    else{
        for(x = i; x <=mid; x++){
            sorted[k++] = arr[x];
        }
    }
    //sorted�� left ���� right������ ��� ���� �� ������.
    for(x= left; x <= right; x++){
        arr[x] = sorted[x];//�ٽ� ���� �迭�� �纹��.
    }
}

void mergesort(int arr[], int left, int right){ 
    //left right�� �� �迭���� �����ִ� ����.
    int mid;
    if(left<right){ //��ĭ¥�� ������ �����̵�. ��ĭ¥������ merge
        mid = (left+right)/2; //�߰���Ƽ�
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
int main(){
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    sorted = new int[10]();
    mergesort(arr, 0, 9);
    for(int x= 0 ; x < 10; x++){
        cout<<arr[x]<< " ";
    }
    cout << endl;
    delete[] sorted;

    return 0;
}
