#include "hyplibDef.h"

void write_file(string path, vector<string> data) {
	ofstream out_stream(path);
	for (int idx = 0; idx < data.size(); idx++) {
		out_stream << data[idx];
	}
	out_stream.close();
}
