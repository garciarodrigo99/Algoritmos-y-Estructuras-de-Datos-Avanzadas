//#include <gtest/gtest.h>
#include "../../../google_test/googletest/include/gtest/gtest.h"
#include "../src/BigInt/Base_Class/Number.hpp"

TEST(ConvertTo8, B10) {
  BigInt<8> test8("3062");
  Number* test10 = new BigInt<10>("1586");
  EXPECT_EQ(test8, test10->operator BigInt<8UL>());
}

TEST(ConvertTo8, B16) {
  BigInt<8> test8("3062");
  Number* test16 = new BigInt<16>("632");
  EXPECT_EQ(test8, test16->operator BigInt<8UL>());
}

TEST(ConvertTo10, B8) {
  BigInt<10> test10("172671");
  Number* test8 = new BigInt<8>("521177");
  EXPECT_EQ(test10, test8->operator BigInt<10UL>());
}

TEST(ConvertTo10, B16) {
  BigInt<10> test10("172671");
  Number* test16 = new BigInt<16>("2A27F");
  EXPECT_EQ(test10, test16->operator BigInt<10UL>());
}

TEST(ConvertTo16, B8) {
  BigInt<16> test16("1A23B9F");
  Number* test8 = new BigInt<8>("150435637");
  EXPECT_EQ(test16, test8->operator BigInt<16UL>());
}

TEST(ConvertTo16, B10) {
  BigInt<16> test16("1A23B9F");
  Number* test10 = new BigInt<10>("27409311");
  EXPECT_EQ(test16, test10->operator BigInt<16UL>());
}

TEST(AddTest, b8b10) {
  BigInt<8> a("53127");//(22103)10
  BigInt<10> b("83093");
  BigInt<8> expected("315354");
  Number* num1 = &a;
  Number* num2 = &b;
  Number* result = num1->add(num2);
  EXPECT_EQ(result->operator BigInt<8UL>(), expected);
}

TEST(AddTest, b8b16) {
  BigInt<8> a("53127");//(22103)10
  BigInt<16> b("A1643B");
  BigInt<8> expected("50335222");
  Number* num1 = &a;
  Number* num2 = &b;
  Number* result = num1->add(num2);
  EXPECT_EQ(result->operator BigInt<8UL>(), expected);
}

TEST(AddTest, b10b8) {
  BigInt<10> a("931792");
  BigInt<8> b("430367550");
  BigInt<10> expected("74458936");
  Number* num1 = &a;
  Number* num2 = &b;
  Number* result = num1->add(num2);
  EXPECT_EQ(result->operator BigInt<10UL>(), expected);
}

TEST(AddTest, b10b16) {
  BigInt<10> a("93179");
  BigInt<16> b("6A1B");
  BigInt<10> expected("120342");
  Number* num1 = &a;
  Number* num2 = &b;
  Number* result = num1->add(num2);
  EXPECT_EQ(result->operator BigInt<10UL>(), expected);
}

TEST(AddTest, b16b8) {
  BigInt<10> a("1234");
  BigInt<10> b("5678");
  BigInt<10> expected("6912");
  Number* num1 = &a;
  Number* num2 = &b;
  Number* result = num1->add(num2);
  BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
  EXPECT_EQ(*actual, expected);
}

TEST(AddTest, b16b10) {
  BigInt<16> a("3EC1");//(16065)10
  BigInt<10> b("12098");
  BigInt<16> expected("6E03");
  Number* num1 = &a;
  Number* num2 = &b;
  Number* result = num1->add(num2);
  std::cout << "a: " << num1->operator BigInt<10UL>() << std::endl;
  EXPECT_EQ(result->operator BigInt<16UL>(), expected);
}

// TEST(NumberTest, SubtractTest) {
//   BigInt<10> a("5678");
//   BigInt<10> b("1234");
//   BigInt<10> expected("4444");
//   Number* num1 = &a;
//   Number* num2 = &b;
//   Number* result = num1->subtract(num2);
//   BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
//   EXPECT_EQ(*actual, expected);
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
// }

// TEST(NumberTest, ModuleTest) {
//   BigInt<10> a("5678");
//   BigInt<10> b("1234");
//   BigInt<10> expected("742");
//   Number* num1 = &a;
//   Number* num2 = &b;
//   Number* result = num1->module(num2);
//   BigInt<10> *actual = dynamic_cast<BigInt<10>*>(result);
//   EXPECT_EQ(*actual, expected);
// }

//g++ -o test/numberTest test/test_number.cpp ../../google_test/build/lib/libgtest.a -lpthread

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
