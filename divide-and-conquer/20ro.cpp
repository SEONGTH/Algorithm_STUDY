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
        //ù��°�迭�� �迭�߰��� ������ ���ų�
        //�ι�°�迭�� ���������� �� �� ���� �ݺ�

        if(arr[i] <= arr[j]){
            //ù��°�迭������ �ι�°�迭���� �۾Ƽ� 
            //ù�迭���� �� �Ҹ��ϸ� �״������� �׳� i ����
            //���� ���� ���
            sorted[k++] = arr[i++];
        }
        else{
            //�װ� �ƴϸ� �ι�° �迭��ŭ�Դϴ�.
            sorted[k++] = arr[j++];
        }

    }
    if(i > mid){ //���� �迭1�� ������� Ŭ ��쿣
        for(int x = j; x <= mid ; x++){ 
            sorted[k++] = arr[x];
            //�ι�° �迭�� ���� �ɵ��մϴ�.
        }
    }
    else{
        //�ƴԸ���
        for(int x = i; x <= mid; x++){
            sorted[k++] = arr[x];
        }
    }
    //sorted�� left ���� right ���� ��� ���ĵ� ������ ���
    for(int x = left; x <= right; x++){
        arr[x] = sorted[x];
        //�ٽÿ��� �迭�� �� ����
    }
}

void mergesort(int arr[], int left, int right){
    //left right�� �� �迭���� ���� �ִ� ����
    int mid;
    if(left < right){
        //��ĭ¥���� ������ ����. ��ĭ���� merge
        mid = (left + right)/2; //�߰����
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right); //����� ����
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

    for(int k = 0 ; k < 20; k++){ //���¹�ȣ���� �ƴ����� üũ�մϴ�. �ߺ� �� �Ȱ����ϴ�.
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
        //�ִ��� endl�� ����. �ӵ� ������ �ֹ���.
    }
    for(int e = 0; e < 20; e++){
        if(usernum == userarr[e]){
            cout<<endl <<"After your number is here : " << e+1<< endl;
        }
    }
    delete[] sorted;
    return 0;
}
