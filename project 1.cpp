// project 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[]) {

	Graph G;

	if (G.data_input(argv[1])) {

		G.create_A();

		if (G.hamilton(0)) G.data_output(argv[2]);
		else G.no_way_answer(argv[2]);
	
	}
	else G.error_output(argv[2]);

	system("pause");
    return 0;
}

