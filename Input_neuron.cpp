#include "Input_neuron.h"

//--------------------------------------------------------------------------------
//							 Input neuron implementation
//--------------------------------------------------------------------------------
Input_neuron::Input_neuron(int& aNum,double aNormalaizValue) :
	mNum(aNum),
	mNormalaizValue(aNormalaizValue)
{}
//--------------------------------------------------------------------------------
Input_neuron::~Input_neuron()
{}
//--------------------------------------------------------------------------------
void 
Input_neuron::setInput(double& aInput) 
{
	Input_neuron::mInput = aInput;
	
	return;
}
//--------------------------------------------------------------------------------
void 
Input_neuron::normalize()
{
	mOutput = mInput / mNormalaizValue;

	return;
}
//--------------------------------------------------------------------------------
double
Input_neuron::getOutput()
{
	return mOutput;
}
//--------------------------------------------------------------------------------