#include "Utils.h"

string doubleToString(double x)
{
    string s = to_string(x);
    unsigned int decimalSepPos = s.find('.');
    if (decimalSepPos != string::npos)
    {
        unsigned int len = s.length() - 1;
        while (s[len] == '0')
        {
            len--;
        }
        if (len == decimalSepPos)
        {
            s = s.substr(0, len);
        }
        else
        {
            s = s.substr(0, len + 1);
        }
    }
    return s;
}