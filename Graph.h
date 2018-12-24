#pragma once
class Graph
{
private:
	std::vector <int> Vert; // Вектор вершин
	int **A, n; // Матрица смежности, размерность
	std::vector <int> Path; // Вектор гамильтонова пути
	std::vector <bool> Visited; // Посещенные вершины

public:
	
	Graph();

	bool data_input(const std::string file_name); // Считывание данных из файла

	void create_A(); // Создание матрицы смежности
	bool hamilton(int curr); // Нахождение гамильтонова пути

	void data_output(const std::string file_name); // Запись пути в файл
	void no_way_answer(const std::string file_name); // Запись отрицательного ответа
	void error_output(const std::string file_name); // Вывод ошибки

	~Graph();
};

