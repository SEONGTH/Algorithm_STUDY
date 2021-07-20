#include <iostream>
#define SWAP(x, y) ( (x)^=(y), (y)^=(x), (x)^=(y) ) //use XOR
#define MAX 101010
//문제생김. 
int arr[MAX] = {0,};
using namespace std;
/********************************************
pivot을 찾고 pivot기준으로 정렬해주는 partition
반환값은 최종 pivot의 위치를 반환.
********************************************/
int partition(int arr[], int left, int right){
    int pivot, low, high;
    pivot = arr[left];
    cout << "now pivot : " << pivot << endl;
    low = left + 1;
    high = right;
    do{
        while(low <= right && arr[low] < pivot){
            low++;
            
            cout << "looking : "<<arr[low] << "<-- low"<<endl;
        }
        while(high >= left && arr[high] > pivot){
            high--;
            cout << "looking : "<<arr[high] << "<-- high"<<endl;
        }
        if(low < high){
        //before cross
            cout << "swap : " << arr[low] <<" , " << arr[high] << endl;
            SWAP(arr[low], arr[high]);
        }
    } while(low < high);

    if(high!=left) {
        SWAP(arr[high], arr[left]);
    }
    return high;
}
void quicksort(int arr[], int left, int right){
    if(left < right){
        int q = partition(arr, left, right);
        //1. arr[q] is sorted.
        //2. arr[left~q-1]까지는 arr[q]보다작음.
        //3. arr[q+1~right]까지는 arr[q]보다 크다.
        quicksort(arr,left, q-1);
        quicksort(arr, q+1, right);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, n-1);
    for(int j = 0 ; j < n ; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}


