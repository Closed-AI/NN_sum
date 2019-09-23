#include "LearningSet.h"

//--------------------------------------------------------------------------------
//							 Learning set implementation
//--------------------------------------------------------------------------------
LearningSet::LearningSet(int arg)
{
	for (int val1 = 0; val1 <= arg / 2; val1++)
		for (int val2 = 0; val2 <= arg / 2; val2++)
		{
			if (val1 + val2 % 2 == 0)
			{
				arg1.emplace_back(val1);
				arg2.emplace_back(val2);
			}
			else
			{
				arg1.emplace_back(val2);
				arg2.emplace_back(val1);
			}

			ans.emplace_back(val1 + val2);
		}
}
//--------------------------------------------------------------------------------
LearningSet::~LearningSet() {}
//--------------------------------------------------------------------------------
int
LearningSet::size()
{
	return ans.size();
}
//--------------------------------------------------------------------------------
double
LearningSet::getArg1(int& id)
{
	return arg1[id];
}
//--------------------------------------------------------------------------------
double
LearningSet::getArg2(int& id)
{
	return arg2[id];
}
//--------------------------------------------------------------------------------
double
LearningSet::getAns(int& id)
{
	return ans[id];
}
//--------------------------------------------------------------------------------