#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct strarray
{
  char **strarr;
  int length;
};

void assign(struct strarray *out, int i, char *val)
{
  int length = strlen(val);
  out->strarr[i] = malloc(length + 1);
  strcpy(out->strarr[i], val);
}

void assign_array(struct strarray *out, char **val, int i)
{
  out->length = i;
  out->strarr = malloc(i);

  int j;
  for (j = 0; j < i; j++) {
    assign(out, j, val[j]);
  }
}

void strarray_free(struct strarray *out)
{
  int i;
  for (i = 0; i < out->length; i++) {
    free(out->strarr[i]);
  }
  free(out->strarr);
}

void outfunction(struct strarray *out)
{
  char *arr[3] = { "hello", "awesome", "world" };

  assign_array(out, arr, 3);
}
