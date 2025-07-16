#include<iostream>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

int result = INT_MAX;
void solve(vector<int>nums,int sum1,int sum2,int index){
    if(index == nums.size()){
        result = min(result,abs(sum1-sum2));
        return;
    }

    solve(nums,sum1+nums[index],sum2,index+1);
    solve(nums,sum1,sum2 + nums[index],index+1);
}

int main(){
    vector<int>nums{3, 2, 7, 4, 1};

    solve(nums,0,0,0);
    cout << result;
}