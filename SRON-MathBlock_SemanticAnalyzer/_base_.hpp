
#pragma once

#include "_sron_token_.hpp"

namespace SemanticAnalyzer
{

    std::set<SronTokenString> variableSet;

    std::set<SronTokenString> inbuiltFncSet;

    std::set<SronTokenString> userDefinedFncSet;

    std::vector<SronToken>::iterator iterator;
    std::vector<SronToken>::const_iterator tokenVectorEnd;

    /*
      Found functions which are called when a particular type is found.
    */
    inline static void FOUND_TYPE_IDENTIFIER();
    inline static void FOUND_TYPE_FUNCTION_CALL();
    inline static bool FOUND_TYPE_MATH_BLOCK();
    inline static void FOUND_TYPE_LIST_OPEN();

}