#include <iostream>
using namespace std;
int *sorted;
int *usernum;

void merge(int arr[], int left, int mid, int right){
    int i , j , k;
    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right){
        //첫번째배열이 배열중간의 끝까지 오거나
        //두번째배열이 우측끝까지 갈 때 까지 반복

        if(arr[i] <= arr[j]){
            //첫번째배열값들이 두번째배열보다 작아서 
            //첫배열값들 다 소모하면 그다음부턴 그냥 i 이후
            //부터 세는 경우
            sorted[k++] = arr[i++];
        }
        else{
            //그게 아니면 두번째 배열만큼입니다.
            sorted[k++] = arr[j++];
        }

    }
    if(i > mid){ //만약 배열1이 가운데보다 클 경우엔
        for(int x = j; x <= mid ; x++){ 
            sorted[k++] = arr[x];
            //두번째 배열만 보면 될듯합니다.
        }
    }
    else{
        //아님말고
        for(int x = i; x <= mid; x++){
            sorted[k++] = arr[x];
        }
    }
    //sorted의 left 부터 right 까지 모두 정렬된 상태인 경우
    for(int x = left; x <= right; x++){
        arr[x] = sorted[x];
        //다시원래 배열로 재 복사
    }
}

void mergesort(int arr[], int left, int right){
    //left right는 이 배열에서 보고 있는 범위
    int mid;
    if(left < right){
        //한칸짜리가 들어오면 거짓. 두칸부터 merge
        mid = (left + right)/2; //중간잡고
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right); //가운데는 ㄴㄴ
        merge(arr,left, mid, right);
    }
}


int binary_search(int usernum, int*arr){
    int return_num = 0;
    int newsize = sizeof(arr)/4;
    bool flag = false;
    int left = 0;
    int right = newsize;
    while(flag==true){
        int num = (newsize)/2;
        if(num == usernum){
            return_num = num;
            flag=true;
        }
        else{
            if(num < usernum){
                left = num+1;
                continue;
            }
            else{
                if(num==usernum){
                    return_num = num;
                    flag=true;
                }
                right = num-1;
                continue;
            }
        }
    }
}


int main(){
    int userarr[20] = {0,};
    sorted = new int[20]();
    int usernum = 0;
    int finder = 0;
    for(int i = 0; i < 20; i++){
        cout<<"enter new arr num :";
        cin>>userarr[i];
        cout<<"input number is "<<i+1 <<" "<<endl;
    }
    cout<<"now new_arr is"<<endl;
    for(int j = 0; j < 20; j++){
        cout << userarr[j] <<" ";
    }
    cout << endl;

    cout<<">>witch number you want to find :";
    cin>>usernum;

    for(int k = 0 ; k < 20; k++){ //없는번호인지 아닌지만 체크합니다. 중복 은 안골라냅니다.
        if(usernum == userarr[k]){
            cout<<"before binary search, your number location is "<<finder+1<<endl;
        }
        else{
            finder++;
        }
    }
    if(finder>19){
        cout<<"I can't find"<<endl;
        return 1;
    }
    mergesort(userarr,0,19);
    int binary_search(int usernum, int*arr);

    for(int i = 0; i < 20; i++){
        cout << userarr[i] << " ";
        //최대한 endl은 적게. 속도 저하의 주범임.
    }
    for(int e = 0; e < 20; e++){
        if(usernum == userarr[e]){
            cout<<endl <<"After your number is here : " << e+1<< endl;
        }
    }
    delete[] sorted;
    return 0;
}
