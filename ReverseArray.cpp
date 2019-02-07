//Reverse Array
# include <iostream>

using namespace std;

void reverseArray(int arr[], int start, int end)
{
  while (start < end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }

}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}


int main(int argc, const char* argv[])
{
  int array[] = {1,2,3,4,5,6};

  printArray(array,6);

  reverseArray(array,0,5);

  printArray(array,6);
}
