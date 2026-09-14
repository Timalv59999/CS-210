#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& a, int target, int& counts)
{
   int low = 0;
   int high = a.size() - 1;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      counts++;
      if (a[mid] == target)
      {
         return mid;
      }
      else if (a[mid] < target)
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   return -1;
}

int main()
{
   vector<int> a = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
   int counts = 0;
   int index = binarySearch(a, 2, counts);
   cout << "index is: " << index << ", comparisons: " << counts <<  endl;
   
   vector<int> b = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
   int counts2 = 0;
   int indextwo = binarySearch(b, 91, counts2);
   cout << "index is: " << indextwo << ", comparisons: " << counts2 <<  endl;
   
   vector<int> c = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
   int counts3 = 0;
   int indexthree = binarySearch(c, 23, counts3);
   cout << "index is: " << indexthree << ", comparisons: " << counts3 <<  endl;
   
   vector<int> d = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
   int counts4 = 0;
   int indexfour = binarySearch(d, 0, counts4);
   cout << "index is: " << indexfour << ", comparisons: " << counts4 <<  endl;
   
   vector<int> e = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
   int counts5 = 0;
   int indexfive = binarySearch(e, 17, counts5);
   cout << "index is: " << indexfive << ", comparisons: " << counts5 <<  endl;
}