#include "CsvLogger.hpp"

int main(int argc, char* argv[]){
    std::vector<std::string> indices;
    indices.push_back(std::string("index1"));
    indices.push_back(std::string("index2"));
    std::string prefix("Prefix");
    std::string tag("Tag");
    
    CsvLogger testLogger(prefix, tag);
    testLogger.init();
    std::vector<std::string> data;
    data.push_back("a"); data.push_back(std::to_string(1.2)); data.push_back(std::to_string(1));
    testLogger.write(data);
    
    return 0;
}
