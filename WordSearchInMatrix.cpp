#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(vector<vector<char>>& board, int row, int col, string& word, int index, vector<vector<bool>>& visited) {
        if (index == word.length()) {
            return true;
        }
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || 
            board[row][col] != word[index] || visited[row][col]) {
            return false;
        }
        
        visited[row][col] = true;
        
        // Explore all four directions: up, down, left, right
        bool found = solve(board, row - 1, col, word, index + 1, visited) || // Up
                     solve(board, row + 1, col, word, index + 1, visited) || // Down
                     solve(board, row, col - 1, word, index + 1, visited) || // Left
                     solve(board, row, col + 1, word, index + 1, visited);   // Right
        
        // Backtrack
        visited[row][col] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, i, j, word, 0, visited)) { // Start with index 0
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
