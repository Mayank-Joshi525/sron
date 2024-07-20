
#pragma once

#ifndef FLAG_H
#define FLAG_H

#define TYPE_VOID (short unsigned int)0
#define TYPE_INT (short unsigned int)1
#define TYPE_DOUBLE (short unsigned int)2
#define TYPE_CHAR (short unsigned int)3
#define TYPE_BOOL (short unsigned int)4
#define TYPE_STRING (short unsigned int)5
#define TYPE_LIST (short unsigned int)6

#define TYPE_LIST_OPEN (short unsigned int)7            // '['
#define TYPE_LIST_CLOSE (short unsigned int)8           // ']'

#define TYPE_IDENTIFIER (short unsigned int)9
#define TYPE_OPERATOR (short unsigned int)10
#define TYPE_ATTRIBUTE (short unsigned int)11

#define TYPE_CLOSING_BRACKETS (short unsigned int)12     // ')'
#define TYPE_OPENING_BRACKETS (short unsigned int)13     // '('

#define TYPE_KEYWORD (short unsigned int)14
#define TYPE_COLON (short unsigned int)15               // ':'
#define TYPE_MATH_BLOCK (short unsigned int)16          // '~'

#define TYPE_FUNCTION_SCOPE_START (short unsigned int)17 // '{'
#define TYPE_FUNCTION_SCOPE_CLOSE (short unsigned int)18 // '}'

#define TYPE_FUNCTION_CALL (short unsigned int)19

#define TYPE_NEWLINE (short unsigned int)20              // '\n'

#define TYPE_ASSIGN (short unsigned int)21               // '='

#define TYPE_DATATYPE (short unsigned int)22

#define TYPE_COMMA (short unsigned int)23                // ','

#endif