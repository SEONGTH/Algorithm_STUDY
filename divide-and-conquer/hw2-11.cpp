//https://www.acmicpc.net/problem/1517
#include <iostream>
using namespace std;
typedef long long ll; //!!!! 최악의 경우 25억개여서  

ll count= 0; //몇번발생했는지
int arr[505050] = {0,};
int sorted[505050] = {0,};



void merge(int left, int mid, int right){
    int i, j, k;
    i = k = left;
    //c언어 대입은 right-most. 오른쪽부터 불러와서 왼쪽에 복사.
    j = mid +1;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){ //같을때도 교환하지 않습니다.
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
            count += (ll)(mid - i + 1); // 남은만큼
            //여기도 type-casting 명시적으로 해주어야 함.  
        }
    }
    //while(i>mid && j<= right){ //compact하나 시간은 더 걸림
        //sorted[k++] = arr[j++];
    //}
    if(i > mid){
        while(j<= right){
            sorted[k++] = arr[j++];
        }
    }
    else{
        while(i<=mid){
            sorted[k++] = arr[i++];
        }
    }
    //sort_completed.

    for(int x = left; x <= right; x++){
        arr[x] = sorted[x];

    }
    return;
}


void mergesort(int left, int right){
    int mid;
    if(left < right){
        mid = ((left + right)/2);
        mergesort(left , mid);
        mergesort(mid+1, right);
        merge(left, mid, right);
    }
    return;
}
int main(){
    int n = 0;
    cin >> n;

    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    mergesort(0, n-1);

    cout << count;
    return 0;
}
