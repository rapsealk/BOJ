#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

"""
"""

import unittest

def rotate_in_clockwise_90(matrix):
    """
    rotate_in_clockwist_90(matrix) -> list

    matrix: NxN 2d-array of integer
    
    [[0, 1, 2],       [[6, 3, 0],
     [3, 4, 5],  -->   [7, 4, 1],
     [6, 7, 8]]        [8, 5, 2]]
    
    [[0,0], [0,1], [0,2],       [[2,0], [1,0], [0,0],
     [1,0], [1,1], [1,2],  -->   [2,1], [1,1], [0,1],
     [2,0], [2,1], [2,2]]        [2,2], [1,2], [0,2]]
    """
    
    N = len(matrix)
    rmatrix = [[] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            rmatrix[N-j][i] = matrix[i][j]
    return rmatrix

def unlock(key, lock):
    """
    unlock(key, lock) -> bool
    """
    N = len(lock)
    board_shape = 3 * N - 2
    board = [[0 for _ in range(board_shape)] for _ in range(board_shape)]

    

    return False

def solution(key, lock):
    for _ in range(4):
        key = rotate_in_clockwise_90(key)
        if unlock(key, lock):
            return True
    return False

class SolutionTest(unittest.TestCase):

    def test_01(self):
        key = [[0, 0, 0],
               [1, 0, 0],
               [0, 1, 1]]
        lock = [[1, 1, 1],
                [1, 1, 0],
                [1, 0, 1]]
        result = True
        self.assertEqual(solution(key, lock), result)

if __name__ == "__main__":
    unittest.main()