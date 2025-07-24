#include<iostream>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

int main(){
    int n = 16;
    string s;

    while(n > 0){
        s += n % 2 == 0 ? '0' : '1';
        n /= 2;
    }
    reverse(s.begin(),s.end());
    cout << s;
}