#include<iostream>
#include<stdexcept>
using namespace std;

class ArrayQueue
{
private:
   int allocationSize;
   int* array;
   int length;
   int frontIndex;
   
   void Resize()
   {
      int newSize = allocationSize * 2; 
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
   ArrayQueue()
   {
      allocationSize = 1;
      array = new int[allocationSize];
      frontIndex = 0;;
      length = 0;;
   }
   
   virtual ~ ArrayQueue()
   {
      delete[] array;
   }
   
   int getLength() const
   {
      return length;
   }
   
   bool Enqueue(int item)
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
   
   int Dequeue()
   {
      if(length == 0)
      {
         throw runtime_error("Queue is Empty");
      }
      
      int toReturn = array[frontIndex];
      length--;
      frontIndex = (frontIndex + 1) % allocationSize;
      return toReturn;
   }
   
};

int main()
{
   ArrayQueue Q;
   
   try
  { 
     cout<< Q.Enqueue(1) << "\n";
     cout<< Q.Enqueue(2) << "\n";
     cout<< Q.Enqueue(3) << "\n";
     cout<< Q.Enqueue(4) << "\n";
     cout<< Q.Dequeue() << "\n";
     cout<< Q.Dequeue() << "\n";
     cout<< Q.Dequeue() << "\n";
     cout<< Q.Dequeue() << "\n";
     cout<< Q.Dequeue() << "\n"; 
   }
   catch(const runtime_error& e)
   {
      cout<< "Error: " << e.what() << "\n";
   }
   cout<< Q.Enqueue(5) << "\n"; 
}
