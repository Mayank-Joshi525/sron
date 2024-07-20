#pragma once

#ifndef _SRON_STRING_H
#define _SRON_STRING_H

#include "__import__.hpp"

struct SronTokenString
{
    const char *str;

    inline SronTokenString(const char *const &_str) : str(_str) {}

    inline SronTokenString(const std::string &_str = " ") : str(_str.c_str()) {}

    inline SronTokenString &operator=(const char *const &__str)
    {
        this->str = __str;

        return *this;
    }

    inline SronTokenString &operator=(std::string &&__str)
    {
        this->str = __str.c_str();

        return *this;
    }

    inline operator std::string() const
    {
        return std::string(this->str);
    }

    inline bool operator!=(const char *const &right) const
    {
        return std::strcmp(this->str, right) != 0;
    }

    inline bool operator!=(const SronTokenString &_right) const
    {
        return std::strcmp(this->str, _right.str) != 0;
    }

    inline bool operator==(const char *const &right) const
    {
        return std::strcmp(this->str, right) == 0;
    }

    inline bool operator==(const std::string &right) const
    {
        return right == this->str;
    }

    inline bool operator==(const SronTokenString &_tk) const
    {
        return std::strcmp(this->str, _tk.str) == 0;
    }

    inline bool operator<(const SronTokenString &_tk) const
    {
        return std::strcmp(this->str, _tk.str) < 0;
    }

    inline bool operator<=(const SronTokenString &_tk) const
    {
        return std::strcmp(this->str, _tk.str) <= 0;
    }

    inline bool operator>(const SronTokenString &_tk) const
    {
        return std::strcmp(this->str, _tk.str) > 0;
    }

    inline bool operator>=(const SronTokenString &_tk) const
    {
        return std::strcmp(this->str, _tk.str) >= 0;
    }

    struct HashFunction
    {
        std::size_t operator()(const SronTokenString &s) const
        {
            return std::hash<std::string>{}(std::string(s.str));
        }
    };
};

inline std::ostream &operator<<(std::ostream &COUT, const SronTokenString &_tk)
{
    return COUT << _tk.str;
}

#endif
