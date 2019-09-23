//--------------------------------------------------------------------------------

#ifndef OUTPUT_NEURON
#define OUTPUT_NEURON

#include "Libs.h"

class Output_neuron
{
public:
	Output_neuron	(int inp_size,int& aNum, double& aLearningRate);
	~Output_neuron	();

	void	setInputs	(std::vector<double>& aInputs);
	void	multiplie	();
	void	sigmoid_x	();
	void	setError	(double& arg);
	void	weightsCor	();

	int		getNum		();

	double	getError	();
	double	getOutput	();
	double	getWeight	(int id);
	double	sigmoid_x	(double& arg);
	double	sigmoid_dx	(double& arg);
	double	weightsDelta();

private:
	std::vector<double>	mInputs;
	std::vector<double>	mWeights;

	int	mNum;

	double	mSum;
	double	mError;
	double	mOutput;
	double	mLearningRate;
};

#endif // OUTPUT_NEURON

//--------------------------------------------------------------------------------