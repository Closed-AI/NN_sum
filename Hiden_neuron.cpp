#include "Hidden_neuron.h"

//--------------------------------------------------------------------------------
//							 Hidden neuron implementation
//--------------------------------------------------------------------------------
Hidden_neuron::Hidden_neuron(int inp_size,int& aNum,double& aLearningRate) :
	mNum(aNum),
	mError(0),
	mLearningRate(aLearningRate)
{
	mInputs.resize(inp_size);
	mWeights.resize(inp_size);
	
	for (auto& i : mWeights)
		i = (double(rand() % 1000) - 500) / 1000.;

	mOffset = (double(rand() % 1000) - 500) / 1000.;
}
//--------------------------------------------------------------------------------
Hidden_neuron::~Hidden_neuron() {}
//--------------------------------------------------------------------------------
void
Hidden_neuron::setInputs(std::vector<double>& aInputs)
{
	mInputs.resize(aInputs.size());

	for (int i = 0; i < aInputs.size(); i++)
		mInputs[i] = aInputs[i];

	return;
}
//--------------------------------------------------------------------------------
void
Hidden_neuron::multiplie()
{
	mSum = 0;
	
	for (int i = 0; i < mInputs.size(); i++)
		mSum += mInputs[i] * mWeights[i];

	mSum += mOffset;
	
	return;
}
//--------------------------------------------------------------------------------
void
Hidden_neuron::sigmoid_x()
{
	mOutput = 1. / (1. + exp(-1 * mSum));

	return;
}
//--------------------------------------------------------------------------------
void
Hidden_neuron::setError(double arg)
{
	mError = arg;

	return;
}
//--------------------------------------------------------------------------------
void
Hidden_neuron::weightsCor()
{
	double del = weightsDelta();

	for (int i = 0; i < mWeights.size(); i++)
		mWeights[i] -= mLearningRate * del * mInputs[i];

	mOffset -= mLearningRate * del;

	return;
}
//--------------------------------------------------------------------------------
int
Hidden_neuron::getNum()
{
	return mNum;
}
//--------------------------------------------------------------------------------
double
Hidden_neuron::getError()
{
	return mError;
}
//--------------------------------------------------------------------------------
double
Hidden_neuron::getOutput()
{
	return mOutput;
}
//--------------------------------------------------------------------------------
double 
Hidden_neuron::sigmoid_x(double& arg)
{
	return 1. / (1. + exp(-1 * arg));
}
//--------------------------------------------------------------------------------
double 
Hidden_neuron::sigmoid_dx(double& arg) 
{
	return sigmoid_x(arg) * (1 - sigmoid_x(arg));
}
//--------------------------------------------------------------------------------
double
Hidden_neuron::weightsDelta()
{
	return mError * sigmoid_dx(mSum);
}
//--------------------------------------------------------------------------------