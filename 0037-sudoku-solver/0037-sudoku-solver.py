def getBoxNum(r, c):
    if 0 <= r < 3 and 0 <= c < 3: return 1
    if 0 <= r < 3 and 3 <= c < 6: return 2
    if 0 <= r < 3 and 6 <= c < 9: return 3
    if 3 <= r < 6 and 0 <= c < 3: return 4
    if 3 <= r < 6 and 3 <= c < 6: return 5
    if 3 <= r < 6 and 6 <= c < 9: return 6
    if 6 <= r < 9 and 0 <= c < 3: return 7
    if 6 <= r < 9 and 3 <= c < 6: return 8
    if 6 <= r < 9 and 6 <= c < 9: return 9
    


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.board = board
        self.solve()
        
    def solve(self):
        row, col = self.getNext()

        if row == -1 and col == -1:
            return True
        
        for val in ["1","2","3","4","5","6","7","8","9"]:
            if self.isValid(row, col, val):
                self.board[row][col] = val
                
                if self.solve():
                    return True
                self.board[row][col] = "."
                
        return False
    
    def getNext(self):
        for row in range(9):
            for col in range(9):
                if self.board[row][col] == ".":
                    return row, col
        return -1, -1
    
    def isValid(self, row, col, val):
        if self.checkRow(row, val) and self.checkCol(col, val) and self.checkBox(row - row%3, col - col%3, val):
            return True
        return False
    
    def checkRow(self, row, val):
        for i in range(9):
            if self.board[row][i] == val:
                return False
        return True

    def checkCol(self, col, val):
        for i in range(9):
            if self.board[i][col] == val:
                return False
        return True
    
    def checkBox(self, row, col, val):
        for r in range(row, row+3):
            for c in range(col, col+3):
                if self.board[r][c] == val:
                    return False
        return True