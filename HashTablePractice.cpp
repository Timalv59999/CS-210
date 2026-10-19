#include<iostream>
#include<list>
#include<cstring>
using namespace std;

class HashTable
{
   private:
      static const int hashGroups = 10;
      list<pair<int, string>> table[hashGroups];
      
      public:
         bool isEmpty() const;
         int hashFunction(int key);
         void insertItem(int key, string value);
         void removeItem(int key);
         string searchTable(int key);
};

bool HashTable::isEmpty() const
{
   int sum{};
   for(int i{}; i < hashGroups; i++)
   {
      sum += table[i].size();
   }
   
   if(!sum)
   {
      return true;
   }
   return false;
}

int HashTable::hashFunction(int key)
{
   return key%hashGroups;
}

void HashTable::insertItem(int key, string value)
{
   int hashValue = hashFunction(key);
   auto& cell = table[hashValue];
   auto bItr = begin(cell);
   bool keyExists = false;
   for(; bItr != end(cell); bItr++)
   {
      if(bItr -> first == key)
      {
         keyExists = true;
         bItr -> second = value;
         break;
      }
   }
   
   if(!keyExists)
   {
      cell.emplace_back(key, value);
   }
   return;
}

void HashTable::removeItem(int key)
{
   int hashValue = hashFunction(key);
   auto& cell = table[hashValue];
   auto bItr = begin(cell);
   bool keyExists = false;
   for(; bItr != end(cell); bItr++)
   {
      if(bItr -> first == key)
      {
         keyExists = true;
         bItr = cell.erase(bItr);
         cout<<"[INFO] Item Removed." << endl;
         break;
      }
   }
   
   if(!keyExists)
   {
      cout<<"[WARNING] Key not found. Pair not removed."<< endl;
   }
}

int main()
{
}

