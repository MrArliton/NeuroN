#include "Lay.h"
using namespace std;
Lay::Lay(int neurons,int weights) { // �����������
	Lay::neurons.resize(neurons);
	for (int i = 0; i < neurons; i++) {
		Lay::neurons.at(i).resize(weights);
	}
	out.resize(neurons);
	for (int i = 0; i < neurons;i++) {
		for (int o = 0; o < weights;o++) {
			Lay::neurons.at(i).at(o) = (rand()%100)/100.0;
		}
	}
}
float Lay::sigmoid(float value) { //������������� ������� ��������
	return 1.0 / (1.0 + exp(-value));
}
vector<vector<float>> Lay::getNeurons() { 
	return Lay::neurons;
}
void Lay::putIn(vector<float> out) { // ���� �������� � ����������� ����
	for (int i = 0; i < neurons.size();i++) {
		for (int o = 0; o < out.size();o++) {
			Lay::out.at(i) += neurons.at(i).at(o)*out.at(o);
		}
		Lay::out.at(i) = sigmoid(Lay::out.at(i));
	}

}
vector<float> Lay::getOut() {
	return out;
}
vector<float> Lay::learn(vector<float> error, std::vector<float> out) { // ��������
	float weight_delta;
/*	cout << "=" << neurons.size() << "=";
	for (int i = 0; i < error.size();i++) {
	cout <<	neurons.at(i).size() << "==";
	}
	//cout << "-1-";*/
	vector<float> errors(out.size()); // ������ ��� �������� ������ ���������� ����
	for (int i = 0; i < error.size(); i++) {
	//	cout << " 3 ";
		weight_delta = error.at(i) * Lay::out.at(i) * (1 - Lay::out.at(i)); // ����� �����
	//	cout << " 4 ";
		for (int o = 0; o < out.size(); o++) {
		//	cout << "-7-";
		//	cout << neurons.at(i).size();
			neurons.at(i).at(o) = neurons.at(i).at(o) + out.at(o) * weight_delta * learning_rate; // ����������� �������� �����
		//	cout << "---";
			errors.at(o) += neurons.at(i).at(o) * weight_delta; // ������� ����� �����
		//	cout << "-6-";
		}
	//	cout << " 5 ";
	}
	//cout << "-2-";
	return errors;
}