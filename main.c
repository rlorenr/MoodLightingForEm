#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "types.h"
#include "prototypes.h"
#include "constants.h"

enum RETURN{NORMAL=0,NO_FILENAME_GIVEN};

int main(int argc, char** argv)
{
  if(argc < 2)
    {
      return NO_FILENAME_GIVEN;
    }
  Grid G = generate_grid(3,5);
  destroy_grid(G);
  
  return NORMAL;
}
