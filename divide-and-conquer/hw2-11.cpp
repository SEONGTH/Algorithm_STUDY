//https://www.acmicpc.net/problem/1517
#include <iostream>
using namespace std;
typedef long long ll; //!!!! �־��� ��� 25�ﰳ����  

ll count= 0; //����߻��ߴ���
int arr[505050] = {0,};
int sorted[505050] = {0,};



void merge(int left, int mid, int right){
    int i, j, k;
    i = k = left;
    //c��� ������ right-most. �����ʺ��� �ҷ��ͼ� ���ʿ� ����.
    j = mid +1;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){ //�������� ��ȯ���� �ʽ��ϴ�.
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
            count += (ll)(mid - i + 1); // ������ŭ
            //���⵵ type-casting ��������� ���־�� ��.  
        }
    }
    //while(i>mid && j<= right){ //compact�ϳ� �ð��� �� �ɸ�
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
