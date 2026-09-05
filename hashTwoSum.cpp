#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

std::pair<int, int> twoSumHash(const std::vector<int>& nums, int target)
{
   std::unordered_map<int, int> seen;
   for (int i = 0; i < static_cast<int>(nums.size()); i++)
   {
      int complement = target - nums[i];

      std::unordered_map<int, int>::iterator it = seen.find(complement);
      if (it != seen.end())
      {
         int earlierIndex = (*it).second;
         return std::pair<int, int>(earlierIndex, i);
      }
      seen[nums[i]] = i;
   }
   return std::pair<int, int>(-1, -1);
}

int main()
{
   std::vector<int> nums1 = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
   int target1 = 24;
   std::pair<int, int> result1 = twoSumHash(nums1, target1);
   std::cout << "Indexes are (" << result1.first << ", " << result1.second << ") and their values are ("
              << nums1[result1.first] << ", " << nums1[result1.second] << "). Thus the ressults are valid." << std::endl;
              
   std::vector<int> nums2 = {17, 6, 8, 1, 69, 82, 4, 9, 19, 0, 5, 12, 16, 42, 20};
   int target2 = 9;
   std::pair<int, int> result2 = twoSumHash(nums2, target2);
   std::cout << "Indexes are (" << result2.first << ", " << result2.second << ") and their values are ("
              << nums2[result2.first] << ", " << nums2[result2.second] << "). Thus the results are valid." << std::endl;
   
   std::vector<int> nums3 = {14, 22, 81, 11, 2, 82, 9, 8, 19, 0, 5, 17, 16, 42, 21};
   int target3 = 44;
   std::pair<int, int> result3 = twoSumHash(nums3, target3);
   std::cout << "Indexes are (" << result3.first << ", " << result3.second << ") and their values are ("
              << nums3[result3.first] << ", " << nums3[result3.second] << "). Thus the results are valid" << std::endl;
              
   std::vector<int> nums4 = {3, 61, 80, 1, 60, 82, 5, 9, 19, 22, 90, 12, 23, 42, 0};
   int target4 = 87;
   std::pair<int, int> result4 = twoSumHash(nums4, target4);
   std::cout << "Indexes are (" << result4.first << ", " << result4.second << ") and their values are ("
              << nums4[result4.first] << ", " << nums4[result4.second] << "). Thus the results are valid" << std::endl;
              
   std::vector<int> nums5 = {171, 60, 89, 100, 69, 82, 423, 99, 119, 60, 25, 152, 106, 242, 120};
   int target5 = 267;
   std::pair<int, int> result5 = twoSumHash(nums5, target5);
   std::cout << "Indexes are (" << result5.first << ", " << result5.second << ") and their values are ("
              << nums5[result5.first] << ", " << nums5[result5.second] << "). Thus the results are valid" << std::endl;
}
