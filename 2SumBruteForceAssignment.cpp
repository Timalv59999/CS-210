#include <iostream>
#include <vector>

struct twoSumResult
{
   int index1;
   int index2;
   int value1;
   int value2;
};

twoSumResult twoSumBruteForce(const std::vector<int>& nums, int target); 
int main()
{
   std::vector<int> nums = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
   int target = 24;
   twoSumResult result = twoSumBruteForce(nums, target);
   std::cout << "The Indexes are (" << result.index1  << ", " << result.index2 << ") and their values are ("
              << result.value1 << ", " << result.value2 << "). Thus the results are valid" << std::endl;  
              
      std::vector<int> nums1 = {12, 1, 19, 24, 39, 22, 24, 30, 19, 0, 8, 2, 6, 42, 7};
   int target1 = 37;
   twoSumResult result1 = twoSumBruteForce(nums1, target1);
   
   std::cout << "The Indexes are (" << result1.index1  << ", " << result1.index2 << ") and their values are ("
              << result1.value1 << ", " << result1.value2 << "). Thus the results are valid." << std::endl;   
              
   std::vector<int> nums2 = {28, 13, 119, 24, 34, 30, 4, 3, 9, 0, 82, 72, 61, 2, 7};
   int target2 = 58;
   twoSumResult result2 = twoSumBruteForce(nums2, target2);
   
   std::cout << "The Indexes are (" << result2.index1  << ", " << result2.index2 << ") and their values are ("
              << result2.value1 << ", " << result2.value2 << "). Thus the results are valid." << std::endl;  
              
   std::vector<int> nums3 = {228, 113, 119, 4, 50, 30, 48, 31, 9, 0, 68, 72, 61, 2, 7};
   int target3 = 118;
   twoSumResult result3 = twoSumBruteForce(nums3, target3);
   
   std::cout << "The Indexes are (" << result3.index1  << ", " << result3.index2 << ") and their values are ("
              << result3.value1 << ", " << result3.value2 << "). Thus the results are valid." << std::endl; 
              
   std::vector<int> nums4 = {1442, 1113, 1219, 2354, 34, 0, 4, 2540, 967, 1900, 822, 7267, 6110, 209, 2809};
   int target4 = 3982;
   twoSumResult result4 = twoSumBruteForce(nums4, target4);
   
   std::cout << "The Indexes are (" << result4.index1  << ", " << result4.index2 << ") and their values are ("
              << result4.value1 << ", " << result4.value2 << "). Thus the results are valid." << std::endl;            
   return 0;
}

twoSumResult twoSumBruteForce(const std::vector<int>& nums, int target)
{
   for(int i = 0; i < nums.size(); i++)
   {
      int Diff = target - nums[i];
      for(int j = i + 1; j < nums.size(); j++)
      {
         if(nums[j] == Diff)
         {
            return {i,j, nums[i], nums[j]};
         }
      }
   }
 return {-1, -1, 0, 0};
}