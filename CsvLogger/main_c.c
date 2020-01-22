// Implemented by Hayeon Park
#include "CsvLogger.h"

static FILE *logger;

void main(int argc, char* argv[]){
  char filename[] = "test.csv";
  
  logger = fopen(filename, "w+");

  char* a = "one";
  char* b = "two";
  char* c = "three";

  char* datas[] = {a,b,c};

  write_csv_data(logger, datas, 3);
  
  fsync(fileno(logger));
  fclose(logger);

  return;
}

