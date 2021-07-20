//https://www.acmicpc.net/problem/11728
#include <iostream>
using namespace std;

//#define MAX 10000001 전역변수는 백만 못넘음
int *arr;

void mergesort(int arrA[], int arrB[], int left, int right){
    //left = end of first arrayA
    //right = end of second arrayB
    int i, j, k;
    i = j = k = 0;
    while(i <= left && j <= right){
        //arrA의 끝까지 가거나 arrB의 끝까지 갈때까지 반복
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
    int a, b,*arrA,*arrB, ans;
    //a -> size of arrA
    //b -> size of arrB
    ios_base::sync_with_stdio(false); //stdio
    cin.tie(NULL);//cin이랑 cout 묶음을 푼다. 
    
    cin >> a >> b;
    ans = a + b;

    arr = new int[a + b];
    arrA = new int[a];
    arrB = new int[b];

    for(int i = 0; i < a; i++){
        cin >> arrA[i];
    }
    for(int j = 0; j < b; j++){
        cin >> arrB[j];
    }
    mergesort(arrA, arrB, a-1, b-1);
    for(int k = 0; k < ans; k++){
        cout << arr[k] <<" ";
    }
    delete arr;
    delete arrA;
    delete arrB;
    return 0;
}
