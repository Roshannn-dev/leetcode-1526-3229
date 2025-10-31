/* ------------------ 3229. Minimum Operations to Make Array Equal to Target -------------------
Input: nums = [3,5,1,2], target = [4,6,2,4]
we need to increase or decrease 1's in the nums in order to get target
first we find the difference between the two vectors 
[4,6,2,4] - [3,5,1,2]  =  [1,2,1,2]
as this is same as problem no 1526 so we add sumofoperations first value is that 1 and run a loop upto n and 
add its and previos one differences
what if there are negetive values
[1,3,4,2] and [2,1,2,1]
we need to find differences 
[2,1,2,1] - [1,3,4,2]  = [1,-2,-2,-1]
as we surely need 1 step so add first element to sumofoperations and next check if they are same signs or not
if thery are same signs then add thier differences and if not then
add the numbers absolute value
[1,-2,  they are of different signs so add abs(-2) to sumofoperations (1 + 2) = 3
[-2,-2, they are of same signs so add their differences (3 + abs(-2 - (-2))) = 3
[-2,-1 . same here (3 + max(0 ,abs (abs(1) - abs(- 2))) = 3 + 0;
so there it takes 3 steps
verify it >>>
[1,3,4,2]. add 1 to index 0 to make it 2  step 1
[3,4,2] <-> [1,2,1] as we need to decreament here -1 to all  step 2
[2,3,1] <-> [1,2,1] as last element got equal so decrement for [2,3,  step 3
[1,2] <-> [1,2] so they are same
 */
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        
        vector<long long> x(n); 
        
        for(int i = 0; i < n; i++){
            x[i] = (long long)target[i] - (long long)nums[i];
        }

        // Handle the edge case of an empty array
        if (n == 0) {
            return 0;
        }

        long long result = abs(x[0]); 
        
        for(int i = 1; i < x.size(); i++){
            if(x[i] * x[i - 1] > 0) {
                result += max(0LL, abs(x[i]) - abs(x[i - 1]));
            } else {
            
                result += abs(x[i]);
            }
        }
        return result;
    }
};