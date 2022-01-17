/*============================================================================

  rationalize

  main.c

  Turn a floating-point decimal number into a fraction, with specified
  precision.

  Copyright (c)2022 Kevin Boone, GPL 3.0

============================================================================*/
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include "rationalize.h" 

/*============================================================================

  show_usage

============================================================================*/
void show_usage (const char *argv0, FILE *out)
  {
  fprintf (out, "Usage: %s [options] { number | - }\n", argv0);
  fprintf (out, "  -i,--improper   show an improper (\"top-heavy\") fraction\n");
  fprintf (out, "  -o,--order=N    figures of precision required (3)\n");
  fprintf (out, "  -v,--version    show the version\n");
  }

/*============================================================================

  main 

============================================================================*/
int main (int argc, char **argv)
  {
  int ret = 0;
  int order = 3;
  BOOL improper = FALSE;
  BOOL version = FALSE;
  BOOL help = FALSE;
  BOOL carry_on = TRUE;
  
 static struct option long_options[] =
    {
      {"help", no_argument, NULL, 'h'},
      {"improper", no_argument, NULL, 'i'},
      {"order", required_argument, NULL, 'o'},
      {"version", no_argument, NULL, 'v'},
      {0, 0, 0, 0}
    };

  int opt;
  while (carry_on)
     {
     int option_index = 0;
     opt = getopt_long (argc, argv, "hio:v", long_options, &option_index);

     if (opt == -1) break;

     switch (opt)
       {
       case 'h':
         help = TRUE;
         break;
       case 'i':
         improper = TRUE;
         break;
       case 'o':
         order = atoi (optarg); 
         break;
       case 'v':
         version = TRUE;
         break;
       default:
         carry_on = FALSE;
         ret = 1;
       }
     }

  if (help)
    {
    show_usage (argv[0], stdout);
    ret = 0; 
    carry_on = FALSE;
    }

  if (carry_on && version)
    {
    printf ("%s: VERSION %s\n", argv[0], VERSION);
    printf ("Copyright (c)2922 Kevin Boone, distributed under the terms of\n");
    printf ("The GNU Public Licence, v3.0\n");
    ret = 0; 
    carry_on = FALSE;
    }

  if (carry_on)
    {
    if (argc - optind == 1)
      {  
      double n;
      size_t len = 80;
      char *s_num = malloc (len + 1);
      strncpy (s_num, argv[optind], len);
      if (s_num[0] == '-')
        {
        getline (&s_num, &len, stdin);
        }

      if (sscanf (s_num, "%lf", &n) == 1)
	{
	int whole, numerator, denominator;
	BOOL negative;
	rationalize (n, order, improper, &whole, &numerator, 
	    &denominator, &negative);
	if (negative) printf ("-");
	if (whole > 0)
	  printf ("%d ", whole);
	printf ("%d/%d\n", numerator, denominator);
	}
      else
	{
	fprintf (stderr, "%s: Invalid number: %s\n", argv[0], s_num);
        ret = 1;
	}
      free (s_num);
      }  
    else
      {
      show_usage (argv[0], stderr);
      ret = 1;
      }
    }
  return ret;
  } 



