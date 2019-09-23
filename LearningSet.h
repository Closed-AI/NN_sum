//--------------------------------------------------------------------------------

#ifndef	LEARNING_SET
#define LEARNING_SET

#include "Libs.h"

class LearningSet
{
public:
	LearningSet	(int arg);
	~LearningSet();

	int		size	();

	double	getArg1	(int& id);
	double	getArg2	(int& id);
	double	getAns	(int& id);

private:
	std::vector<double> arg1;
	std::vector<double> arg2;
	std::vector<double> ans;
};

#endif //LEARNING_SET

//--------------------------------------------------------------------------------