#include<iostream>
#include <vector>
using namespace std;


bool isSafe(int row,int col,vector<vector<int>> &mat,int val)
    {
        for(int i=0;i<9;i++)
        {
            if(mat[row][i]==val || mat[i][col]==val)
                return false;
            if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==val)
                return false;
        }
        return true;
    }
  
    bool solve(vector<vector<int>> &mat)
    {
        int n=9;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                // yaha tak traverse kar rahe the matrix ko
                // kya cell khali hai
                if(mat[row][col]==0)
                {
                    // trying all possible values
                    for(int val=1;val<=9;val++)
                    {
                        // safety check
                        if(isSafe(row,col,mat,val))
                        {
                            mat[row][col]=val;
                            
                            // recursive call
                            bool poss=solve(mat);
                            
                            if(poss)
                                return true;
                            else
                                mat[row][col]=0; // backtrack
                        }
                    }
                    // agar solution mila to thik nhi to false;
                    return false;
                }
                
            }
        }
        // means solution mil gya
        return true;
    }
  
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
