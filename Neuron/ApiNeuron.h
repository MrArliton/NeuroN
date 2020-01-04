#pragma once
#include "Lay.h"
class ApiNeuron
{
private:
	std::vector<Lay> lays;
public:
	ApiNeuron(std::vector<int> lays);
	void learn(int iterations,std::vector<float> input,std::vector<float> output);
	std::vector<float> activate(std::vector<float>input);
	std::vector<float> getOtvet();
};

