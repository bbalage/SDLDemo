#ifndef CODE_HPP
#define CODE_HPP
#include <array>
#include <vector>

class Code
{
private:
    std::vector<int> code;

public:
    Code(std::vector<int> code);
    ~Code(){};
    std::vector<int> getCode();
};
#endif
