//--------------------------------------------------------------------------------

#ifndef	NEURAL_NET
#define NEURAL_NET

#include "Input_neuron.h"
#include "Hidden_neuron.h"
#include "Output_neuron.h"

class NeuralNet
{
public:
	NeuralNet	(int input_size, int hidden_size, 
				 int output_size,double aLearningRate);
	~NeuralNet	();

	void	learn	(double arg1, double arg2, double trueAns);

	int		work	(double arg1, double arg2);

private:
	std::vector<Input_neuron>	input_layer;
	std::vector<Hidden_neuron>	hidden_layer;
	std::vector<Output_neuron>	output_layer;

	double	mError;
	double	mLearningRate;
};

#endif //NEURAL_NET

//--------------------------------------------------------------------------------