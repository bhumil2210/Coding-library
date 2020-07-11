from itertools import product, repeat
from random import choice


def main():
    T = int(input())  # the number of test cases

    for case in range(1, T+1):
        R, C = map(int, input().split())  # the numbers of rows and columns

        if R < 2 or C < 2 or R + C < 7:
            print('Case #{}: IMPOSSIBLE'.format(case))
        else:
            print('Case #{}: POSSIBLE'.format(case))

            while True:
                grid = [[False]*C for _ in repeat(None, R)]
                moves = []
                last = None
                for _ in repeat(None, R*C):
                    candidates = ([(r, c) for r, c in product(range(R), range(C)) if not grid[r][c]
                                   and r != last[0] and c != last[1] and last[0] - last[1] != r - c
                                   and last[0] + last[1] != r + c]
                                  if last is not None else list(product(range(R), range(C))))
                    if not candidates:
                        break
                    cell = choice(candidates)
                    moves.append(cell)
                    grid[cell[0]][cell[1]] = True
                    last = cell
                else:
                    print(len(moves))
                    for r, c in moves:
                        print(r+1, c+1)
                    break


main()
