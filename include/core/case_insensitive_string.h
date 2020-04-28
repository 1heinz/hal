#pragma once

#include <string>

struct case_insensitive_char_traits : public std::char_traits<char>
{
    static bool eq(char c1, char c2)
    {
        return toupper(c1) == toupper(c2);
    }

    static bool ne(char c1, char c2)
    {
        return toupper(c1) != toupper(c2);
    }

    static bool lt(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);
    }

    static int compare(const char* s1, const char* s2, size_t n)
    {
        while (n-- != 0)
        {
            if (toupper(*s1) < toupper(*s2))
                return -1;
            if (toupper(*s1) > toupper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }

    static const char* find(const char* s, int n, char a)
    {
        while (n-- > 0 && toupper(*s) != toupper(a))
        {
            ++s;
        }
        return s;
    }
};
using case_insensitive_string = std::basic_string<char, case_insensitive_char_traits>;