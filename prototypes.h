#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

#include "types.h"

#define VECTYPE float
#define VECSTRING "%+.2f"

void display_vertex(int,int*);
void display_vector(int,VECTYPE*);
DimNode* add_grid_layer(int,int,int);
void destroy_grid_layer(int,int,DimNode*);
Grid generate_grid(int,int);
void destroy_grid(Grid);
VECTYPE perlin_noise(int,VECTYPE*,Grid);

#endif
