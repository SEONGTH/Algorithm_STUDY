#include <iostream>
using namespace std;


int main(){
	int arr[10] = {0,}; //size : 10
    int count = 0;
    int i = 0;
    while(1){
        int n = 0;
        if(count==9){
            cout<<"stack full"<<endl;
            break;
        }
        cin>>n; //new input
        arr[i] = n;
        count++;
        i++;
        for(int j = 0; j < count; j++){
            cout << "|" << arr[j] << "|";
        }
        cout <<endl << "botton :" << arr[0] <<"/" << "top : " <<n<<endl;
    }
}
