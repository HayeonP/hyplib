#include "hyplibDef.h"

string change_file_extention(string filename, string extention) {
	istringstream ss(filename);
	while (getline(ss, filename, '\\')) {}
	ss = istringstream(filename);
	getline(ss, filename, '.');
	filename = filename + "." + extention;
	return filename;
}