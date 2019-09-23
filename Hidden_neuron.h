//--------------------------------------------------------------------------------

#ifndef HIDDEN_NEURON_H
#define HIDDEN_NEURON_H

#include "Libs.h"

class Hidden_neuron
{
public:
	Hidden_neuron	(int inp_size,int& aNum, double& aLearningRate);
	~Hidden_neuron	();

	void	setInputs	(std::vector<double>& aInputs);
	void	multiplie	();
	void	sigmoid_x	();
	void	weightsCor	();
	void	setError	(double arg);

	int		getNum		();

	double	getError	();
	double	getOutput	();
	double	sigmoid_x	(double& arg);
	double	sigmoid_dx	(double& arg);
	double	weightsDelta();

private:
	std::vector<double>	mInputs;
	std::vector<double>	mWeights;

	int	mNum;

	double	mSum;
	double	mError;
	double	mOffset;
	double	mOutput;
	double	mLearningRate;
};

#endif //HIDDEN_NEURON_H

//--------------------------------------------------------------------------------