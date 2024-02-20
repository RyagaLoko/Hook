// FunctionPointerHandler.hpp
#pragma once
#include "Templates.hpp"
#include <minwindef.h>

class FunctionPointerHandler {
public:
    template <typename T>
    static PBYTE ConvertMemberFuncToPBYTE(void (T::*memberFunc)()) {
        // Use the provided MemberFuncToPtr to get a void* to the member function
        void* ptrToMemberFunction = MemberFuncToPtr(&memberFunc);

        // Cast the void* to PBYTE
        PBYTE pbyteToMemberFunction = reinterpret_cast<PBYTE>(ptrToMemberFunction);

        return pbyteToMemberFunction;
    }

    // Add any other related functionality here.
};
