// Implemented by Hayeon Park
#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void write_csv_data(FILE *fp, char* data[], int category_num);