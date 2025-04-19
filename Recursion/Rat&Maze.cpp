#include <iostream>
#include <vector>
#include <string>
#include<set>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    int n = maze.size();
    return (row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1 && !visited[row][col]);
}


void solve(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& paths) {
    int n = maze.size();

    if (row == n-1 && col == n-1) {
        //Solved
        paths.push_back(path);
        return;
    }

    visited[row][col] = true;

    //Move Down
    if (isSafe(row+1, col, maze, visited)) {
        solve(row+1, col, maze, visited, path + "D", paths);
    }

    //Move up
    if (isSafe(row-1, col, maze, visited)) {
        solve(row-1, col, maze, visited, path + "U", paths);
    }

    //Move Right
    if (isSafe(row, col+1, maze, visited)) {
        solve(row, col+1, maze, visited, path + "R", paths);
    }

    //Move Left
    if (isSafe(row, col-1, maze, visited)) {
        solve(row, col-1, maze, visited, path + "L", paths);
    }

    //Backtrack
    visited[row][col] = false;
}


vector<string> ratAndMaze(vector<vector<int>> &maze) {
    vector<string> all_paths;
    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));


    if (maze[0][0] == 1) {
        solve(0, 0, maze, visited, "", all_paths);
    }

    return all_paths;

}


int main() {
    vector<vector<int>> maze = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
    };

    auto all_paths = ratAndMaze(maze);
    for (auto path : all_paths) {
        cout << path << endl;
    }

}

