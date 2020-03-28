#!/usr/local/bin/python3
# -*- coding: utf-8 -*-
import sys

N = int(sys.stdin.readline().replace('\n', ''))
A = list(map(lambda x: int(x), sys.stdin.readline().replace('\n', '').split(' ')))
B = list(map(lambda x: int(x), sys.stdin.readline().replace('\n', '').split(' ')))

A.sort()
B.sort(reverse=True)

result = 0
for a, b in zip(A, B):
    result += a * b
    
sys.stdout.write(str(result) + '\n')