#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{

    int i = 0;
    bool positive = true;

    while (i < s.length())
    {

        if (s[i] == ' ' || s[i] == '0' || s[i] == '+')
        {
            i++;
        }
        else if (s[i] == '-')
        {
            positive = false;
            i++;
        }
        else
        {
            break;
        }
    }

    int ans = 0;
    int base = 1;
    while (i < s.length())
    {

        if (isdigit(s[i]))
        {
            cout << "s[i] = " << s[i] << endl;
            ans = ans * base + s[i];
            base = base * 10;
        }
        else
        {
            break;
        }

        i++;
    }

    if (!positive)
    {
        cout << "Negative" << endl;
        ans = -ans;
    }
    return ans;
}

int main()
{
    string s = "000+42";
    cout << myAtoi(s) << endl;
    return 0;
}