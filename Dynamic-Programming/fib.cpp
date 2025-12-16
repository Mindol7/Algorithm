#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    vector<int> arr;
    arr.push_back(0);

    for(int i = 1; i <= n; i++){
        if(i <= 2) arr.push_back(1);
        else {
            arr.push_back((arr[i-1] + arr[i-2]) % 1234567);
        }
    }
    return arr[n];
}

int main(){
    cout<<solution(3)<<endl; // 2
    cout<<solution(5)<<endl;
    return 0;
}