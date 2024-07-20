#pragma once

#ifndef SRON_TOKEN_H
#define SRON_TOKEN_H

#include "_sron_token_string_.hpp"

struct SronToken
{

    unsigned short int _type;
    SronTokenString _token;
    const char *_flag;
    unsigned short int _newline_count;

    SronToken() {}

    SronToken(unsigned short int type, const char *token, const char *flag, unsigned short int newline_count = 0U) : _type(type), _token(token), _flag(flag), _newline_count(newline_count) {}
};

inline static std::ostream &operator<<(std::ostream &COUT, const SronToken& obj)
{
    COUT << "\n Type: " << obj._type << "\t Token: " << obj._token << "\t Flag: " << obj._flag << "\t Newline count: " << obj._newline_count << "\n";
    return COUT;
}

typedef std::vector<SronToken> TokenVector;

#endif