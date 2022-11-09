if (student1->year >= 1947 && student1->year <= 2025)
        {
            cout << "Enter the month : ";
            cin >> student1->month;
            if (student1->month >= 1 && student1->month <= 12)
            {
                if (student1->month == 1 || student1->month == 3 || student1->month == 5 || student1->month == 7 || student1->month == 8 || student1->month == 10 || student1->month == 12)
                {
                    cout << "Enter the date : ";
                    cin >> student1->date;
                    if (student1->date >= 1 && student1->date <= 31)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Error in date" << endl;
                        continue;
                    }
                }

                else if (student1->month == 4 || student1->month == 6 || student1->month == 9 || student1->month == 11)
                {
                    cout << "Enter the date : ";
                    cin >> student1->date;
                    if (student1->date >= 1 && student1->date <= 30)
                    {

                        break;
                    }

                    else
                    {
                        cout << "Error in date" << endl;
                        continue;
                    }
                }

                else if (student1->month == 2)
                {
                    cout << "Enter the date : ";
                    cin >> student1->date;
                    if (student1->date >= 1 && student1->date <= 28)
                    {
                        break;
                    }
                    else
                    {
                        cout << "error" << endl;
                        continue;
                    }
                }
            }
            else
            {
                cout << "Error in month" << endl;
                continue;
            }
        }

        continue;
    }