#ifndef __TYPES_H__
#define __TYPES_H__

typedef union DimNodes {
  union DimNode* branch;
  float* vec;
} DimNode;

typedef struct Grids {
  union DimNode* points;
  int breadth;
  int dim;
} Grid; 

#endif
