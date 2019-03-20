#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Implementation of Class Solution
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numsMap;
    //int complement;
    for (int i = 0; i < nums.size(); i++){
      //complement = target - nums[i];
      if(numsMap.count(target - nums[i])){
        return vector<int>{numsMap[target - nums[i]], i};
      }
      numsMap[nums[i]] = i;
    }
    return vector<int>{0, 0};
  }
  // vector<int> twoSum(vector<int> &numbers, int target) {
  //   vector<int> res;
  //   map<int,int>hmap;
  //   hmap.clear();
  //   for (int i=0;i<numbers.size();i++){
  //     hmap[numbers[i]]=i;
  //   }
  //   for (int i=0;i<numbers.size();i++){
  //     if (hmap.find((target-numbers[i]))!=hmap.end()){
  //       if (i<hmap[target-numbers[i]]){
  //         res.push_back(i+1);
  //         res.push_back(hmap[target-numbers[i]]+1);
  //         return res;
  //       }
  //       if (i>hmap[target-numbers[i]]){
  //         res.push_back(hmap[target-numbers[i]]+1);
  //         res.push_back(i+1);
  //         return res;
  //       }
  //     }
  //   }
  //   return res;
  // }
  //
  // vector<int> twoSum(vector<int>& nums, int target) {
  //   vector<int> tmpnums = nums;
  //   sort(tmpnums.begin(), tmpnums.end());
  //   int left = 0;
  //   int right = tmpnums.size() - 1;
  //   while(left < right){
  //     if(tmpnums[left] + tmpnums[right] < target)
  //     left++;
  //     else if(tmpnums[left] + tmpnums[right] > target)
  //     right--;
  //     else
  //     break;
  //   }
  //   if(left >= right)
  //   return vector<int>{0, 0};
  //   int index1 = distance(nums.begin(), std::find(nums.begin(), nums.end(), tmpnums[left]));
  //   nums[index1] = -1;
  //   int index2 = distance(nums.begin(), std::find(nums.begin(), nums.end(), tmpnums[right]));
  //   return vector<int>{index1, index2};
  // }
};

int main(int argc, const char * argv[]){
  vector<int> nums;
  int num = 0, target = 0;
  cout << "Please input nums, end with ENTER" << "\n";
  while(cin.peek() != '\n'){
    cin >> num;
    nums.push_back(num);
  }
  cout << "Please input target, end with ENTER" << "\n";
  cin >> target;
  Solution solution;
  vector<int> TwoSum = solution.twoSum(nums, target);
  for(int i = 0; i < TwoSum.size(); i++){
    cout << TwoSum[i] << " ";
  }
  return 0;
}
