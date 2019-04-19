#include "TextLabelEditor.h"

namespace PHY {
	TextLabelEditor::TextLabelEditor(string filepath)
		: TextLabelEditor(filepath, ' ')
	{}

	TextLabelEditor::TextLabelEditor(string filepath, char token)
		: filepath_(filepath), token_(token)
	{
		ifstream in_stream(filepath_);
		
		while (!in_stream.eof()) {
			string line;
			getline(in_stream, line);
			str_line_list_.push_back(line);

			string node;
			nodelist node_list;
			istringstream node_stream(line);
			while (getline(node_stream, node, token_))
				node_list.push_back(node);
			node_line_list_.push_back(node_list);
		}
		
		in_stream.close();
	}

	string TextLabelEditor::node_line_to_string_line(nodelist data){
		string str_data;
		for (string it : data) {
			str_data += it;
			str_data += token_;
		}
		str_data.erase(str_data.end() - 1);
		return str_data;
	}

	nodelist TextLabelEditor::string_line_to_node_line(string data) {
		string node;
		nodelist node_list;
		istringstream node_stream(data);
		while (getline(node_stream, node, token_))
			node_list.push_back(node);
		
		return node_list;
	}

	void TextLabelEditor::set_line(int location, string data) {
		str_line_list_[location] = data;
		nodelist node_line = string_line_to_node_line(data);
		node_line_list_[location] = node_line;
		string str_line = node_line_to_string_line(node_line);
	}

	void TextLabelEditor::set_line(int location, nodelist data) {
		node_line_list_[location] = data;
		string str_line = node_line_to_string_line(data);
		str_line_list_[location] = str_line;
		nodelist node_line = string_line_to_node_line(str_line);
		
	}

	string TextLabelEditor::get_str_line(int line_num) {
		return str_line_list_[line_num];
	}

	nodelist TextLabelEditor::get_node_line(int line_num) {
		return node_line_list_[line_num];
	}

	void TextLabelEditor::print_line(int line_num) {
		cout << str_line_list_[line_num] << endl;
	}

	void TextLabelEditor::print_data() {
		for (string it : str_line_list_)
			cout << it << endl;
		cout << endl;

		for (nodelist it1 : node_line_list_) {
			for (string it2 : it1) {
				cout << it2 << " ";
			}
			cout << endl;
		}
	}

	void TextLabelEditor::write_data(vector<string> data) {
		ofstream out_stream(filepath_);
		for (string it : data)
			out_stream << it << "\n";
		out_stream.close();
	}

	void TextLabelEditor::write_data(vector<nodelist> data) {
		ofstream out_stream(filepath_);
		for (nodelist it : data)
			out_stream << node_line_to_string_line(it) << "\n";
		out_stream.close();
	}

}

