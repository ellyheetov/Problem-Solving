#include <iostream>
#include <vector>
#define VISIT 0
using namespace std;

vector<vector<int>> board;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_boundary(int row, int col){
    return row >= 0 && col >=0 && col<board[0].size() && row<board.size();
}

void dfs(int x,int y){
    board[x][y] = VISIT;

    for(int i = 0; i<  4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(is_boundary(nx,ny) && board[nx][ny]!= VISIT)
            dfs(nx,ny);
    }
}

int main(){
    int test_case;
    int max_row, max_col;
    int meal;

    cin >> test_case;
    for(int test = 0; test < test_case; test++) {

        int count = 0;

        cin >> max_row >> max_col;
        cin >> meal;

        board.resize(max_row);
        for (int i = 0; i < max_row; i++) {
            board[i].resize(max_col, 0);
        }
        for (int i = 0; i < meal; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        for (int row = 0; row < max_row; row++) {
            for (int col = 0; col < max_col; col++) {
                if (board[row][col] == VISIT) continue;
                dfs(row, col);
                count++;
            }
        }
        cout << count << "\n";
    }
}