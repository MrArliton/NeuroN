#pragma once
#include <vector>
class Lay
{
private:
	std::vector<std::vector<float>> neurons;
	float sigmoid(float value);
	std::vector<float> out;
	const float learning_rate = 0.02f;
public:
	Lay(int neurons, int weights);
	void putIn(std::vector<float> out);
	std::vector<float> getOut();
	std::vector<std::vector<float>> getNeurons();
	std::vector<float> learn(std::vector<float> error, std::vector<float> out);
};


