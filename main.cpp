#include "NeuralNet.h"
#include "LearningSet.h"

int main()
{
#define N	int(21)		//Net's max output
#define LR	double(0.4)	//learning rate
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	srand(time(NULL));

	NeuralNet Net(2, N, N, LR);//int input_size, int hidden_size, int output_size, double aLearningRate

	LearningSet learnSet(N);

	double ansRate;

	while (!false)
	{
		ansRate = 0;

		for (int i = 0; i < learnSet.size(); i++)
		{
			if (Net.work(learnSet.getArg1(i), learnSet.getArg2(i)) != learnSet.getAns(i))
			{
				Net.learn(learnSet.getArg1(i), learnSet.getArg2(i), learnSet.getAns(i));
			}
			else ansRate++;
		}

		if (ansRate == learnSet.size()) break;
		std::cout << std::fixed << ansRate / double(learnSet.size()) << '\n';
	}

	int val1;
	int val2;

	while (!false)
	{
		std::cin >> val1 >> val2;

		if (val1 < 0 || val2 < 0) break;
		else std::cout << Net.work(val1, val2) << "\n\n";
	}

	return 0;
}