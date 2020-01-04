#include "ApiNeuron.h"

ApiNeuron::ApiNeuron(std::vector<int> lays1) { // 1 значение количество входящих чисел
	for (int i = 1; i < lays1.size();i++) {
		lays.push_back(Lay(lays1.at(i),lays1.at(i-1)));
	}
}
void ApiNeuron::learn(int iterations, std::vector<float> in, std::vector<float> out) {
	for (int i = 0; i < out.size(); i++) {
		out.at(i) = out.at(i) - activate(in).at(i);
	}
	for (int p = 0; p < iterations;p++) {
		std::vector<float> errors = out;
		for (int i = lays.size() - 1; i > 0; i--) {
			errors = lays.at(i).learn(errors, lays.at(i -1).getOut());
		}
		lays.at(0).learn(out, in);
	}
}
std::vector<float> ApiNeuron::activate(std::vector<float>input) {
	lays.at(0).putIn(input);
	for (int i = 1; i < lays.size();i++) {
		lays.at(i).putIn(lays.at(i-1).getOut());
	}
	return lays.at(lays.size() - 1).getOut();
}
std::vector<float> ApiNeuron::getOtvet() {
	return lays.at(lays.size() - 1).getOut();
}