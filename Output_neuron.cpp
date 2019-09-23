#include "Output_neuron.h"

//--------------------------------------------------------------------------------
//							 Output neuron implementation
//--------------------------------------------------------------------------------
Output_neuron::Output_neuron(int inp_size,int& aNum, double& aLearningRate) :
	mNum(aNum),
	mLearningRate(aLearningRate)
{
	mInputs.resize(inp_size);
	mWeights.resize(inp_size);

	for (auto& i : mWeights)
		i = (double(rand() % 1000) - 500) / 1000.;
}
//--------------------------------------------------------------------------------
Output_neuron::~Output_neuron() {}
//--------------------------------------------------------------------------------
void
Output_neuron::setInputs(std::vector<double>& aInputs)
{
	mInputs.resize(aInputs.size());

	for (int i = 0; i < aInputs.size(); i++)
		mInputs[i] = aInputs[i];

	return;
}
//--------------------------------------------------------------------------------
void
Output_neuron::multiplie()
{
	mSum = 0;

	for (int i = 0; i < mInputs.size(); i++)
		mSum += mInputs[i] * mWeights[i];

	return;
}
//--------------------------------------------------------------------------------
void
Output_neuron::sigmoid_x()
{
	mOutput = 1. / (1. + exp(-1 * mSum));

	return;
}
//--------------------------------------------------------------------------------
void
Output_neuron::setError(double& ExpRes)
{
	mError = mOutput - ExpRes;

	return;
}
//--------------------------------------------------------------------------------
void
Output_neuron::weightsCor()
{
	double del = weightsDelta();

	for (int i = 0; i < mWeights.size(); i++)
		mWeights[i] -= mLearningRate * del * mInputs[i];

	return;
}
//--------------------------------------------------------------------------------
int
Output_neuron::getNum()
{
	return mNum;
}
//--------------------------------------------------------------------------------
double
Output_neuron::getError()
{
	return mError;
}
//--------------------------------------------------------------------------------
double
Output_neuron::getOutput()
{
	return mOutput;
}
//--------------------------------------------------------------------------------
double
Output_neuron::getWeight(int id)
{
	return mWeights[id];
}
//--------------------------------------------------------------------------------
double
Output_neuron::sigmoid_x(double& arg)
{
	return 1. / (1. + exp(-1 * arg));
}
//--------------------------------------------------------------------------------
double
Output_neuron::sigmoid_dx(double& arg)
{
	return sigmoid_x(arg) * (1 - sigmoid_x(arg));
}
//--------------------------------------------------------------------------------
double
Output_neuron::weightsDelta()
{
	return mError * sigmoid_dx(mSum);
}
//--------------------------------------------------------------------------------