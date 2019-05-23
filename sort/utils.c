#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

struct valuestack
  {
    int value;
    struct valuestack *previous;
  };

int ReadTestCSVFile(char const *filename, int **array)
  {
    FILE *file; // declare pointer to file stream
    int *temp, value, count = 0; // declare int variable to address to in fscanf call
    char comma; // declare char variable to address to in fscanf call

    struct valuestack *previousElement = 0, *currentElement = 0; // valuestack pointer to hold the address of the
    // printf("%d\n", sizeof(struct valuestack));
    file = fopen(filename, "r");
    while (fscanf(file, " %d %c", &value, &comma) != EOF)
      {
        ++count;
        currentElement = malloc(sizeof(struct valuestack));

        currentElement->value = value;
        currentElement->previous = previousElement;

        previousElement = currentElement;
      }

    temp = malloc(sizeof(int) * count);
    *array = temp;
    previousElement = 0;

    for (int i = count - 1; i >= 0; i--)
      {
        temp[i] = currentElement->value;
        previousElement = currentElement->previous;

        free(currentElement);
        currentElement = previousElement;
      }

    fclose(file);
    return count;
  }
