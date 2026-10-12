#include<iostream>
#include<stdexcept>
using namespace std;

class LinkedDeque
{
   private:
   struct Node
   {
      int data;
      Node* next;
      Node* prev;
   };
   
   Node* head;
   Node* tail;
   
   public:
   LinkedDeque()
   {
      head = nullptr;
      tail = nullptr;
   }
   
   ~LinkedDeque()
   {
      while(head != nullptr)
      {
         Node* toDelete = head;
         head = head -> next;
         delete toDelete;
      }
   }
   
   LinkedDeque(const LinkedDeque&) = delete;
   LinkedDeque& operator = (const LinkedDeque&) = delete;
   
   bool PushFront(int item)
   {
      Node* newNode = new Node;
      newNode -> data = item;
      newNode -> prev = nullptr;
      newNode -> next = head;
      
      if(head == nullptr)
      {
         tail = newNode;
      }
      else
      {
         head -> prev = newNode;
      }
      head = newNode;
      return true;
   }
   
   bool PushBack(int item)
   {
      Node* newNode = new Node;
      newNode->data = item;
      newNode->next = nullptr;
      newNode->prev = tail;

      if (tail == nullptr)     
      {
         head = newNode;
      }
      else
      {
         tail->next = newNode;
      }
      tail = newNode;
      return true;
   }
   
   
   int PopFront()
   {
      if (head == nullptr)
      {
         throw runtime_error("The Deque is Empty");
      }
      Node* toDelete = head;
      int toReturn = head->data;
      head = head->next;
      if (head == nullptr)          
      {
         tail = nullptr;
      }
      else
      {
         head->prev = nullptr;
      }
      delete toDelete;
      return toReturn;
   }
   
   int PopBack()
   {
      if (tail == nullptr)
      {
         throw runtime_error("The Deque is Empty");
      }
      Node* toDelete = tail;
      int toReturn = tail->data;
      tail = tail->prev;
      if (tail == nullptr)          
      {
         head = nullptr;
      }
      else
      {
         tail->next = nullptr;
      }
      delete toDelete;
      return toReturn;
   }
};

int main()
{
   LinkedDeque D;
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