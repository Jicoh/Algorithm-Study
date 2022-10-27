#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int res = 300000;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len; ++i){
            int left = 0;
            int right = len-1;
            while(left < right && left < len && right >= 0){
                if(left == i){
                    left++;
                    continue;
                }else if(right == i){
                    right--;
                    continue;
                }
                int sum = nums[i] + nums[left] + nums[right];
                int distance = sum - target;//3sum与target的distance
                if(abs(distance) < abs(res)){
                    res = distance;
                }
                if(distance < 0){
                    left++;
                }else if(distance > 0){
                    right--;
                }else{
                    return target;
                }
            }
        }
        cout<<res+target;
        return res + target;
    }
};

int main() {
    vector<int> v = {-1,2,1,-4};
    int target = 1;
    Solution s;
    s.threeSumClosest(v,1);
}
