#include<iostream>
using namespace std;

class BinarySearchTree
{
   private:
      struct Node
      {
         int value;
         Node* left;
         Node* right;
         Node(int v)
         {
            value = v;
            left = nullptr;
            right = nullptr;
         }
      };
      Node* root = nullptr;
      
      Node* remove(Node* current, int v)
      {
         if (current == nullptr) 
         {
            return nullptr;
         }
         if(v < current -> value)
         {
            current -> left = remove(current -> left, v);
         } 
         else if(v > current -> value)
         {
            current -> right = remove(current -> right, v);
         }
         else
         {
            if(current -> left == nullptr)
            {
               Node* temp = current -> right;
               delete current;
               return temp;
            }
            if(current -> right == nullptr)
            {
               Node* temp = current -> left;
               delete current;
               return temp;
            }
            
            Node* successor = current -> right;
            while(successor -> left != nullptr)
            {
               successor = successor -> left;
            }
            current -> value = successor -> value;
            current -> right = remove(current -> right, successor -> value);
         }
         return current;
      }
      
      bool contains(int v)
      {
         Node* current = root;
         while(current != nullptr)
         {
            if(v == current -> value)
            {
               return true;
            }
            else if(v < current -> value)
            {
               current = current -> left;
            }
            else
            {
               current = current -> right;
            }
         }
         return false;
      }
      
      void inorder(Node* current)
      {
         if(current == nullptr)
         {
            return;
         }
         inorder(current -> left);
         cout << current -> value << " ";
         inorder(current -> right);
      }
      
      void preorder(Node* current)
      {
         if(current == nullptr)
         {
            return;
         }
         cout << current -> value << " ";
         preorder(current -> left);
         preorder(current -> right);
      }
      
      void postorder(Node* current)
      {
         if(current == nullptr)
         {
            return;
         }
         postorder(current -> left);
         postorder(current -> right);
         cout << current -> value << " ";
      }
      
      int height(Node* current)
      {
         if(current == nullptr)
         {
            return -1;
         }
         
         int leftHeight = height(current -> left);
         int rightHeight = height(current -> right);
         
         if(leftHeight > rightHeight)
         {
            return leftHeight + 1;
         }
         else
         {
            return rightHeight + 1;
         }
      }
      
   public:
      void insert(int number)
      {
         if(root == nullptr)
         {
            root = new Node(number);
            return;
         }
         
         Node* current = root;
         while(true)
         {
            if(number < current -> value)
            {
               if(current -> left == nullptr)
               {
                  current -> left = new Node(number);
                  return;
               }
               current = current -> left;
            }
            else
            {
               if(current -> right == nullptr)
               {
                  current -> right = new Node(number);
                  return;
               }
               current = current -> right;
            }
         }
      }
      
      bool search(int v)
      {
         bool found = contains(v);
         if(found)
         {
            cout << v << " exists" << endl;
         }
         else
         {
            cout << v << " does not exists" << endl;
         }
         return found;
      }
      
      void remove(int v)
      {
         if(contains(v))
         {
            root = remove(root, v);
            cout << "Removed: " << v << endl;
         }
         else
         {
            cout << v << " does not exist " << endl;
         }
      }
      
      void inorder()
      {
         if(root == nullptr)
         {
            cout << "Cannot print an empty tree" << endl;
            return;
         }
         cout<<"inorder:";
         inorder(root);
         cout << endl;
      }
      
      void preorder()
      {
         preorder(root);
         cout<< endl;
      }
      
      void postorder()
      {
         postorder(root);
         cout<< endl;
      }
      
      int height()
      {
         return height(root);
      }
};

int main()
{
   BinarySearchTree BST;
   
   BST.insert(100);
   BST.insert(50);
   BST.insert(176);
   BST.insert(128);
   BST.insert(291);
   BST.insert(310);
   BST.insert(27);
   BST.insert(92);
   BST.insert(79);
   BST.insert(99);
   BST.insert(5);
   
   BST.inorder();
   BST.search(5);
   BST.search(1000);
   
   BST.remove(5);
   BST.inorder();
   BST.remove(291);
   BST.inorder();
   BST.remove(92);
   BST.inorder();
   cout << "postorder: ";
   BST.postorder();
   cout << "preorder: ";
   BST.preorder();
   cout << "height: " << BST.height();
}