//--------------------------------------------------------------------------------

#ifndef INPUT_NEURON_H
#define INPUT_NEURON_H

#include "Libs.h"

class Input_neuron
{
public:
	Input_neuron	(int& aNum,double aNormalaizValue);
	~Input_neuron	();

	void	setInput	(double& arg);
	void	normalize	();

	double	getOutput	();

private:
	int	mNum;
	
	double	mInput;
	double	mOutput;
	double	mNormalaizValue;
};

#endif // INPUT_NEURON_H

//--------------------------------------------------------------------------------