// TASK 1 Update 7,1,7
// Noman Ali
// L1F20BSCS0554
#include <iostream>
#include <fstream>
using namespace std;
int *IncreasedArray(int * &arr, int &size);
void reDesignArray(int * &arr, int &size);
void displayArr(int *arr, int size);
int main()
{
	ifstream read;
	read.open("input.txt");

	int *arr = new int[];
	int size = 0;

	int value = 0;
	while (read>>value)
	{
		arr=IncreasedArray(arr, size);
		arr[size - 1] = value;
	}

	reDesignArray(arr, size); 
	
	displayArr(arr, size);
	
	
	cout << endl;
	return 0;
}
void displayArr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
void reDesignArray(int * &arr, int &size)
{
	for (int i = 0; i < size; i++)
	{
		int index = 0;
		if (arr[i] == 7)
		{
			if (arr[i] == 7 && arr[i + 1] == 7)
			{
				index = i;
				for (int j = index; j < size; j++)
				{
					arr[j] = arr[j + 1];
				}
				size = size - 1;
				break;
			}
			else if (arr[i] == 7 && arr[i + 2] == 7)
			{
				index = i;
				for (int j = index; j < size; j++)
				{
					arr[j] = arr[j + 1];
				}
				size = size - 1;
				break;
			}
		}
	}

}
int *IncreasedArray(int * &arr, int &size)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = NULL;
	size = size + 1;
	return temp;
}
