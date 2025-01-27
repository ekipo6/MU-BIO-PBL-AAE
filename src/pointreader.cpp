#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pointreader.h"

int read_csv_header(FILE* file) {
    char header[256];
    if (fgets(header, sizeof(header), file)) {
        // Validate the header here (e.g., check column names)
        return 0; // Validation successful
    }
    return -1; // Validation failed
}

// Parses a CSV row
int parse_csv_row(const char* row, point_t* point) {
    int parsed = sscanf(row, "%lf, %lf, %lf, %lf, %lf, %lf, %lf",
        &point->t, &point->x, &point->y,
        &point->v, &point->vx, &point->vy,
        &point->theta);
    if (parsed != 7) {
        printf("Error parsing row: %s\n", row);
        return -1; // Parsing error
    }
    return 0; // Parsing successful
}

// Extracts X and Y coordinates
void extract_coordinates(const point_t* point, double* x, double* y) {
    *x = point->x;
    *y = point->y;
}

// Reads points from a CSV file
int readPoints(const char* file, point_t** points) {
    FILE* fp = fopen(file, "r");
    if (!fp) {
        // If opening the file fails, print an error message and return -1
        printf("Failed to open file: %s\n", file);
        return -1; // File could not be opened
    }
    printf("File opened: %s\n", file);

    // Read and validate the CSV header
    if (read_csv_header(fp) != 0) {
        fclose(fp);
        printf("Failed to read CSV header\n");
        return -1;
    }

    // Define initial capacity
    size_t capacity = 350; // Initial capacity
    *points = (point_t*)malloc(capacity * sizeof(point_t));
    if (!*points) {
        // If memory allocation fails, close the file and print an error message
        fclose(fp);
        printf("Memory allocation failed\n");
        return -1; // Memory allocation failed
    }
    printf("Memory allocated\n");

    int count = 0;
    char line[256];
    // Read lines from the file
    while (fgets(line, sizeof(line), fp)) {
        // Parse each line and store the points
        if (parse_csv_row(line, &(*points)[count]) == 0) {
            count++;
            // If the maximum capacity is exceeded, stop reading
            if (count >= capacity) {
                break; // Stop reading if capacity is exceeded
            }
        }
        else {
            printf("Error reading line: %s\n", line);
        }
    }

    // If reading points fails, print an error message
    if (count == 0) {
        printf("Failed to read points from file\n");
    }

    // Close the file
    fclose(fp);
    return count; // Return the number of points read
}
