
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

    * If TYPE_LIST_OPEN is found, then call SemanticAnalyzer::FOUND_TYPE_LIST_OPEN()

    * The above function will move the SemanticAnalyzer::iterator to their respective end token.

    For example: 
                    1- SemanticAnalyzer::FOUND_TYPE_LIST_OPEN() function moves the iterator to ']' token
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
   * ~ 97 + println( 2 + 2 ) ~      [Invalid]
  
*/

inline static bool SemanticAnalyzer::FOUND_TYPE_MATH_BLOCK(){
   using SemanticAnalyzer::iterator;
   using SemanticAnalyzer::tokenVectorEnd;
   
   // inside math block any operation need 3 values: 
   // Two OPERAND and One OPERATOR between them. (eg:  ~ a + b ~) 
   // Their can be opening bracket after OPERATOR and
   // Their can be closing bracket after OPERAND.

   //eg ((((a + b ) + c) + d) + e)   or  ~ (()) ~
   while(++iterator->_type ==  TYPE_OPENING_BRACKETS || iterator->_type == TYPE_CLOSING_BRACKETS);

   // 
   //
   //
   // Implemention for unary operator
   //
   //


   //first value always operand  but not for unary operator (eg: ~ -a ~)
   switch (iterator->_type){
      case TYPE_INT:
      case TYPE_VOID:
      case TYPE_DOUBLE:
      case TYPE_CHAR:
      case TYPE_STRING:
      case TYPE_BOOL:
         break;

      case TYPE_IDENTIFIER:
         SemanticAnalyzer::FOUND_TYPE_IDENTIFIER();
         break;

      case TYPE_FUNCTION_CALL:                              // fuction_name(
         SemanticAnalyzer::FOUND_TYPE_FUNCTION_CALL();      //iterator will reach to ')'
         break;

      case TYPE_LIST_OPEN:                           // '['
         SemanticAnalyzer::FOUND_TYPE_LIST_OPEN();   // iterator will reach to ']'
         break;

      // case TYPE_OPERATOR:  will return false (eg: ~ + a ~ )
      default:
         return false;
   }

   // second value always operator and third value always operand
   while(++iterator->_type != TYPE_MATH_BLOCK){

      while(iterator->_type ==  TYPE_CLOSING_BRACKETS){   // ~ ( a ) ~   or   ~(a + (c + b))~
         if(++iterator->_type == TYPE_MATH_BLOCK)  return true;
      }

      switch(iterator->_type){      //operator only
         case TYPE_OPERATOR:
            break;
         default:
            return false;
      }
      
      //Closing brackets cannot be placed after an operator but opening brackets can.
      while(++iterator->_type ==  TYPE_OPENING_BRACKETS);      

      switch (iterator->_type){   //operand only
         case TYPE_INT:
         case TYPE_VOID:
         case TYPE_DOUBLE:
         case TYPE_CHAR:
         case TYPE_STRING:
         case TYPE_BOOL:
            break;

         case TYPE_IDENTIFIER:
            SemanticAnalyzer::FOUND_TYPE_IDENTIFIER();
            break;

         case TYPE_FUNCTION_CALL:
            SemanticAnalyzer::FOUND_TYPE_FUNCTION_CALL();
            break;

         case TYPE_LIST_OPEN:
            SemanticAnalyzer::FOUND_TYPE_LIST_OPEN();
            break;

         default:    // case TYPE_OPERATOR:  will also return false (eg: ~ a + + ~ )
            return false;
      }
   }
   
   return true;
}