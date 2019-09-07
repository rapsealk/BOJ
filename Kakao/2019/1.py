#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

"""
테스트 1 〉	통과 (0.08ms, 10.8MB)
테스트 2 〉	통과 (0.64ms, 10.8MB)
테스트 3 〉	통과 (0.34ms, 10.8MB)
테스트 4 〉	통과 (0.07ms, 10.8MB)
테스트 5 〉	통과 (0.04ms, 10.8MB)
테스트 6 〉	통과 (0.09ms, 10.8MB)
테스트 7 〉	통과 (0.76ms, 10.8MB)
테스트 8 〉	통과 (0.77ms, 10.7MB)
테스트 9 〉	통과 (1.18ms, 10.8MB)
테스트 10 〉	통과 (5.08ms, 10.7MB)
테스트 11 〉	통과 (0.18ms, 10.8MB)
테스트 12 〉	통과 (0.18ms, 10.9MB)
테스트 13 〉	통과 (0.21ms, 10.8MB)
테스트 14 〉	통과 (1.17ms, 10.8MB)
테스트 15 〉	통과 (0.21ms, 10.6MB)
테스트 16 〉	통과 (0.05ms, 10.8MB)
테스트 17 〉	통과 (2.19ms, 10.8MB)
테스트 18 〉	통과 (2.22ms, 10.9MB)
테스트 19 〉	통과 (2.21ms, 10.8MB)
테스트 20 〉	통과 (5.78ms, 10.7MB)
테스트 21 〉	통과 (5.80ms, 10.8MB)
테스트 22 〉	통과 (5.67ms, 10.7MB)
테스트 23 〉	통과 (5.55ms, 10.6MB)
테스트 24 〉	통과 (5.12ms, 10.8MB)
테스트 25 〉	통과 (5.75ms, 10.8MB)
테스트 26 〉	통과 (5.67ms, 10.6MB)
테스트 27 〉	통과 (5.66ms, 10.8MB)
테스트 28 〉	통과 (0.06ms, 10.8MB)
"""

import unittest

def tokenize(s, length):
    tokens = []
    while len(s) >= length:
        tokens.append(s[:length])
        s = s[length:]
    if s:
        tokens.append(s)
    return tokens

def compress(tokens):
    compressed = ''
    i = 0
    while i < len(tokens):
        token = tokens[i]
        count = 1
        for _token in tokens[i+1:]:
            if token == _token:
                count += 1
            else:
                break
        if count > 1:
            compressed += str(count)
        compressed += token
        i += count
    return compressed

def solution(s):
    answer = len(s)

    for i in range(len(s) // 2):
        tokens = tokenize(s, i+1)
        compressed = compress(tokens)

        if answer > len(compressed):
            answer = len(compressed)
            
    return answer

class SolutionTest(unittest.TestCase):

    def test_01(self):
        s = "aabbaccc"
        result = 7
        self.assertEqual(solution(s), result)

    def test_02(self):
        s = "ababcdcdababcdcd"
        result = 9
        self.assertEqual(solution(s), result)

    def test_03(self):
        s = "abcabcdede"
        result = 8
        self.assertEqual(solution(s), result)

    def test_04(self):
        s = "abcabcabcabcdededededede"
        result = 14
        self.assertEqual(solution(s), result)

    def test_05(self):
        s = "xababcdcdababcdcd"
        result = 17
        self.assertEqual(solution(s), result)

if __name__ == "__main__":
    unittest.main()