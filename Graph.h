#pragma once
class Graph
{
private:
	std::vector <int> Vert; // ������ ������
	int **A, n; // ������� ���������, �����������
	std::vector <int> Path; // ������ ������������ ����
	std::vector <bool> Visited; // ���������� �������

public:
	
	Graph();

	bool data_input(const std::string file_name); // ���������� ������ �� �����

	void create_A(); // �������� ������� ���������
	bool hamilton(int curr); // ���������� ������������ ����

	void data_output(const std::string file_name); // ������ ���� � ����
	void no_way_answer(const std::string file_name); // ������ �������������� ������
	void error_output(const std::string file_name); // ����� ������

	~Graph();
};

