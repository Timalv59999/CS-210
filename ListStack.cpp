#include<iostream>
#include<stdexcept>
using namespace std;

class LinkedStack
{
private:
   struct Node
   {
      int data;
      Node* next;
   };
   Node* top;
   
   public:
   LinkedStack()
   {
      top = nullptr;
   }
   
   ~LinkedStack()
   {
      while(top != nullptr)
      {
         Node* toDelete = top;
         top = top -> next;
         delete toDelete;
      }
   }
   
   LinkedStack(const LinkedStack&) = delete;
   LinkedStack& operator = (const LinkedStack&) = delete;
   
   bool Push(int item)
   {
      Node* newNode = new Node;
      newNode -> data = item;
      newNode -> next = top;
      top= newNode;
      return true;
   }
   
   int Pop()
   {
      if(top == nullptr)
      {
         throw runtime_error("Stack is Empty");
      }
      Node* toDelete = top;
      int toReturn = top -> data;
      top = top -> next;
      delete toDelete;
      return toReturn;
   }
};  

int main()
{
   LinkedStack L;
   try
   {
      cout<< L.Push(1) << "\n";
      cout<< L.Pop() << "\n";
      cout<< L.Push(2) << "\n";
      cout<< L.Pop() << "\n";
      cout<< L.Push(3) << "\n";
      cout<< L.Push(4) << "\n";
      cout<< L.Push(5) << "\n";
      cout<< L.Pop() << "\n";
      cout<< L.Pop() << "\n";
      cout<< L.Pop() << "\n";
      cout<< L.Pop() << "\n";
   }
   catch(runtime_error& e)
   {
      cout<< "Error: " << e.what() << "\n";
   }
}