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
	};
}
