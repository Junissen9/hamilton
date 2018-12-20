// project 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector <int> Vert; //Вектор вершин
int **A, n; //Матрица смежности, размерность
vector <int> Path; //Вектор гамильтонова пути
vector <bool> Visited; //Посещенные вершины

bool data_input(const string file_name) {  // Считывание данных из файла
	
	int tek;
	ifstream in_file;
	in_file.open(file_name);

	if (in_file) { // если файл успешно открылся
		if (in_file >> n) {
			while (!in_file.eof()) {
				in_file >> tek;
				Vert.push_back(tek);
			}
		}
		else return false;
	}
	else return false;
	in_file.close(); 

	return true;
};

void create_A () { // Создание матрицы смежности
	A = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
		A[i] = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sqrt(Vert[i] + Vert[j]) - (int)sqrt(Vert[i] + Vert[j]) < 0.001) A[i][j] = 1;
			else A[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)  // Инициализация вектора посещения вершин
		Visited.push_back(false);
};


bool hamilton(int curr) // Нахождение гамильтонова пути
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

void data_output(const string file_name) { // Запись пути в файл
	ofstream answerFile;
	answerFile.open(file_name);

	for (int i = 0; i < n; i++) {
		answerFile << Vert[Path[i]] << " ";
	}

	answerFile.close();
}

void no_way_answer(const string file_name) { // Запись отрицательного ответа
	ofstream no_wayFile;
	no_wayFile.open(file_name);

	no_wayFile << "It's impossible";

	no_wayFile.close();
}


void error_output(const string file_name) { // Вывод ошибки
	ofstream errorFile;
	errorFile.open(file_name);

	errorFile << "Error";

	errorFile.close();
}

int main(int argc, char* argv[])
{
	if (data_input(argv[1])) {

		create_A();

		if (hamilton(0)) data_output(argv[2]);
		else no_way_answer(argv[2]);
	
	}
	else error_output(argv[2]);

	system("pause");
    return 0;
}

