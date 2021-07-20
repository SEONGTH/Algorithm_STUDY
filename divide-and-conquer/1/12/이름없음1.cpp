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
    //sorted의 left 부터 right까지는 모두 정렬 된 상태임.
    for(x= left; x <= right; x++){
        arr[x] = sorted[x];//다시 원래 배열로 재복사.
    }
}

void mergesort(int arr[], int left, int right){ 
    //left right는 이 배열에서 보고있는 범위.
    int mid;
    if(left<right){ //한칸짜리 들어오면 거짓이됨. 두칸짜리부터 merge
        mid = (left+right)/2; //중간잡아서
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
