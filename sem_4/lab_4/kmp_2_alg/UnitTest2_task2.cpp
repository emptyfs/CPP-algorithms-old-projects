#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../kmp2/kmp2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(Test_prefix_function)
		{
			std::string input = "abcdef$defabcdefabc";
			std::vector<int> expected = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 1, 2, 3 };
			std::vector<int> actual = prefix_function(input);
			Assert::IsTrue(expected == actual);

			input = "acab$abacabac";
			expected = { 0, 0, 1, 0, 0, 1, 0, 1, 2, 3, 4, 1, 2 };
			actual = prefix_function(input);
			Assert::IsTrue(expected == actual);

			input = "";
			expected = {};
			actual = prefix_function(input);
			Assert::IsTrue(expected == actual);

			input = "qwerty$yqwertyqwert";
			expected = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5 };
			actual = prefix_function(input);
			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(Test_kmp)
		{
			std::string input_A = "defabc";
			std::string input_B = "abcdef";
			int expected = 3;
			int actual = kmp(input_A, input_B);
			Assert::IsTrue(expected == actual);

			input_A = "abac";
			input_B = "acab";
			expected = 2;
			actual = kmp(input_A, input_B);
			Assert::IsTrue(expected == actual);

			input_A = "";
			input_B = "";
			expected = -13;
			actual = kmp(input_A, input_B);
			Assert::IsTrue(expected == actual);

			input_A = "yqwert";
			input_B = "qwerty";
			expected = 1;
			actual = kmp(input_A, input_B);
			Assert::IsTrue(expected == actual);

			input_A = "qwe";
			input_B = "w";
			expected = -13;
			actual = kmp(input_A, input_B);
			Assert::IsTrue(expected == actual);
		}
	};
}