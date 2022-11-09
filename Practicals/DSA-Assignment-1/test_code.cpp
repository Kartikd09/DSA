for (;;)
{
    cout << "Enter Date of Birth :- " << endl;
    bool check_year = true;
    do
    {
        cout << "Enter the year : ";
        cin >> student1[i].year;
        if (student1[i].year >= 1947 && student1[i].year <= 2025)
        {
            check_year = false;
        }
        else
        {
            cout << "Error in year!! Re-enter" << endl;
            continue;
        }

    } while (check_year);

    bool check_month = true;
    do
    {
        cout << "Enter the month : ";
        cin >> student1[i].month;
        if (student1[i].month >= 1 && student1[i].month <= 12)
        {
            check_month = false;
        }
        else {
            cout << "Error in month!! Re-enter" << endl;
            check_month = true;
        }


    } while (check_month);

    bool check_date = true;
    do
    {
        cout << "Enter the date : ";
        cin >> student1[i].date;

        if (student1[i].month >= 1 && student1[i].month <= 12)
        {
            if (student1[i].month == 1 || student1[i].month == 3 || student1[i].month == 5 || student1[i].month == 7 || student1[i].month == 8 || student1[i].month == 10 || student1[i].month == 12)
            {
                cout << "Enter the date : ";
                cin >> student1[i].date;
                if (student1[i].date >= 1 && student1[i].date <= 31)
                {
                    break;
                }
                else
                {
                    cout << "Error in date!! Re-enter" << endl;
                    continue;
                }
            }

            else if (student1[i].month == 4 || student1[i].month == 6 || student1[i].month == 9 || student1[i].month == 11)
            {
                cout << "Enter the date : ";
                cin >> student1[i].date;
                if (student1[i].date >= 1 && student1[i].date <= 30)
                {

                    break;
                }

                else
                {
                    cout << "Error in date!! Re-enter" << endl;
                    continue;
                }
            }

            else if (student1[i].month == 2)
            {
                cout << "Enter the date : ";
                cin >> student1[i].date;
                if ((student1[i].year % 4 == 0 && student1[i].year % 100 != 0) || student1[i].year % 400 == 0)
                {
                    if (student1[i].date >= 1 && student1[i].date <= 29)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Error in date!! Re-enter" << endl;
                        continue;
                    }
                }
                else if (student1[i].date >= 1 && student1[i].date <= 28)
                {
                    break;
                }
                else
                {
                    cout << "Error in date!! Re-enter" << endl;
                    continue;
                }
            }
        }
    }

} while (check_date);


// if (student1->pin.length() == 6)
            // {
            //         for (int i = 0; i < student1->pin.length(); i++)
            //         {
            //             if (student1[i].pin >= '0' && student1[i].pin <='9')
            //             {
            //                 continue;
            //             }
            //             else
            //             {
            //                 cout << "Error in pin" << endl;
            //                 break;
            //             }

            //         }

            // }
            // check = false;


void printReport(record student1[], int arr[], int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        int c = arr[i];
        // cout << "The details of student " << i + 1 << " are :- " << endl;

        cout << "Roll no. :- " << student1[c].Roll_no << endl;

        cout << "Name :- " << student1[c].first_name << endl;

        cout << "Father's Name :- " << student1[c].father_name_first << endl;

        cout << "Date of Birth :- " << student1[c].date << "/" << student1[c].month << "/" << student1[c].year << endl;

        cout << "Branch :- " << student1[c].branch << endl;

        cout << "Year of Admission :- " << student1[c].yoa << endl;

        cout << "Year of passing :- " << student1[c].tyop << endl;

        cout << "District :- " << student1[c].district << endl;

        cout << "State :- " << student1[c].state << endl;

        cout << "PIN :- " << student1[c].pin << endl;

        cout << "Country :- " << student1[c].country << endl;
    }
    cout << endl;
    // printRecord(student1, size_arr);
}


//for getreport
    // int arr[size];
    // bool result = true;
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = i + 1; j < size; j++)
    //     {

    //         if (student1[i].first_name == student1[j].first_name)
    //         {
    //             arr[0] = i;
    //             arr[j] = j;
    //             result = false;
    //         }


    //     }
    //     if (result == false)
    //     {
    //         int size_arr = sizeof(arr) / sizeof(arr[0]);
    //         printReport(student1, arr, size_arr);
    //     }
    //     else {
    //         continue;
    //     }


    // }