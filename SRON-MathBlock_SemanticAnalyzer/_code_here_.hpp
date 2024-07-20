
#include "_base_.hpp"

/*
 * The below function will check if valid TYPES mentioned in _flags_.hpp are within the 
 * math block or not. It also verifies whether the expression is valid or not.
 
 * Below given are the types which are allowed within the math block...
 
 * TYPE_INT
 * TYPE_VOID
 * TYPE_DOUBLE
 * TYPE_CHAR
 * TYPE_STRING
 * TYPE_LIST_OPEN
 * TYPE_LIST_CLOSE
 * TYPE_BOOL
 * TYPE_OPERATOR
 * TYPE_OPENING_BRACKETS
 * TYPE_CLOSING_BRACKETS
 * TYPE_IDENTIFIER
 * TYPE_FUNCTION_CALL
 
 NOTE-
    * If TYPE_FUNCTION_CALL is found, then call SemanticAnalyzer::FOUND_TYPE_FUNCTION_CALL()

    * If TYPE_IDENTIFIER is found, then call SemanticAnalyzer::FOUND_TYPE_IDENTIFIER()

    * If TYPE_LIST_OPEN is found, then call SemanticAnalyzer::FOUND_LIST_OPEN()

    * The above function will move the SemanticAnalyzer::iterator to their respective end token.

    For example: 
                    1- SemanticAnalyzer::FOUND_LIST_OPEN() function moves the iterator to ']' token
                    where list ends.
                    2- Same with SemanticAnalyzer::FOUND_TYPE_FUNCTION_CALL(), it moves the iterator
                    to ')' where arguments passed to the function ends.

** PRE-KNOW:
   * This function SemanticAnalyzer::FOUND_TYPE_MATH_BLOCK() is called when TYPE_MATH_BLOCK is found.
   * This function returns true if everything is fine otherwise returns false

** Basic Test case:
   * ~ 2 + 2 + 2 - 2 ~             [Valid]
   * ~ 2 + println() ~             [Valid]
   * ~ 2 2 + ~                     [Invalid]
   * ~ + + 22 println()~           [Invalid]
   * ~ 97 + println( 2 + 2) ~      [Invalid]
  
*/

inline static bool SemanticAnalyzer::FOUND_TYPE_MATH_BLOCK(){

    using SemanticAnalyzer::iterator;

    ++iterator;

    // code here
}