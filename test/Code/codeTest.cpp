#include "../../src/Code/code.hpp"
#include <gtest/gtest.h>

class CodeTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<int> vec{0, 1, 2, 3};
        this->code = new Code(vec);
    }

    void TearDown() override
    {
        delete this->code;
    }

    Code *code;
};

TEST_F(CodeTest, BasicAssertions)
{
    auto code = this->code->getCode();
    ASSERT_EQ(code.size(), 4);
};
