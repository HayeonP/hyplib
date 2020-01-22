// Added by PHY
#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <thread>
#include <mutex>

class CsvLogger{
private:
  inline bool is_exists (const std::string& filename);
  void create_log_file();
private:
  std::string prefix_;
	std::string tag_;
  std::string path_;
  std::ofstream fout_;
public:
  CsvLogger();
  CsvLogger(std::string prefix, std::string tag);
  CsvLogger(std::string prefix, std::string tag, std::string path);
  void init();
  void init(std::string prefix, std::string tag);
  void init(std::string prefix, std::string tag, std::string path);
  void write(std::vector<std::string> data);
public:
  
};