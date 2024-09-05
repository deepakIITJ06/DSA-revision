#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// pehle saare row me check krein ki wo value present to nahi ---> then saare column me if valid phir next box me jaye....
// if last column me pahuch jayenge tabhi row change krenge
// simply 1-9 loop chalakr check krein ki kaun sa valid hai kaun nahi --> if valid then board pe rkh dein wo value

class Solution {
public:
    vector<vector<char>> ans;
    bool check(int row,int col,char val,vector<vector<char>> &board) {
        for(int i=0;i<9;i++) {
            if(i!=row && board[i][col]==val) {
                return false;
            }
        }
        for(int j=0;j<9;j++) {
            if(j!=col && board[row][j]==val) {
                return false;
            }
        }
        int cornerX = (row/3)*3;
        int cornerY = (col/3)*3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(cornerX+i==row && cornerY+j==col) continue;
                if(board[cornerX+i][cornerY+j]==val) {
                    return false;
                }
            }
        }
        return true;

    }
    void rec(int row,int col,vector<vector<char>> &board) {
        if(row==9) {
            ans = board;
            return;
        }
        if(col==9) {
            return rec(row+1,0,board);
        }
        if(board[row][col]!='.') {
            return rec(row,col+1,board);
        }
        for(char i='1';i<='9';i++) {
            if(check(row,col,i,board)) {
                board[row][col] = i;
                rec(row,col+1,board);
                board[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        rec(0,0,board);
        board = ans;
        // for(auto &row: ans) {
        //     for(auto &el: row) {
        //         cout<<el<<" ";
        //     }
        //     cout<<endl;
        // }
    }
};