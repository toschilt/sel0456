#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SSIZE 1024

void
write_data (FILE * stream)
{
  int i;
  for (i = 0; i < 100; i++)
    fprintf (stream, "%d\n", i);
  if (ferror (stream))
    {
      fprintf (stderr, "Output to stream failed.\n");
      exit (EXIT_FAILURE);
    }
}

int main (void)
{
  FILE *in;
  size_t n = SSIZE;
  char * s = malloc(n);
  int r;

  in = popen ("ls -la", "w");
  if (!in) {
    fprintf (stderr, "incorrect parameters or too many files.\n");
    return EXIT_FAILURE;
  }
  while ((r = getline(&s, &n, in)) > 0) {
    puts(s);
  }
  free(s);
  return EXIT_SUCCESS;
}