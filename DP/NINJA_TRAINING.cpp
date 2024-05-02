#include <bits/stdc++.h>
using namespace std;
// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points)
{
  // Create a 2D DP (Dynamic Programming) table to store the maximum points
  // dp[i][j] represents the maximum points at day i, considering the last activity as j
  // vector<vector<int>> dp(n, vector<int>(4, 0));

  vector<int> prev(4, 0);

  vector<int> curr(4, 0);
  // Initialize the DP table for the first day (day 0)
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++)
  {
    for (int last = 0; last < 4; last++)
    {
      curr[last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++)
      {
        if (task != last)
        {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (recursively calculated)
          int activity = points[day][task] + prev[task];
          // Update the maximum points for the current day and last activity
          curr[last] = max(curr[last], activity);
        }
      }
    }
    prev = curr;
  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return prev[3];
}

int main()
{
  // Define the points matrix
  vector<vector<int>> points = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
  int n = points.size(); // Get the number of days

  /*
   dp[n] = 0 | 1 | 2
   dp[0] = 3   3   2
   dp[1] = 8   8   8
   dp[2] = 17  17 16
  */
  // Call the ninjaTraining function to find the maximum points and print the result
  cout << ninjaTraining(n, points);
  return 0;
}
