#include <iostream>
#include "code.hpp"
#include <time.h>

Code::Code(std::vector<int> code)
{
    this->code = code;
}

std::vector<int> Code::getCode()
{
    auto code = this->code;
    return code;
}
