#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <utility>  


bool isSorted(const std::vector<int>& values)
{
   int n = static_cast<int>(values.size());   

   for(int i = 0; i < n - 1; i++)
   {
      if(values[i] > values[i + 1])
      {
         return false;
      }
   }
   return true;
}

void bubbleSort(std::vector<int>& values)
{
   int n = static_cast<int>(values.size());

   for(int i = 0; i < n - 1; i++)
   {
      for(int j = 0; j < n - i - 1; j++)
      {
         if(values[j] > values[j + 1])
         {
            int temp = values[j];
            values[j] = values[j + 1];
            values[j + 1] = temp;
         }
      }
   }
}


void selectionSort(std::vector<int>& values)
{
   int n = static_cast<int>(values.size());

   for(int i = 0; i < n - 1; i++)
   {
      int minIndex = i;   

      for(int j = i + 1; j < n; j++)
      {
         if(values[j] < values[minIndex])   
         {
            minIndex = j;
         }
      }

      std::swap(values[i], values[minIndex]);
   }
}


void insertionSort(std::vector<int>& values)
{
   int n = static_cast<int>(values.size());

   for(int i = 1; i < n; i++)
   {
      int key = values[i];  

      int j = i - 1;
      while(j >= 0 && values[j] > key)
      {
         values[j + 1] = values[j];
         j--;
      }
      values[j + 1] = key;
   }
}


void quickSortRange(std::vector<int>& values, int low, int high)
{
   
   if(low >= high)
   {
      return;
   }


   int mid = low + (high - low) / 2;
   std::swap(values[low], values[mid]);
   int pivot = values[low];

   int i = low;        
   int j = high + 1;   

   while(true)
   {
      do { i++; } while(i <= high && values[i] < pivot);
      do { j--; } while(values[j] > pivot);   

      if(i >= j)
      {
         break;   
      }
      std::swap(values[i], values[j]);
   }

   
   std::swap(values[low], values[j]);

   quickSortRange(values, low, j - 1);
   quickSortRange(values, j + 1, high);
}


void quickSort(std::vector<int>& values)
{
   if(values.empty())
   {
      return;
   }
   quickSortRange(values, 0, static_cast<int>(values.size()) - 1);
}


using SortFn = void (*)(std::vector<int>&);

struct Algorithm
{
   std::string name;
   SortFn fn;
};

enum class InputType { Random, Sorted, Reversed };


std::vector<int> makeInput(InputType type, int n)
{
   std::vector<int> data(n);

   if(type == InputType::Random)
   {
      std::mt19937 rng(12345);
      std::uniform_int_distribution<int> dist(0, 1000000);
      for(int i = 0; i < n; i++)
      {
         data[i] = dist(rng);
      }
   }
   else if(type == InputType::Sorted)
   {
      for(int i = 0; i < n; i++)
      {
         data[i] = i;
      }
   }
   else
   {
      for(int i = 0; i < n; i++)
      {
         data[i] = n - i;
      }
   }
   return data;
}


double timeSort(SortFn sort, const std::vector<int>& input, bool& ok)
{
   std::vector<int> copy = input;  

   auto start = std::chrono::steady_clock::now();
   sort(copy);
   auto end = std::chrono::steady_clock::now();

   ok = isSorted(copy);             

   return std::chrono::duration<double, std::milli>(end - start).count();
}

int main()
{
   const std::vector<int> sizes = {5000, 10000, 20000};
   const int TRIALS = 10;   

   const std::vector<Algorithm> algorithms = {
      {"Bubble",    bubbleSort},
      {"Selection", selectionSort},
      {"Insertion", insertionSort},
      {"Quick",     quickSort}
   };

   const std::vector<std::pair<std::string, InputType>> inputTypes = {
      {"Random",         InputType::Random},
      {"Already sorted", InputType::Sorted},
      {"Reverse sorted", InputType::Reversed}
   };

   bool allOk = true;

   std::cout << std::fixed << std::setprecision(3);
   std::cout << "Times in milliseconds (average of " << TRIALS << " runs)\n";

   for(const auto& inputType : inputTypes)
   {
      std::cout << "\n" << inputType.first << " input\n";
      std::cout << std::left << std::setw(12) << "Algorithm";
      for(int n : sizes)
      {
         std::cout << std::right << std::setw(12) << ("n=" + std::to_string(n));
      }
      std::cout << "\n";

      for(const auto& algo : algorithms)
      {
         std::cout << std::left << std::setw(12) << algo.name;

         for(int n : sizes)
         {
            std::vector<int> input = makeInput(inputType.second, n);

            double total = 0.0;
            for(int t = 0; t < TRIALS; t++)
            {
               bool ok = false;
               total += timeSort(algo.fn, input, ok);
               if(!ok)
               {
                  allOk = false;
                  std::cout << "\n*** " << algo.name << " FAILED isSorted on "
                            << inputType.first << ", n=" << n << " ***\n";
               }
            }
            std::cout << std::right << std::setw(12) << total / TRIALS;
         }
         std::cout << "\n";
      }
   }

   std::cout << "\n" << (allOk ? "All sorts passed isSorted verification."
                              : "SOME SORTS FAILED verification.") << "\n";
   return 0;
}