#include<iostream>
#include<vector>
using namespace std;
/* -------------1526. Minimum Number of Increments on Subarrays to Form a Target Array----------------
for example if the array is like [1,2,3]
#first initialize a vector to [0,0,0] and add the 1's to it left to right it will be [1,1,1] as both 0 indexes of them are equal then move next
increment
# [1,1] -> [2,2] as the second indexes of both the arrays are equal then move forward and increment
# [2] -> [3] the final array will be [1,2,3] 
 so no of steps involved are 3
 (if its increasing array)
for another example let array be [3,2,1]
#initialize a vector to [0,0,0] and add 1 to them it will be [1,1,1] last 1 is matched dont increment that
#and again [1,1] remain unequal and add again 1 to them [2,2] as 2 is matched them dont incremnet it next
#[2] -> [3] so the final vector becomes [3,2,1] 
so no of steps involved are 3
(if its decreasing array) 
as we see the maximum element in decreasig array is total no of operations and the element beside it is always less
than that So in order to write code we store first element in a varaible and check if there is a chance of having a
element greater than it or not if yes then add their difference to the variable
*/
class Solution{
public:
int Noofoperations(vector<int> target){
      int maxoperations = target[0];
        for(int i = 1; i < target.size();i++){
            if(target[i] > target[i-1]){
                maxoperations += target[i] - target[i -1];
            }
        }
        return maxoperations;
}
};
int main(){
  vector<int> nums = {2,1,5};
  Solution s1;
  int result = s1.Noofoperations(nums);
  cout<<result;
}
