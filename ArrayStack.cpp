#include<iostream>
#include<stdexcept>
using namespace std;

class ArrayStack
{
private:
   int length;
   int allocationSize;
   int* array;
   
   void Resize()
   {
      int newSize = allocationSize * 2;
      int* newArray = new int[newSize];
      for (int i = 0; i < length; i++)
      {
         newArray[i] = array[i];
      }
   
   
   delete[] array;
   array = newArray;
   allocationSize = newSize;
   }

public:
   ArrayStack()
   {
      allocationSize = 1;
      array = new int[allocationSize];
      length = 0;
 
   }
   
   virtual ~ArrayStack()
   {
      delete[] array;
   }
   
   int getLength() const
   {
      return length;
   }
   
   bool Push(int item)
   {
      
      if(length == allocationSize)
      {
         Resize();
      }
      
      array[length] = item;
      length++;
      return true;
   }
   
   int Pop()
   {
      if(length == 0)
      {
         throw runtime_error("Stack is Empty");
      }
      length--;
      return array[length];
   }
};

int main()
{
   ArrayStack s;
   
   s.Push(1);
   s.Pop();
   s.Push(2);
   s.Push(3);
   s.Push(4);
   try
   {
      cout<< s.Pop() << "\n";
      cout<< s.Pop() << "\n";
      cout<< s.Pop() << "\n";
      cout<< s.Pop() << "\n";
      cout<< s.Pop() << "\n";
   }
   catch(const runtime_error& e)
   {
      cout<< "Error: " << e.what() << "\n";
   }
   
   s.Push(5);
}
   