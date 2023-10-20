// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <conio.h>
using std::cout;
using std::cin;
using std::endl;
int const N = 100;
int array[N];

void IncArray(void);
void DecArray(void);
void RandArray(void);
void ViewArray(void);
void CheckSum(void);
void Series(void);
void SelectSort(void);
void BubbleSort(void);
void ShakeSort(void);
void ChangeArray(void);

int main()
{
	setlocale(LC_ALL, "Russian");
	system("mode con cols=70 lines=60");
	system("color black");
	char c;
	while (1)
	{
		system("cls");
		cout << " Размер массива - " << N << ".\n\n";
		cout << " 1) Создать возрастающий массив\n";
		cout << " 2) Создать убывающий массив\n";
		cout << " 3) Создать рандомный массив\n";
		cout << " 4) Просмотр массива\n";
		cout << " 5) Сортировка методом прямого выбора\n";
		cout << " 6) Сортировка пузырьковым методом\n";
		cout << " 7) Сортировка шейкерным методом\n";
		cout << " 0) Выход\n";
		c = _getch();
		switch (c)
		{
			system("cls");
		case '1':system("cls"); IncArray(); system("pause"); break;
		case '2':system("cls"); DecArray(); system("pause"); break;
		case '3':system("cls"); RandArray(); system("pause"); break;
		case '4':system("cls"); ViewArray(); CheckSum(); Series(); system("pause"); break;
		case '5':system("cls"); SelectSort(); system("pause"); break;
		case '6':system("cls"); BubbleSort(); system("pause"); break;
		case '7':system("cls"); ShakeSort(); system("pause"); break;
		case '0':return 0;
		default:cout << "\nОшибка! Неверный ввод. Нажмите любую клавишу."; _getch();
		}
	}
}

void IncArray()
{
	for (int i = 0; i < N; i++)
	{
		array[i] = i + 1;
	}
	cout << "Возрастающий массив создан!\n\n";
	ViewArray();
	CheckSum();
	Series();
}
void DecArray()
{
	for (int i = 0; i < N; i++)
	{
		array[i] = N - i;
	}
	cout << "Убывающий массив создан!\n\n";
	ViewArray();
	CheckSum();
	Series();
}
void RandArray()
{
	for (int i = 0; i < N; i++)
	{
		array[i] = 1 + rand() % N;
	}
	cout << "Рандомный массив создан!\n\n";
	ViewArray();
	CheckSum();
	Series();
}
void ViewArray()
{
	for (int i = 0; i != N; i = i + 10)
	{
		printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d\n", array[i], array[i + 1], array[i + 2], array[i + 3], array[i + 4], array[i + 5], array[i + 6], array[i + 7], array[i + 8], array[i + 9]);
	}
	cout << "\n";
}

void CheckSum()
{
	int cs;
	cs = 0;
	for (int i = 0; i < N; i++)
	{
		cs = cs + array[i];
	}
	cout << "Контрольная сумма: " << cs << "\n";
}

void Series()
{
	int s;
	s = 0;
	for (int i = 0; i < N; i++)
	{
		if (array[i] <= array[i + 1])
			s = s;
		else
			s = s + 1;
	}
	cout << "число серии в массиве: " << s << "\n";
}
void SelectSort()
{
	int min, temp, j;
	int fw, compare;
	cout << "До сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	compare = 0;
	fw = 0;
	for (int i = 0; i < N - 1; i++)
	{
		min = i;
		for (j = i + 1; j < N; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				compare = compare + 1;
			}
			else
				compare = compare + 1;
		}
		temp = array[i];
		fw = fw + 1;
		array[i] = array[min];
		fw = fw + 1;
		array[min] = temp;
		fw = fw + 1;
	}
	ViewArray();
	cout << "После сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	cout << "Количество сравнений: " << compare << ", количество пересилок: " << fw << endl;
}
void BubbleSort()
{
	int i, j, temp;
	int fw, compare;
	cout << "До сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	compare = 0;
	fw = 0;
	for (i = 0; i < N; i++)
	{
		for (j = N - 1; j > i; j--)
		{
			compare = compare + 1;
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				fw = fw + 1;
				array[j - 1] = array[j];
				fw = fw + 1;
				array[j] = temp;
				fw = fw + 1;
			}
		}
	}
	ViewArray();
	cout << "После сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	cout << "Количество сравнений: " << compare << ", количество пересилок: " << fw << endl;
}
void ShakeSort()
{
	int l, r, temp;
	int fw, compare;
	cout << "До сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	l = 0;
	r = N - 1;
	fw = 0;
	compare = 0;
	int flag = 1;
	while ((l < r) && flag > 0)
	{
		flag = 0;
		for (int i = l; i < r; i++)
		{
			compare = compare + 1;
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				fw = fw + 1;
				array[i] = array[i + 1];
				fw = fw + 1;
				array[i + 1] = temp;
				fw = fw + 1;
				flag = 1;
			}
		}
		r--;
		for (int i = r; i > l; i--)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				fw = fw + 1;
				array[i] = array[i - 1];
				fw = fw + 1;
				array[i - 1] = temp;
				fw = fw + 1;
				flag = 1;
			}
		}
		l++;
	}
	ViewArray();
	cout << "После сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	cout << "Количество сравнений: " << compare << ", количество пересилок: " << fw << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
