// Added by PHY
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
  std::ofstream fout_;
public:
  CsvLogger(std::string prefix, std::string tag) : prefix_(prefix), tag_(tag) {}
  void init();
  void write(std::vector<std::string> data);
public:
  
};

void CsvLogger::init(){
  create_log_file();
}

bool CsvLogger::is_exists (const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void CsvLogger::create_log_file(){
  std::string file_name = prefix_;
  int file_idx = 0;
  while(1){
    auto idx = file_name.find(".");
    file_name = file_name.substr(0, idx);
    if(file_idx == 0){
			file_name += std::string("_");
			file_name += tag_;
      file_name += std::string(".csv");
		}
    else{
			idx = file_name.find("(");
			file_name = file_name.substr(0, idx);
      file_name = file_name+std::string("(") + std::to_string(file_idx)+std::string(")") + std::string("_") + tag_ + std::string(".csv");
		}
    
    if(!is_exists(file_name)) break;
    file_idx++;
		std::cout<<"temp filename : "<<file_name<<std::endl;
  }
  
  std::cout<<"File name : "<<file_name<<std::endl;

  fout_.open(file_name, std::ofstream::binary);
}

void CsvLogger::write(std::vector<std::string> data){
  bool isBegin = true;
  for(auto it = data.begin(); it != data.end(); ++it){
    if(isBegin) isBegin = false;
    else fout_<<", ";
    fout_ << *it;
  }
  fout_ << "\n";
  fout_.flush();
}
