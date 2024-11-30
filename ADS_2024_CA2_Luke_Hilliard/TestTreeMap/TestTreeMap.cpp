#include "CppUnitTest.h"
#include "../ADS_2024_CA2_Luke_Hilliard/TreeMap.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTreeMap
{
	TEST_CLASS(TestTreeMap)
	{
	public:
		
		TEST_METHOD(TestAddToEmptyTree)
		{
			TreeMap<std::string, int> tree;
			tree.put("First", 2);
			Assert::AreEqual(1, tree.size());
		}

		TEST_METHOD(TestClearTree)
		{
			TreeMap<std::string, int> tree;
			tree.put("First", 1);
			tree.put("Second", 2);
			tree.put("Third", 3);

			tree.clear();
			Assert::IsTrue(tree.size() == 0);
		}

		TEST_METHOD(TestContainsKey)
		{
			TreeMap<int, std::string> tree;
			tree.put(1, "Apple");
			tree.put(30, "Banana");
			tree.put(2, "Orange");
			tree.put(5, "Pear");

			Assert::IsTrue(tree.containsKey(30));
		}
	};
}
