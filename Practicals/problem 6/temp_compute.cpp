int ComputeTree(Node *root, string input)
{
    string temp_eval;
    temp_eval = conv_ToPostfix(input);

    cout << temp_eval << endl;
    for (int i = 0; i < temp_eval.length(); i++)
    {
        if (check_Operator(temp_eval[i]) == 0)
        {
            int val;
            cout << "Enter a value for " << temp_eval[i] << " : ";
            cin >> val;
            push_eval(val);
        }

        else
        {
            double a = pop_eval();
            double b = pop_eval();

            switch (temp_eval[i])
            {
            case '+':
            {
                push_eval(a + b);
                break;
            }
            case '-':
            {
                push_eval(b - a);
                break;
            }
            case '*':
            {
                push_eval(a * b);
                break;
            }
            case '/':
            {
                push_eval(b / a);
                break;
            }
            case '^':
            {
                push_eval(pow(b, a));
                break;
            }
            }
        }
    }

    int result = pop_eval();
    cout << "Computed Result is: " << result << endl;
}