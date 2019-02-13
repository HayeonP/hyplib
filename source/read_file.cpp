#include "hyplibDef.h"

void read_file(string path, vector<string>& data) {
	ifstream in_stream(path);
	string input;

	while (!in_stream.eof()) {
		getline(in_stream, input);
		data.push_back(input);
	}
	in_stream.close();
}