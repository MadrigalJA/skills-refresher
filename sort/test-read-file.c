#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char const *argv[])
  {
    int **arrayAddress, *array, count;
    // set the pointer to the address of the pointer that contains the address of the int array
    arrayAddress = malloc(sizeof(int*));

    for (int i = 1; i < argc; i++)
      {
        count = ReadTestCSVFile(argv[i], arrayAddress);
        // set the array Pointer to the address of the initial index of the array
        array = *arrayAddress;

        printf("Start of file %s :\n", argv[i]);
        // display the array returned from the input file
        for (int j = 0; j < count; j++)
          {
            printf("%d: %d\n", j, array[j]);
          }

        printf("End of File\n\n");

        free(array);
      }

    free(arrayAddress);
    return 0;
  }
