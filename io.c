#include <stdio.h>
#include <stdlib.h>

char *read_file(char *filename, int *text_len)
{
  char *buffer = NULL;
  int string_size, read_size;
  FILE *handler = fopen(filename, "r");

  if (!handler)
  {
    return buffer;
  }

  fseek(handler, 0, SEEK_END);
  string_size = ftell(handler);
  *text_len = string_size;
  rewind(handler);

  buffer = (char *)malloc(sizeof(char) * (string_size + 1));
  read_size = fread(buffer, sizeof(char), string_size, handler);
  buffer[string_size] = '\0';

  fclose(handler);
  return buffer;
}

void *write_file(char *filename, unsigned char *content)
{
  FILE *handler = fopen(filename, "w");
  fprintf(handler, "%s", content);
  fclose(handler);
}