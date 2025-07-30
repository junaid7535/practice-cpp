#include<iostream>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

bool isPrime(int num){
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int solve(vector<int>&nums,int index,int target){
    if(target == 0) return 0;
    if(index >= nums.size() || target < 0) return INT_MAX;

    int include = solve(nums,index,target - nums[index]);
    if(include != INT_MAX) include += 1;

    int exclude = solve(nums,index+1,target);

    return min(include,exclude);
}

int main(){
    int n = 11,m = 3;
    vector<int>nums,nums1;

    for(int i = 2; i <= n; i++){
        if(isPrime(i)){
            nums.push_back(i);
        }
    }
    int i = 0;
    while(m--){
        nums1.push_back(nums[i]);
        i++;
    }
    cout << solve(nums1,0,n);
}