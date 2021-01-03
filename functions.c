#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "prototypes.h"

void display_vertex(int dim, int* vertex)
{
  printf("[");
  for(int i = 0; i < dim-1; i++)
    {
      printf("%d,",vertex[i]);
    }
  printf("%d]\n",vertex[dim-1]);
  return;
}

void display_vector(int dim, VECTYPE* vector)
{
  printf("[");
  for(int i = 0; i < dim-1; i++)
    {
      printf(VECSTRING,vector[i]);
      printf(",");
    }
  printf(VECSTRING,vector[dim-1]);
  printf("]\n");
  return;
}

DimNode* add_grid_layer(int dim, int n, int breadth)
{
  DimNode* arr = (DimNode*) malloc(breadth*sizeof(DimNode));
  if(n>0)
    {
      for(int i = 0; i < breadth; i++)
	{
	  arr[i].branch = add_grid_layer(dim,n-1,breadth);
	}
      return arr;
    }
  else
    {
      for(int i = 0; i < breadth; i++)
	{
	  arr[i].vec = (float*) malloc(dim*sizeof(float));
	  double magnitude = 0;
	  for(int j = 0; j < dim; j++)
	    {
	      arr[i].vec[j] = rand() % 1;
	      magnitude += arr[i].vec[j] * arr[i].vec[j];
	    }
	  magnitude = sqrt(magnitude);
	  for(int j = 0; j < dim; j++)
	    {
	      arr[i].vec[j] /= magnitude;
	    }
	}
      return arr;
    }
}

void destroy_grid_layer(int breadth, int n, DimNode* layer)
{
  if(n > 0)
    {
      for(int i = 0; i < breadth; i++)
	{
	  destroy_grid_layer(breadth, n-1, layer->branch[i]);
	}
      free(layer->branch);
    }
  else
    {
      for(int i = 0; i < breadth; i++)
	{
	  free(layer[i].vec);
	}
    }
  free(layer);
  return;
}

Grid generate_grid(int dim, int breadth)
{
  Grid g;
  g.dim = dim;
  g.breadth = breadth;
  g.points = add_grid_layer(dim,dim,breadth);
  return g;
}

void destroy_grid(Grid g)
{
  destroy_grid_layer(g.breadth, g.dim, g.points);
  free(g.points);
  return;
}

VECTYPE perlin_noise(int dim, VECTYPE* coord, Grid points)
{
  int **vertices;
  int num_vertices = (int) pow((double)2.0,(double)dim);
  vertices = (int **) malloc(dim*sizeof(VECTYPE)*num_vertices);
  vertices[0] = (int *) malloc(dim*sizeof(int));

  // create array of surrounding vertices
  for(int d = 0; d < dim; d++)
    {
      vertices[0][d] = floor((double)coord[d]);
    }
  for(int i = 1; i < num_vertices; i++)
    {
      vertices[i] = (int *) malloc(dim*sizeof(int));
      for(int p = 0; p < dim; p++)
	{
	  vertices[i][p] = vertices[0][p] + ((i & ((int) pow((double)2.0,(double) p)))>0);
	}
    }
  // get gradients from or assign gradients to each vertex
  for(int i = 0; i < num_vertices; i++)
    {
    }     
  
  // garbage clean-up
  for(int i = 0; i < num_vertices; i++)
    {
      free(vertices[i]);
    }
  free(vertices);
  return 0.00;
}
	  
