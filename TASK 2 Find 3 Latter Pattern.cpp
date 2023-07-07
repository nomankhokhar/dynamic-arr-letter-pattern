// TASK 2 Find 3 Latter Pattern
// Noman Ali
// L1F20BSCS0554
#include <iostream>
#include <fstream>
using namespace std;
char *ShrinkArr(char * &arr, int &size);
void DisplayLine(char *arr, int size);
void FindPattern(char * &arr, int &size, char *ThreeLetterPattern);
void Modification_Array_Display(char *arr);
int main()
{
	ifstream read;
	read.open("line_text.txt");
	int size = 50;
	char *arr = new char[size];

	read.getline(arr,50);
	
	arr=ShrinkArr(arr, size);
	DisplayLine(arr, size);

	int sizeofPattern = 5;
	char *ThreeLetterPattern = new char[sizeofPattern];

	cout << "\n\nEnter 3 Letter Pattern : ";
	cin >> ThreeLetterPattern;


	FindPattern(arr, size,ThreeLetterPattern);

	Modification_Array_Display(arr);

	cout << endl;
	return 0;
}
void Modification_Array_Display(char *arr)
{
	cout << arr;
	delete[]arr;
	arr = 0;
}
void FindPattern(char * &arr, int &size, char *ThreeLetterPattern)
{
	
	int length = strlen(ThreeLetterPattern);
	int finalSize = size;
	for (int k = 0; k < size; k++)
	{
		int	index = 0;
		if (arr[k] == ThreeLetterPattern[0])
		{
			if (arr[k] == ThreeLetterPattern[length - 3] && arr[k + 2] == ThreeLetterPattern[length - 1])
			{
				finalSize = finalSize - 1;
				arr[k + 1] = arr[k + 2];
				index = k + 1;
				for (int l = index; l < size; l++)
				{
					arr[l] = arr[l + 1];
				}
			}
		}
	}
	size = finalSize;
	size = size + 1;
	arr[size - 1] = '\0';
	delete[]ThreeLetterPattern;
	ThreeLetterPattern = 0;
}
void DisplayLine(char *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
}
char *ShrinkArr(char * &arr, int &size)
{
	int length = strlen(arr);
	
	char *temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = 0;
	size = length;
	return  temp;
}
