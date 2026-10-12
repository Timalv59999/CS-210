#include<iostream>
#include<stdexcept>
using namespace std;

class ArrayDeque
{
private:
   int* array;
   int length; //length of array
   int allocationSize;//how many elements can fit in array
   int frontIndex;
   
   void Resize()
   {
      int newSize = allocationSize *2;
      int* newArray = new int[newSize];
      for(int i = 0; i < length; i++)
      {
         int itemIndex = (frontIndex + i) % allocationSize;
         newArray[i] = array[itemIndex];
      }
      
      delete[] array;
      array = newArray;
      allocationSize = newSize;
      frontIndex = 0;
   }
   
   public:
   ArrayDeque()
   {
      frontIndex = 0;
      allocationSize = 1;
      length = 0;
      array = new int[allocationSize];  
   }
   
   virtual ~ ArrayDeque()
   {
      delete[] array;
   }
   
   bool PushBack(int item)
   {
      if(length == allocationSize)
      {
         Resize();
      }
      
      int itemIndex = (frontIndex + length) % allocationSize;
      array[itemIndex] = item;
      length++;
      return true;
   }
   
   bool PushFront(int item)
   {
      if(length == allocationSize)
      {
         Resize();
      }
      
      frontIndex = (frontIndex - 1 + allocationSize) % allocationSize;
      array[frontIndex] = item;
      length++;
      return true;
      
   }
   
   int PopFront()
   {
      if(length == 0)
      {
         throw runtime_error("The Deque is Empty");
      }
      
      int toReturn = array[frontIndex];
      length--;
      frontIndex = (frontIndex + 1) % allocationSize;
      return toReturn; 
   }
   
   int PopBack()
   {
      if(length == 0)
      {
         throw runtime_error("The Deque is Empty");
      }
      
      int backIndex = (frontIndex + length - 1) % allocationSize;
      int toReturn = array[backIndex];
      length--;
      return toReturn;
   }
};

int main()
{
   ArrayDeque D;
   try
   {
      cout << D.PushFront(1) << "\n";
      cout << D.PushFront(2) << "\n";
      cout << D.PushFront(5) << "\n";
      cout << D.PushBack(15) << "\n";
      cout << D.PushBack(12) << "\n";
      cout << D.PopFront() << "\n";
      cout << D.PopFront() << "\n";
      cout << D.PopBack() << "\n";
      cout << D.PopBack() << "\n";
      cout << D.PopBack() << "\n";
      cout << D.PopBack() << "\n";  
   }
   catch(runtime_error& e)
   {
      cout<< "Error: " << e.what() << "\n";
   }
}