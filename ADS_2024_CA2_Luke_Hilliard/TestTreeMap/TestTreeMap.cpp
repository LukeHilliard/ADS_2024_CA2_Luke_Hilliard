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

		TEST_METHOD(TestGet)
		{
			TreeMap<char, int> tree;
			tree.put('C', 5);
			tree.put('X', 9);
			tree.put('I', 6);

			Assert::AreEqual(9, tree.get('X'));
		}

		TEST_METHOD(TestKeySet)
		{
			TreeMap<char, int> tree;
			tree.put('C', 5);
			tree.put('X', 9);
			tree.put('I', 6);

			BinaryTree<char> base;
			base.add('C');
			base.add('X');
			base.add('I');

			;			BinaryTree<char> keys = tree.keySet();
			Assert::AreEqual(keys, base);
		}

		TEST_METHOD(TestPut)
		{
			TreeMap<int, int> tree;
			tree.put(1, 0);

			Assert::IsTrue(tree.containsKey(1));
		}

	};
}
