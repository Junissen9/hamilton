#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"

using namespace std;

Graph::Graph()
{
}

bool Graph::data_input(const string file_name) { // Считывание данных из файла

	int tek;
	ifstream in_file;
	in_file.open(file_name);

	if (in_file) { // если файл успешно открылся
		if (in_file >> n && n>0) {
			while (!in_file.eof()) {
				if(in_file >> tek && tek>0)
				Vert.push_back(tek);
				else return false;
			}
		}
		else return false;
	}
	else return false;
	in_file.close();

	return true;
};

void Graph::create_A() { // Создание матрицы смежности
	A = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
		A[i] = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sqrt(Vert[i] + Vert[j]) - (int)sqrt(Vert[i] + Vert[j]) < 0.001) A[i][j] = 1;
			else A[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) // Инициализация вектора посещения вершин
		Visited.push_back(false);
};


bool Graph::hamilton(int curr) // Нахождение гамильтонова пути
{
	Path.push_back(curr);

	if (Path.size() == n)
		return true;

	Visited[curr] = true;

	for (int nxt = 0; nxt < n; ++nxt) {
		if (A[curr][nxt] == 1 && !Visited[nxt])
			if (hamilton(nxt)) return true;
	}
	Visited[curr] = false;
	Path.pop_back();

	return false;
};

void Graph::data_output(const string file_name) { // Запись пути в файл
	
	ofstream answerFile;
	answerFile.open(file_name);

	for (int i = 0; i < n; i++) {
		answerFile << Vert[Path[i]] << " ";
	}

	answerFile.close();
}

void Graph::no_way_answer(const string file_name) { // Запись отрицательного ответа

	ofstream no_wayFile;
	no_wayFile.open(file_name);

	no_wayFile << "It's impossible";

	no_wayFile.close();
}


void Graph::error_output(const string file_name) { // Вывод ошибки

	ofstream errorFile;
	errorFile.open(file_name);

	errorFile << "Error";

	errorFile.close();
}


Graph::~Graph()
{
}
