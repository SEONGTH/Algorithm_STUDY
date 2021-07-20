//https://www.acmicpc.net/problem/11728
#include <iostream>
using namespace std;

//#define MAX 10000001 ���������� �鸸 ������
int *arr;

void mergesort(int arrA[], int arrB[], int left, int right){
    //left = end of first arrayA
    //right = end of second arrayB
    int i, j, k;
    i = j = k = 0;
    while(i <= left && j <= right){
        //arrA�� ������ ���ų� arrB�� ������ �������� �ݺ�
        if(arrA[i] <= arrB[j]){
            arr[k++] = arrA[i++];
        }
        else{
            arr[k++] = arrB[j++];
        }
    }
    while(i <= left){
        arr[k++] = arrA[i++];
    }
    while(j <= right){
        arr[k++] = arrB[j++];
    }
}

int main(){
    int a, b;
    //a -> size of arrA
    //b -> size of arrB
    int arrA[1000000] = {0,};
    int arrB[1000000] = {0,};
    
    ios_base::sync_with_stdio(false); //stdio
    cin.tie(NULL);//cin�̶� cout ������ Ǭ��. 
    
    cin >> a >> b;

    arr = new int[a + b];

    for(int i = 0; i < a; i++){
        cin >> arrA[i];
    }
    for(int j = 0; j < b; j++){
        cin >> arrB[j];
    }
    mergesort(arrA, arrB, a-1, b-1);
    for(int k = 0; k < a + b; k++){
        cout << arr[k] <<" ";
    }
    delete arr;
    return 0;
}




