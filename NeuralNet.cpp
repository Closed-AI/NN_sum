#include "NeuralNet.h"

//--------------------------------------------------------------------------------
//							 Neural network implementation
//--------------------------------------------------------------------------------
NeuralNet::NeuralNet(int input_size, int hidden_size,
	int output_size, double aLearningRate) :
	mLearningRate(aLearningRate)
{
	//make the input layer
	for (int i = 0; i < input_size; i++)
		input_layer.emplace_back(Input_neuron(i, double(output_size)));
	//end
	//----------------------------------------------------------------------------
	//make the hidden layers

	for (int i = 0; i < hidden_size; i++)
		hidden_layer.emplace_back(Hidden_neuron(input_size,i, mLearningRate));
	//end
	//----------------------------------------------------------------------------
	//make the output layer
	for (int i = 0; i < output_size; i++)
		output_layer.emplace_back(Output_neuron(hidden_size, i, mLearningRate));
	//end
	//----------------------------------------------------------------------------
}
//--------------------------------------------------------------------------------
NeuralNet::~NeuralNet() {};
//--------------------------------------------------------------------------------
void
NeuralNet::learn(double arg1, double arg2, double trueAns) //to do
{
	//generating expected results for the output layer
	double par = output_layer.size();

	std::vector<double> true_results(par,0);
	
	true_results[trueAns] = 1;

	for (int i = trueAns + 1; i < true_results.size(); i++)
		true_results[i] = true_results[i - 1] - 1. / par;

	for (int i = trueAns -1; i >=0; i--)
		true_results[i] = true_results[i + 1] - 1. / par;
	//end

	//output layer's learn
	//std::vector<double> error_to_hidden;
	std::vector<double> error_to_hidden(hidden_layer.size());

	for (auto& i : output_layer)
	{
		i.setError(true_results[i.getNum()]);

		for (int j = 0; j < error_to_hidden.size(); j++)
		{
			error_to_hidden[j] += i.getError() * i.getWeight(j);
		}

		i.weightsCor();
	}
	//end

	//hidden layer's learn
	for (auto& i : hidden_layer)
	{
		i.setError(error_to_hidden[i.getNum()]);
		i.weightsCor();
	}

	return;
}
//--------------------------------------------------------------------------------
int
NeuralNet::work(double arg1, double arg2)
{
	//input layer's work
	input_layer[0].setInput(arg1);
	input_layer[1].setInput(arg2);

	std::vector<double> output_of_input_layer;

	for (auto& i : input_layer)
	{
		i.normalize();
		output_of_input_layer.emplace_back(i.getOutput());
	}
	//end
	//----------------------------------------------------------------------------
	//hiden layer's work
	std::vector<double> output_of_hidden_layer;
	
	for (auto& i : hidden_layer)
	{
		i.setInputs(output_of_input_layer);
		i.multiplie();
		i.sigmoid_x();
		output_of_hidden_layer.emplace_back(i.getOutput());
	}
	//end
	//----------------------------------------------------------------------------
	//output layer's work
	double val = 0;
	
	int ans = 0;

	for (auto& i : output_layer)
	{
		i.setInputs(output_of_hidden_layer);
		i.multiplie();
		i.sigmoid_x();

		if (val < i.getOutput())
		{
			val = i.getOutput();
			ans = i.getNum();
		}
	}
	//end
	//----------------------------------------------------------------------------
	return ans;
}
//--------------------------------------------------------------------------------