#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "prototypes.h"
#include "functions.h"

enum RETURN{NORMAL=0,NO_FILENAME_GIVEN};

int main(int argc, char** argv)
{
  if(argc < 2)
    {
      return NO_FILENAME_GIVEN;
    }
  
  
  return NORMAL;
}
