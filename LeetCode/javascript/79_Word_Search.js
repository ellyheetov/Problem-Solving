/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {
    if(board.length === 0) return false;
    
    const height = board.length;
    const width = board[0].length;
    const direction = [[-1,0],[0,1],[1,0],[0,-1]];

    const isBoundary =(nx,ny) =>{
        return nx >= 0 && nx < height && ny >=0 && ny < width;
    }

    const go =(x,y,k) =>{
        if(board[x][y] != word[k]) return false;
        if(k === word.length -1) return true;

        board[x][y] = '*'; //visit
        for( const [dx,dy] of direction){
            let nx = x + dx;
            let ny = y + dy;
            if(isBoundary(nx,ny) && board[nx][ny] != '*'){
                if(go( nx,ny, k+1)) return true;
            }
        }
        board[x][y] = word[k]; //re
        return false;
    }
    for(let i =0;i< height; i++){
        for(let j =0;j< width; j++){
            if(go(i,j,0)) return true;
        }
    }
    return false;
};

let board =
    [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E']
    ]
word = "ABCB";
console.log(exist(board, word));
