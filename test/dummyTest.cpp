#include <gtest/gtest.h>

class DummyTest : public ::testing::Test
{
protected:
    int a;

    void SetUp() override
    {
        a = 1;
    }

public:
    DummyTest()
    {
    }
    ~DummyTest()
    {
    }
};

TEST_F(DummyTest, BasicAssertions)
{
    ASSERT_EQ(a, 1);
}
