#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

namespace PHY {
	typedef vector<string> nodelist;

	class TextLabelEditor {
	public:
	//private:
		string filepath_;
		// input file path
		char token_;
		// char data classifier of each components.
		// Deafult is ' '
		vector< nodelist > node_line_list_;
		vector< string > str_line_list_;

	public:
		TextLabelEditor(string filepath);
		TextLabelEditor(string filepath, char token);
		// Open file + Create line_list and component_list
		string node_line_to_string_line(nodelist data);
		// change vector line data to string line data
		nodelist string_line_to_node_line(string data);
		void set_line(int location, string data);
		void set_line(int location, nodelist data);
		
		string get_str_line(int line_num);
		nodelist get_node_line(int line_num);
		void print_line(int line_num);
		void print_data();
		void write_data(vector<string> data);
		void write_data(vector<nodelist> data);
		
	};
}
