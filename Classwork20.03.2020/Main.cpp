#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ctime>


using namespace std;

int menu(int choiseMenu)
{
	cout << "\tMENU" << endl;
	cout << "1. Rand array" << endl;
	cout << "2. Show array" << endl;
	cout << "3. Find element" << endl;
	cout << "4. Sort array" << endl;
	cout << "5. Find arythmetic mean" << endl;
	cout << "6. Exit" << endl;
	cout << endl;
	cout << "Enter action ->";
	cin >> choiseMenu;
	return choiseMenu;
}

int randArray(int *array, int size)
{
	int diapazon = 0;
	
	cout << endl;
	cout << "\tRAND ARRAY" << endl;
	cout << "Enter diapazon: ";
	cin >> diapazon;
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % diapazon + 1;
		cout << array[i] << " ";
	}
	cout << endl;
	return array[size];
}

void showArray(int *array, int size)//int arr[]
{
	cout << "SHOW ARRAY" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void findElement(int *array, int size)
{
	cout << "FIND ELEMENT" << endl;
	int element;
	cout << "Enter element to find: ";
	cin >> element;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == element)
		{
			cout << i << endl;
			count++;
		}
		
	}
	if (count == 0)
	{
		cout << "Can not find element" << endl;
	}
}
int sortArray(int *array, int size)
{
	int choise;
	cout << "\tSORT" << endl;
	cout << "1. Bubble" << endl;
	cout << "2. Selection" << endl;
	cout << "3. Insertion" << endl;
	cout << endl;
	cout << "Select way to sort: ";
	cin >> choise;
	switch (choise)
	{
	case 1:
			for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					int temp = array[j];
					array[j] = array[j + 1]; 
					array[j + 1] = temp;

					for (int i = 0; i < size; i++)
					{
						cout << array[i] << " ";
					}
					cout << endl; 
					Sleep(500);

				}
			}
		}
			break;
	case 2:
			for (int i = 0; i < size; i++)
		{
			int temp = array[0];
			for (int j = i+1; j < size; j++)
			{
				if (array[i] > array[j])
				{
					temp = array[i]; 
					array[i] = array[j];
					array[j] = temp;

					for (int i = 0; i < size; i++)
					{
						cout << array[i] << " ";
					}
					cout << endl;
					Sleep(500);
				}
			}

		}
			break;
	case 3:
		int temp = 0;
		int indexPrev = 0;

		for (int i = 1; i < size; i++)
		{
			temp = array[i];
			indexPrev = i - 1;
			while (indexPrev >= 0 && array[indexPrev] > temp)
			{
				array[indexPrev + 1] = array[indexPrev];
				array[indexPrev] = temp;
				indexPrev--;

				for (int i = 0; i < size; i++)
				{
					cout << array[i] << " ";
				}
				cout << endl;
				Sleep(500);
			}
		}
		break;
	}
	return array[size];
}

void arythmeticMean(int *array, int size)
{
	cout << "ARYTHMETIC MEAN" << endl;
	float arythmeticMean = 0;
	for (int i = 0; i < size; i++)
	{
		arythmeticMean = arythmeticMean + array[i];
	}
	arythmeticMean = arythmeticMean / size;
	cout << "Arythmetic mean = " << arythmeticMean << endl;
}
int main()
{
	//const int size = 10;
	//int arr[size] = { 1, 8, 10, 7, 6, 9, 13, 3, 5, 2 };
	
	//bubble sort(бульбашка) - дуже повільний
	
	//for (int i = 0; i < size - 1; i++)
	//{
	//	for (int j = 0; j < size - 1; j++)
	//	{
	//		if (arr[j] > arr[j + 1])
	//		{
	//			int temp = arr[j];//тут зараз 10
	//			arr[j] = arr[j + 1]; //на місце 10 поклали 7
	//			arr[j + 1] = temp;
	//		}
	//	}
	//}


	//вибірка (select)
	/*for (int i = 0; i < size; i++)
	{
		int temp = arr[0];
		for (int j = i+1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i]; //тут більше число яке треба замінити на менше
				arr[i] = arr[j]; //велике число міняємо з меншим
				arr[j] = temp; //на місце малого кладемо більше
			}
		}

	}*/
	//вставка (insert)

	/*int temp = 0; 
	int indexPrev = 0;

	for (int i = 1; i < size; i++)//проходить по нашому масиву
	{
		temp = arr[i];//запис поточного числа
		indexPrev = i - 1;//запис попереднього індексу
		while (indexPrev >= 0 && arr[indexPrev] > temp)//зміщення масиву
		{
			arr[indexPrev + 1] = arr[indexPrev];
			arr[indexPrev] = temp;
			indexPrev--;
		}
	}*/

	const int size = 100;
	int array[size];
	int choiseMenu = 0;

	do {
		choiseMenu = menu(choiseMenu);
		switch (choiseMenu)
		{
		case 1:
			array[size] = randArray(array, size);
			break;
		case 2:
			showArray(array, size);
			break;
		case 3:
			findElement(array, size);
			break;
		case 4:
			array[size] = sortArray(array, size);
			showArray(array, size);
			break;
		case 5:
			arythmeticMean(array, size);
			break;
		case 6:
			cout << "Goodbye!" << endl;
			Sleep(500);
			break;
		default:
			break;
		}

	} while (choiseMenu != 6);





	system("pause");
	return 0;
}