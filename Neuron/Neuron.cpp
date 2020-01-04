
#include "Lay.h"
#include "ApiNeuron.h"
#include <iostream>
/*Lay lay(3, 3);
Lay lay1(2, 3);
Lay lay2(2, 2);
std::vector<float> activate(std::vector<float> in) {
	lay.putIn(in);
	lay1.putIn(lay.getOut());
	lay2.putIn(lay1.getOut());
	return lay2.getOut();
}
void learn(std::vector<float> in,std::vector<float> out) {
	for (int i = 0; i < out.size(); i++) {
		out.at(i) = out.at(i) - activate(in).at(i);
	}
		std::vector<float> errors = lay2.learn(out, lay1.getOut());
		errors = lay1.learn(errors, lay.getOut());
		errors = lay.learn(errors, in);
	
	}*/
int main()
{
	ApiNeuron api({3,3,2,2});
	std::vector<float> otvet = api.activate({ 1,0,1 });
	for (int i = 0; i < otvet.size();i++) {
		std::cout << otvet.at(i) << " ";
	}
	api.learn(10000,{ 1,0,1 }, {0,1});
	std::cout << "\n";
	otvet = api.activate({ 1,0,1 });
	for (int i = 0; i < otvet.size(); i++) {
		std::cout << otvet.at(i) << " ";
	}
	/*for (int i = 0; i < 3; i++) {
		for (int o = 0; o < 1;o++) {
			std::cout << "-";
			std::cout << lay.getNeurons().at(i).at(o);
		}
		std::cout << "\n";
	}
	lay.putIn({0,0,0});
	lay1.putIn(lay.getOut());
	lay2.putIn(lay1.getOut());
	activate({1,0,0});
	for (int i = 0; i < 1; i++) {
	std::cout << lay2.getOut().at(i) << " ";
	}
	std::cout << "\n";
	for (int i = 0; i <100000;i++) {
		learn({ 1,0,0 }, {1,1});
		learn({ 1,1,1 }, {0,1});
		learn({ 0,1,1 }, { 0,0 });
	}
	activate({1,0,0});
	for (int i = 0; i < 2; i++) {
		std::cout << lay2.getOut().at(i) << " ";
	}
	activate({ 1,1,1 });
	for (int i = 0; i < 2; i++) {
		std::cout << lay2.getOut().at(i) << " ";
	}
	activate({ 0,1,1 });
	for (int i = 0; i < 2; i++) {
		std::cout << lay2.getOut().at(i) << " ";
	}*/
}

