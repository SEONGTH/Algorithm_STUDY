#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//global Var
int n; //amounts of block.

//functions
void hanoi(int n, int a, int b, int c);

//main
int main(){
    cin >> n;
    //string s = to_string(pow(2, n));
    string a = to_string(15);
    cout << a << endl;
    //int idx = s.find('.');
    //s = s.substr(0,idx);
    //s[s.length() -1] -= 1;
    //cout << s << '\n';
    if(n<=20){
       hanoi(n,1,3,2);
    }
    return 0;
}

void hanoi(int n, int start, int end, int temp){ // n개 블럭, 시작, 목표, 임시기둥
    if(n==1){
        cout << start << " " << end << "\n";
        return;
    }
    else{
        hanoi(n-1, start, temp, end); //n 말고 모두 temp로
        cout << start << " " << end << "\n";
        hanoi(n-1, temp, end, start); //temp를 다시 end으로 보내기
    }
}

