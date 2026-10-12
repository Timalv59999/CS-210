#include<iostream>
#include<stdexcept>
using namespace std;

class LinkedQueue
{
private:
   struct Node
   {
      int data;
      Node* next;
   };
   Node* head;
   Node* tail;
   
   public:
   LinkedQueue()
   {
      head = nullptr;
      tail = nullptr;
   }
   
   ~LinkedQueue()
   {
      while(head != nullptr)
      {
         Node* toDelete = head;
         head = head -> next;
         delete toDelete;
      }
   }
   
   LinkedQueue(const LinkedQueue&) = delete;
   LinkedQueue& operator = (const LinkedQueue&) = delete;
   
   bool Enqueue (int item)
   {
      Node* newNode = new Node;
      newNode -> data = item;
      newNode -> next = nullptr;
      if(tail == nullptr)
      {
         head = newNode;
      }
      else
      {
         tail -> next = newNode;
      }
      tail = newNode;
      return true;
   }
   
   int Dequeue()
   {
      if(head == nullptr)
      {
         throw runtime_error("Queue is Empty");
      }
      Node* toDelete = head;
      int toReturn = head -> data;
      head = head -> next;
      if(head == nullptr)
      {
         tail = nullptr;
      }
      delete toDelete;
      return toReturn;
   }
};

int main()
{
   LinkedQueue Q;
   try
   {
      cout<< Q.Enqueue(1) << "\n";
      cout<< Q.Dequeue() << "\n";
      cout<< Q.Enqueue(2) << "\n";
      cout<< Q.Dequeue() << "\n";
      cout<< Q.Enqueue(3) << "\n";
      cout<< Q.Dequeue() << "\n";
      cout<< Q.Enqueue(4) << "\n";
      cout<< Q.Dequeue() << "\n";
      cout<< Q.Enqueue(5) << "\n";
      cout<< Q.Dequeue() << "\n";
      cout<< Q.Dequeue() << "\n";
      
   }
   catch(runtime_error& e)
   {
      cout<< "Error: " << e.what() << "\n";
   }
}