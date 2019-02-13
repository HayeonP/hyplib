#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;


string change_file_extention(string filename, string extention);
vector<string> get_filepaths_in_directory(string path);
void write_file(string path, vector<string> data);
void read_file(string path, vector<string>& data);