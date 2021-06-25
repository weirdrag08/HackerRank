#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{   
    std::ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        string s;
        stack<char> my_stack;
        int count = 0;
        bool balanced = true;
        cin>>s;
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                my_stack.push(s[i]);
            }

            else
            {
                if (s[i] == ')')
                {
                    while (!my_stack.empty() && my_stack.top() != '(')
                    {

                        if(my_stack.top()=='[' || my_stack.top()=='{'){
                            balanced = false;
                            break;
                        }
                        my_stack.pop();
                    }
                    if (!my_stack.empty())
                    {
                        my_stack.pop();
                    }
                    else
                    {
                        balanced = false;
                        break;
                    }
                }

                else if (s[i] == '}')
                {
                    while (!my_stack.empty() && my_stack.top() != '{')
                    {
                        if(my_stack.top()=='[' || my_stack.top()=='('){
                            balanced = false;
                            break;
                        }
                        my_stack.pop();
                    }

                    if (!my_stack.empty())
                    {
                        my_stack.pop();
                    }
                    else
                    {
                        balanced = false;
                        break;
                    }
                }

                else if (s[i] == ']')
                {
                    while (!my_stack.empty() && my_stack.top() != '[')
                    {
                        if(my_stack.top()=='(' || my_stack.top()=='{'){
                            balanced = false;
                            break;
                        }
                        my_stack.pop();
                    }

                    if (!my_stack.empty())
                    {
                        my_stack.pop();
                    }
                    else
                    {
                        balanced = false;
                        break;
                    }
                }
            }
        }
        if (!my_stack.empty())
        {
            balanced = false;
        }

        if (!balanced)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    
}
