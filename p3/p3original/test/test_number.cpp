//#include <gtest/gtest.h>
#include "../../../google_test/googletest/include/gtest/gtest.h"
//#include "../src/BigInt/Base_Class/Number.hpp"

// TEST(NumberTest, AddTest) {
//   BigInt<10> a("1234");
//   BigInt<10> b("5678");
//   BigInt<10> expected("6912");
//   Number* num1 = &a;
//   Number* num2 = &b;
//   Number* result = num1->add(num2);
//   BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
//   EXPECT_EQ(*actual, expected);
//   delete num1;
//   delete num2;
//   delete result;
// }

// TEST(NumberTest, SubtractTest) {
//   BigInt<10> a("5678");
//   BigInt<10> b("1234");
//   BigInt<10> expected("4444");
//   Number* num1 = &a;
//   Number* num2 = &b;
//   Number* result = num1->subtract(num2);
//   BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
//   EXPECT_EQ(*actual, expected);
//   delete num1;
//   delete num2;
//   delete result;
// }

// TEST(NumberTest, MultiplyTest) {
//   BigInt<10> a("1234");
//   BigInt<10> b("5678");
//   BigInt<10> expected("7006652");
//   Number* num1 = &a;
//   Number* num2 = &b;
//   Number* result = num1->multiply(num2);
//   BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
//   EXPECT_EQ(*actual, expected);
//   delete num1;
//   delete num2;
//   delete result;
// }

// TEST(NumberTest, DivideTest) {
//   BigInt<10> a("5678");
//   BigInt<10> b("1234");
//   BigInt<10> expected("4");
//   Number* num1 = &a;
//   Number* num2 = &b;
//   Number* result = num1->divide(num2);
//   BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
//   EXPECT_EQ(*actual, expected);
//   delete num1;
//   delete num2;
//   delete result;
// }

// TEST(NumberTest, ModuleTest) {
//   BigInt<10> a("5678");
//   BigInt<10> b("1234");
//   BigInt<10> expected("986");
//   Number* num1 = &a;
//   Number* num2 = &b;
//   Number* result = num1->module(num2);
//   BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
//   EXPECT_EQ(*actual, expected);
//   delete num1;
//   delete num2;
//   delete result;
// }

TEST(Igualacion, Test1) {
    EXPECT_EQ(1, 1);
}

//g++ -o test/numberTest test/test_number.cpp ../../google_test/build/lib/libgtest.a -lpthread

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
