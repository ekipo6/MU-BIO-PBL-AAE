#include "angularvelocitycalculator.h"
#include <math.h>
#include <stdio.h>

float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints)
{
    // If there are fewer than 2 points, print an error message and return 0.0f
    if (numberOfPoints < 2) {
        printf("Not enough points to calculate angular velocity.\n");
        return 0.0f;
    }

    float maxAngularVelocity = 0.0f;

    // Loop through the points starting from the second point
    for (int i = 1; i < numberOfPoints; i++) {
        // Calculate the change in theta and time between consecutive points
        double deltaTheta = points[i].theta - points[i - 1].theta;
        double deltaT = points[i].t - points[i - 1].t;

        // If the change in time is significant, calculate the angular velocity
        if (fabs(deltaT) > 1e-6) {
            float angularVelocity = fabs(deltaTheta / deltaT);
            // Update the maximum angular velocity if the current one is greater
            if (angularVelocity > maxAngularVelocity) {
                maxAngularVelocity = angularVelocity;
            }   
            else {
                // If the change in time is too small or zero, print a message and return the current max angular velocity
				printf("Skipped point %d due to small theeta \n", i);
                return maxAngularVelocity;
            }
        }
    }
    return maxAngularVelocity;
}

