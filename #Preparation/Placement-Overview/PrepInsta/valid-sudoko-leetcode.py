board = [
      ["5","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
]

H = len(board)
W = len(board[0])

cache = []
tt = True
for row in range(H):
    for col in range(W):
        if tt and board[row][col] != '.':
            nrow = board[row][col] + str(row) 
            ncol = board[row][col] + str(col)
            box = board[row][col] + str(row//3) + str(col//3 * 11)
            if [nrow, ncol, box] in cache:
                tt = False
                break
            cache.append([nrow, ncol, box])

if tt:
    print('true')
else:
    print('false')