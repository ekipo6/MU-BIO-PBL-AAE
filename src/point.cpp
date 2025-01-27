#include "point.h"
#include <stdlib.h>

// Frees the memory allocated for points
void freePoints(point_t** const points) {
    // Check if the pointer to points and the points themselves are not null
    if (points && *points) {
        // Free the allocated memory
        free(*points);
        // Set the pointer to null to avoid dangling pointers
        *points = NULL;
    }
}


// Frees the memory allocated for points
