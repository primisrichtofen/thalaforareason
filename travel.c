#include <stdio.h>
#include <limits.h>

#define V 4 // Number of cities

// DP table to store the minimum cost for visiting a subset of cities
int dp[1 << V][V];

// Function to find the minimum cost using dynamic programming
int tsp(int dist[V][V], int mask, int pos) {
    // If all cities have been visited, return the cost to return to the starting city
    if (mask == (1 << V) - 1) {
        return dist[pos][0];
    }

    // If this state has been already computed, return the stored result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < V; city++) {
        // Check if the city has already been visited in the current mask
        if ((mask & (1 << city)) == 0) {
            // Recurse for the next city with the updated mask
            int newAns = dist[pos][city] + tsp(dist, mask | (1 << city), city);
            ans = (ans < newAns) ? ans : newAns;
        }
    }

    // Store the result in dp table and return the answer
    dp[mask][pos] = ans;
    return ans;
}

int main() {
    // Distance matrix representing the graph (cities and distances between them)
    int dist[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Initialize the dp table with -1 (indicating not computed)
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

    // Call the TSP function starting from the first city (0) with only the first city visited
    int result = tsp(dist, 1, 0);

    printf("Minimum cost of visiting all cities: %d\n", result);
    return 0;
}
