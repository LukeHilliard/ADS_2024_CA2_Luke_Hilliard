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
		TEST_METHOD(TestAddToPopulatedTree)
		{
			TreeMap<std::string, int> tree;
			tree.put("First", 1);
			tree.put("Second", 2);
			Assert::AreEqual(2, tree.size());

			tree.put("Third", 3);
			Assert::AreEqual(3, tree.size());
		}
		TEST_METHOD(TestOverwriteValue)
		{
			TreeMap<int, int> tree;
			tree.put(1, 0);
			tree.put(1, 1);
			Assert::AreEqual(0, tree.get(1));
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

		TEST_METHOD(TestContainsNoKey)
		{
			TreeMap<int, std::string> tree;
			tree.put(1, "Apple");
			tree.put(30, "Banana");
			tree.put(2, "Orange");
			tree.put(5, "Pear");

			Assert::IsFalse(tree.containsKey(6));
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

		TEST_METHOD(TestGet)
		{
			TreeMap<char, int> tree;
			tree.put('C', 5);
			tree.put('X', 9);
			tree.put('I', 6);

			Assert::AreEqual(9, tree.get('X'));
		}

		TEST_METHOD(TestRemoveKey)
		{
			TreeMap<double, std::string> tree;
			tree.put(0.1, "Luke");
			tree.put(9.3, "Cathal");
			tree.put(4.2, "Rebecca");

			tree.removeKey(4.2);
			Assert::IsFalse(tree.containsKey(4.2));
		}

		/*TEST_METHOD(TestOperatorOverload)
		{

			TreeMap<char, int> tree;
			tree.put('C', 5);
			tree.put('X', 9);
			tree.put('I', 6);

			int num = tree[1];
			Assert::AreEqual(9, num);
		}*/

	};
}
