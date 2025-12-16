#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    vector<int> arr = {1,2};

    for(int i = 2; i < n; i++){
        arr.push_back((arr[i-1] + arr[i-2]) % 1000000007);   
        // cout << "Idx: " << i << " " << arr[i] << endl; 
    }
    return arr[n-1];
}

int main(){
    cout<<solution(4)<<endl; // 5
    cout<<solution(5)<<endl;
    return 0;
}