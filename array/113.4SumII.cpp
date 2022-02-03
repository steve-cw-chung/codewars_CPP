/* Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
 

Constraints:

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228 */
/*class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        sort(nums4.begin(),nums4.end());
        int i=0,j=0,k=0,l=0;
        bool notDone = true;
        int counter=0;
        int sum = 0;
        
            for(int i =0; i<nums1.size();i++){
                sum +=nums1[i];
                if (sum >0){
                    sum=0;
                    notDone = false;
                    break;
                }
                for(int j = 0; j< nums2.size(); i++){
                    sum +=nums2[j];
                    if (sum >0){
                        sum=0;
                        break;
                    }
                    for(int k=0; k<nums3.size();k++){
                        sum +=nums3[k];
                        if (sum >0){
                            sum=0;
                            break;
                        }
                        for(int l =0; l<nums4.size();l++){
                            sum += nums4[l];
                            if(sum == 0){
                                counter++;
                                sum =0;
                            }else if (sum >0){
                                
                                break;
                            }
                        }
                    }
                }
            }
        
        return counter;
    }
};*/
class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int count=0;
        unordered_map<int,int> mp;
        
        /* Philosophy
        
        1. I know that Addtion have two parts in it  EG (a +b , Part 1 - a, Part 2- b.
        2.So, Lets make and find this dependency factors. How can I do it?
        
        3. If there are 4 Sum. it means 2 sums is going to Part 1 and another 2 gonna be Part 2 which are dependent on Part 1 for 0 resultant.
        
        4. I gonna store summation 2 nums1 in a FREQUENCY Hashmap.
        
        5. Then I traverse 2nd part of the summation (rest to nums) and keep checking that do (0-it1-it2) is exist in map . 
       
        6. If yes, the add the frequency of Part1 int COUNT var.
        
        7. return count;
        */
        
        //Traversing Part 1
        for (auto it1: nums1)
            for (auto it2:nums2)
                mp[it1+it2]++; 
        
        // Traversing Part 2
        for(auto it3: nums3)
            for(auto it4:nums4)
               if(mp.count(0-it3-it4)) count+=mp[0-it3-it4];
        
        return count;
    }
};