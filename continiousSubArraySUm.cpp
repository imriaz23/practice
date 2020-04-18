#include<iostream>
#include<vector>
using namespace std;
// O(n^2)  O(1)
vector<int> continiousSubArraySum(vector<int>& nums,int n,int sum){
  vector<int>ans;
  if(n<=0){
    return ans;
  }
  for(int i=0;i<n;i++){
    int curr_sum=0;
    for(int j=i;j<n;j++){
      if(curr_sum+nums[j] == sum){
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
      }
      curr_sum+=nums[j];
    }
  }
  return ans;
}

// O(n) O(1) Two pointer
vector<int> continiousSubArraySum2(vector<int>& nums,int n,int sum){
  if(n<=0){
    return {-1};
  }
  vector<int>ans;
  int left=0,right=0,curr_sum=0;
  while(left<=right && right<n){
    curr_sum+=nums[right];
    while(curr_sum<sum && right<n){
      right++;
      curr_sum+=nums[right];
    }
    while(curr_sum > sum && left<=right){
      curr_sum-=nums[left];
      left++;
    }
    if(curr_sum==sum){
      ans.push_back(left+1);
      ans.push_back(right+1);
      return ans;
    }
  }
  return {-1};
}
int main(){
  int n;
  cin >>n ;
  int sum;
  cin >> sum ;
  vector <int> nums(n);
  for(int& i : nums){
    cin >> i;
  }
  vector<int> ans;
  ans = continiousSubArraySum2(nums,n,sum);
  cout<<ans[0] << " " <<ans[1] <<endl;
  return 0;
}
