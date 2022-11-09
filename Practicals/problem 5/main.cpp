#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void print(int sort[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << sort[i] << "  ";
}

void bubble_sort(int size, int sort[])
{

    auto start = high_resolution_clock::now();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sort[j] > sort[j + 1])
            {
                int temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration1 = stop - start;

    cout << "\nTime Taken For " << size << " random numbers : " << fixed << duration1.count() << setprecision(6) << " ms" << endl;
    // return duration.count();
}

void insertion_sort(int size, int sort[])
{
    auto start = high_resolution_clock::now();
    int temp;
    for (int i = 1; i < size; i++)
    {
        temp = sort[i];
        int j = i - 1;

        while (j >= 0 && sort[j] > temp)
        {
            sort[j + 1] = sort[j];
            j = j - 1;
        }
        sort[j + 1] = temp;
    }
    auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    duration<double, milli> duration1 = stop - start;
    cout << "\nTime Taken For " << size << " random numbers : " << fixed << duration1.count() << setprecision(6) << " ms" << endl;
    // return duration1.count();
}

void selection_sort(int size, int sort[])
{
    auto start = high_resolution_clock::now();
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        temp = i;
        for (int j = i + 1; j < size; j++)
        {
            if (sort[temp] > sort[j])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            int tmp = sort[i];
            sort[i] = sort[temp];
            sort[temp] = tmp;
        }
    }
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration1 = stop - start;
    cout << "\nTime Taken For " << size << " random numbers : " << fixed << duration1.count() << setprecision(6) << " ms" << endl;
    // return duration.count();
}

void shell_sort(int size, int sort[])
{
    auto start = high_resolution_clock::now();
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = sort[i];
            int j;
            for (j = i; j >= gap && sort[j - gap] > temp; j -= gap)
            {
                sort[j] = sort[j - gap];
            }
            sort[j] = temp;
        }
    }
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration1 = stop - start;
    cout << "\nTime Taken For " << size << " random numbers : " << fixed << duration1.count() << setprecision(6) << " ms" << endl;
    // return duration.count();
}

int Max(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int *output = new int[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int size)
{
    auto start = high_resolution_clock::now();
    int m = Max(arr, size);

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, size, exp);
    }
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration1 = stop - start;
    cout << "\nTime Taken For " << size << " random numbers : " << fixed << duration1.count() << setprecision(6) << " ms" << endl;
    // return duration.count();
}

int *result(int size)
{
    int *sort = new int[size];
    for (int i = 0; i < size; i++)
    {
        unsigned int num = rand() % 1000000;
        sort[i] = num;
    }
    return sort;
}

int main()
{

    long long int size;
    int *sort;
    int choice;
    bool check = true;
    int input;
    srand(time(NULL));

    do
    {
        system("cls");
        cout << "Main Menu:-" << endl;
        cout << "Select the sorting method :- " << endl;
        cout << "1) Bubble sort" << endl;
        cout << "2) Insertion sort" << endl;
        cout << "3) Selection sort" << endl;
        cout << "4) Shell sort" << endl;
        cout << "5) Radix sort" << endl;
        cout << "6) Exit" << endl;
        cout << "Enter the choice : ";
        cin >> input;

        switch (input)

        {
        case 1:
        {
            system("cls");

            cout << "For Bubble sort- : " << endl;
            for (int i = 100; i <= 1000000; i = i * 10)
            {
                sort = result(i);
                bubble_sort(i, sort);
            }
            delete[] sort;
            cout << "Press any key to go back" << endl;
            getch();
        }
        break;

        case 2:
        {
            system("cls");
            cout << "For Insertion Sort :- " << endl;
            for (int i = 100; i <= 1000000; i = i * 10)
            {
                sort = result(i);
                insertion_sort(i, sort);
            }
            delete[] sort;

            cout << endl;
            cout << "Press any key to go back" << endl;

            getch();
            break;
        }

        case 3:
        {
            system("cls");

            cout << "For Selection Sort :- " << endl;
            for (int i = 100; i <= 1000000; i = i * 10)
            {
                sort = result(i);
                selection_sort(i, sort);
            }
            delete[] sort;

            cout << "Press any key to go back" << endl;
            getch();
            break;
        }

        case 4:
        {
            system("cls");

            cout << "For Shell Sort :- " << endl;
            for (int i = 100; i <= 1000000; i = i * 10)
            {
                sort = result(i);
                shell_sort(i, sort);
            }
            delete[] sort;

            cout << endl;
            cout << "Press any key to go back" << endl;
            getch();
            break;
        }

        case 5:
        {
            system("cls");

            cout << "For Radix Sort :- " << endl;
            for (int i = 100; i <= 1000000; i = i * 10)
            {
                sort = result(i);
                radix_sort(sort, i);
            }
            delete[] sort;

            cout << endl;
            cout << "Press any key to go back" << endl;
            getch();
            break;
        }
        case 6:
        {
            check = false;
        }
        }

    } while (check);

    return 0;
}
