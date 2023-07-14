#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../ConsoleApplication2/ConsoleApplication2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesttask1
{
	TEST_CLASS(UnitTesttask1)
	{
	public:

		TEST_METHOD(Test_prefix_function)
		{
			std::string input = "ab$abab";
			std::vector<int> expected = { 0, 0, 0, 1, 2, 1, 2 };
			std::vector<int> actual = prefix_function(input);
			Assert::IsTrue(expected == actual);

			input = "";
			expected = {};
			actual = prefix_function(input);
			Assert::IsTrue(expected == actual);

			input = "ab$abbaabbab";
			expected = { 0, 0, 0, 1, 2, 0, 1, 1, 2, 0, 1, 2 };
			actual = prefix_function(input);
			Assert::IsTrue(expected == actual);

			input = "efef$efefeftef";
			expected = { 0, 0, 1, 2, 0, 1, 2, 3, 4, 3, 4, 0, 1, 2 };
			actual = prefix_function(input);
			Assert::IsTrue(expected == actual);
		}

		TEST_METHOD(Test_kmp)
		{
			std::string input_P = "ab";
			std::string input_T = "abab";
			std::vector<int> expected = { 0, 2 };
			std::vector<int> actual = kmp(input_P, input_T);
			Assert::IsTrue(expected == actual);

			input_P = "";
			input_T = "";
			expected = {};
			actual = kmp(input_P, input_T);
			Assert::IsTrue(expected == actual);

			input_P = "ab";
			input_T = "abbaabbab";
			expected = { 0,4,7 };
			actual = kmp(input_P, input_T);
			Assert::IsTrue(expected == actual);

			input_P = "efef";
			input_T = "efefeftef";
			expected = { 0,2 };
			actual = kmp(input_P, input_T);
			Assert::IsTrue(expected == actual);

			input_P = "aaaaaaaaaaaaa";
			input_T = "efefeftef";
			expected = {};
			actual = kmp(input_P, input_T);
			Assert::IsTrue(expected == actual);
		}
	};
}