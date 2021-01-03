#include <math.h>

#include "prototypes.h"

float PerlinNoise(int dim, float* coord)
{
  int **vertices;
  int num_vertices = (int) floor(pow(2,dim));
  vertices = (int *) malloc(num_vertices);
  vertices[0] = (int) malloc(dim);
  for(int d = 0; d < dim; d++)
    {
      vertices[0][d] = floor(coord[d]);
    }
  for(int i = 1; i < num_vertices; i++)
    {
      vertices[i] = (int) malloc(dim);
      for(int p = 0; p < dim; p++)
	{
	  vertices[i][p] = 
