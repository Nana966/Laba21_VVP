// laba21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    //задание 1
    int n, m,i,j;
    cout << "Task 1.";
    cout << "\nPrint size matrix: ";
    cin >> n; 
    if (cin.fail() || n < 1 || n%2==0)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int** mas1 = new int* [n];
        for (int i = 0; i < n; i++)
            mas1[i] = new int[n];
        cout << "\nMatrix: \n";
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                mas1[i][j] = rand() % 30;
                cout << mas1[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\nSpiral output:\n";
        int i2;
        for (i2 = 0; i2 < n / 2; i2++) 
        {
            for (j = i2; j < (n - i2); j++)  //выводим левые столбцы сверху вниз
                cout<<mas1[j][i2] << " ";
            cout << "\n";
            for (i = i2 + 1; i <= n - i2 - 1; i++) //выводим строки слева направо
                cout<< mas1[n - i2 - 1][i]<<" ";
            cout << "\n";
            for (j = n - i2 - 2; j >= i2; --j) //выводим правые столбцы снизу вверх
                cout<<mas1[j][n - i2 - 1]<<" ";
            cout << "\n";
            for (i = n - i2 - 2; i >= i2 + 1; i--) //выводим строки справа налево
                cout<< mas1[i2][i]<<" ";
            cout<<"\n";
        }
        cout<< mas1[n / 2][n / 2]<<"\n"; //выводим центральное число
    }
    //задание 2
    int K;
    cout << "\nTask 2.";
    cout << "\nPrint count of lines: ";
    cin >> n; 
    cout << "Print count of columns: ";
    cin >> m;
    cout << "Print number line: ";
    cin >> K;
    if (cin.fail() || n < 1 || K<1 || K>n ||m<1)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int Sum = 0, Mul = 1;
        K--;
        int** mas2 = new int* [n];
        for (int i = 0; i < n; i++)
            mas2[i] = new int[m];
        cout << "\nMatrix: \n";
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                mas2[i][j] = rand() % 30;
                cout << mas2[i][j] << " ";
                if (i == K)
                {
                    Sum = Sum + mas2[i][j]; //считаем сумму
                    Mul = Mul * mas2[i][j]; //считаем произведение
                }
            }
            cout << "\n";
        }
        cout << "\nSum = " << Sum << ", Mul = " << Mul;
    }
    //задание 3
    cout << "\n\nTask 3.";
    cout << "\nPrint count of lines: ";
    cin >> n;
    cout << "Print count of columns: ";
    cin >> m;
    if (cin.fail() || n < 1 || m<1)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int MinMul, tempMul=1,column;
        int** mas3 = new int* [n];
        for (int i = 0; i < n; i++)
            mas3[i] = new int[m];
        cout << "\nMatrix: \n";
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                mas3[i][j] = rand() % 30;
                cout << mas3[i][j] << " ";
            }
            cout << "\n";
        }
        for (j = 0; j < m; j++)
        {
            tempMul = 1;
            for (i = 0; i < n; i++)
                tempMul = tempMul * mas3[i][j]; //считаем произведение текущего столбца
            if (j == 0) MinMul = tempMul; //запоминаем первое значение, чтоб было с чем сравнивать
            if (tempMul < MinMul) //сравниваем текущее произведение с минимальным
            {
                MinMul = tempMul;
                column = j;
            }
        }
        cout << "\nColumn = " << column+1 << ", MinMul = " << MinMul;
    }
    //задание 4
    cout << "\n\nTask 4.";
    cout << "\nPrint count of lines: ";
    cin >> n;
    cout << "Print count of columns: ";
    cin >> m;
    if (cin.fail() || n < 1 ||m<1)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int mean, k;
        int** mas4 = new int* [n];
        for (int i = 0; i < n; i++)
            mas4[i] = new int[m];
        cout << "\nMatrix: \n";
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                mas4[i][j] = rand() % 30;
                cout << mas4[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\nMean/Count:\n";
        for (j = 0; j < m; j++)
        {
            k = 0;
            mean = 0;
            for (i = 0; i < n; i++)
                mean = mean + mas4[i][j]; //считаем сумму чисел в столбце
            mean = mean / n; //считаем среднее арифметическое
            for (i = 0; i < n; i++)
                if (mas4[i][j] > mean)  //если число больше среднего
                    k++;  //наращиваем количество
            cout << mean<<"/"<< k << ", ";  //выводим на экран
        }
    }
    //задание 5
    cout << "\n\nTask 5.";
    cout << "\nPrint count of lines: ";
    cin >> n;
    cout << "Print count of columns: ";
    cin >> m;
    if (cin.fail() || n < 1 || m < 1)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int** mas5 = new int* [n];
        for (int i = 0; i < n; i++)
            mas5[i] = new int[m];
        cout << "\Line / column: \n";
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << "Print number "<<i<<","<<j << ": ";
                cin >> mas5[i][j];
            }
            cout << "\n";
        }
        cout << "\nMatrix: \n";
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                    cout << mas5[i][j] << " ";
                cout << "\n";
            }
        bool b = false;
        for (j = 0; j < m; j++)
        {
            b = false;
            for (i = 0; i < n; i++) //проверяем числа в столбце
                if (mas5[i][j] % 2 == 0) //если есть четное число, ставим флаг
                    b = true;
            if (b == false) //если в столбце числа нечетные, выводим его номер
            {
                cout << "\nColumn: " << j + 1;
                break;  //заканчиваем обработку
            }
        }
    }
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
