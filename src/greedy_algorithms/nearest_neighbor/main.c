#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

// Point structure representing a 3D coordinate with a unique ID and visitation state
typedef struct
{
    double x;
    double y;
    double z;
    int id;
    bool visited;
} Point;

// Test dataset of 10 3D points used as input for the nearest-neighbour traversal
Point testData[10] = {
    { 0.0,     0.0,     0.0,    1,  false }, // p1: Origin
    { 3.5,     7.2,     4.1,    2,  false }, // p2
    { -1.8,    4.6,    -2.2,    3,  false }, // p3
    { 9.1,    -3.3,     8.8,    4,  false }, // p4
    { -5.0,   -5.0,    -5.0,    5,  false }, // p5
    { 100.0,   200.0,   300.0,  6,  false }, // p6
    { -99.99,  -0.01,   50.5,   7,  false }, // p7
    { 0.001,   0.002,   0.003,  8,  false }, // p8
    { 1.0,     1.0,     1.0,    9,  false }, // p9
    { -123.45, 678.9,  -456.7,  10, false }  // p10
};

// Number of points in the dataset, computed at compile time
#define data_length sizeof(testData)/sizeof(testData[0])

// Calculates the Euclidean distance between two 3D points
double distance_calc(const Point *a, const Point *b)
{
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main()
{
    // visited_count starts at 1 because the origin is marked visited before the loop
    size_t visited_count = 1;

    // Index into testData for the starting point (p8)
    int origin_index = 7;
    testData[origin_index].visited = true;

    // current_index tracks which point we are travelling from on each iteration
    int current_index = origin_index;

    double total_distance = 0.0;

    // Stores the sequence of point IDs visited; size 11 to include the return to origin
    int shortest_path[11];
    shortest_path[0] = testData[origin_index].id;

    // Greedy nearest-neighbour loop: runs until every point has been visited
    while (visited_count < data_length)
    {
        // Reset closest candidate and minimum distance for this iteration
        int closest_index = -1;
        double min_distance = DBL_MAX;

        // Scan all points to find the nearest unvisited one from current position
        for (size_t i = 0; i < data_length; i++)
        {
            // Skip points that have already been visited
            if (testData[i].visited == true)
            {
                continue;
            }

            double calculated_distance = distance_calc(&testData[current_index], &testData[i]);

            // Update closest candidate if this point is nearer than the current best
            if (calculated_distance < min_distance)
            {
                min_distance = calculated_distance;
                closest_index = i;
            }
        }

        // Record the chosen point, accumulate distance, and advance current position
        shortest_path[visited_count] = testData[closest_index].id;
        total_distance += min_distance;
        current_index = closest_index;
        testData[closest_index].visited = true;
        visited_count++;
    }

    // Calculate the return leg distance from the last visited point back to the origin
    double shame_walk = distance_calc(&testData[current_index], &testData[origin_index]);
    total_distance += shame_walk;

    // Close the tour by appending the origin ID at the end of the path array
    shortest_path[visited_count] = testData[origin_index].id;

    // Print the full traversal path from origin, through all points, and back home
    printf("Path: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d -> ", shortest_path[i]);
    }
    printf("%d -> Home\n", shortest_path[10]);
    printf("Total distance: %lf\n", total_distance);

    return 0;
}