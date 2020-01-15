#include "CsvLogger.h"

CsvLogger::CsvLogger(){
  prefix_= std::string("NoPrefix"); 
  tag_ = std::string("NoTag");
  path_ = std::string(".");
}

CsvLogger::CsvLogger(std::string prefix, std::string tag){
   prefix_ = prefix;
   tag_ = tag;
   path_ = std::string(".");
}

CsvLogger::CsvLogger(std::string prefix, std::string tag, std::string path){
   prefix_ = prefix;
   tag_ = tag;
   path_ = path;
}

void CsvLogger::init(){
  create_log_file();
}

void CsvLogger::init(std::string prefix, std::string tag){
  prefix_ = prefix;
  tag_ = tag;
  init();
}

void CsvLogger::init(std::string prefix, std::string tag, std::string path){
  prefix_ = prefix;
  tag_ = tag;
  path_ = path;
  init();
}

bool CsvLogger::is_exists (const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void CsvLogger::create_log_file(){
  std::string file_name = prefix_;
  std::string file_path;
  std::cout << path_ <<std::endl;
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
      file_name = file_name+std::string("(") + std::to_string(file_idx)+std::string(")") /*+ std::string("_") + tag_*/ + std::string(".csv");
		}
    
    file_path = path_ + std::string("/") + file_name;
    if(!is_exists(file_path)) break;
    file_idx++;
		
  }
  std::cout<<"File path : "<<file_path<<std::endl;

  fout_.open(file_path, std::ofstream::binary);
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