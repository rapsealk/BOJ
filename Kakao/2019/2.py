#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

"""
테스트 1 〉	통과 (0.04ms, 10.9MB)
테스트 2 〉	통과 (0.04ms, 10.8MB)
테스트 3 〉	통과 (0.04ms, 10.9MB)
테스트 4 〉	통과 (0.06ms, 10.8MB)
테스트 5 〉	통과 (0.04ms, 10.8MB)
테스트 6 〉	통과 (0.05ms, 10.9MB)
테스트 7 〉	통과 (0.05ms, 10.6MB)
테스트 8 〉	통과 (0.04ms, 10.7MB)
테스트 9 〉	통과 (0.06ms, 10.8MB)
테스트 10 〉	통과 (0.06ms, 10.8MB)
테스트 11 〉	통과 (0.07ms, 10.8MB)
테스트 12 〉	통과 (0.07ms, 10.7MB)
테스트 13 〉	통과 (0.10ms, 10.7MB)
테스트 14 〉	통과 (0.14ms, 10.8MB)
테스트 15 〉	통과 (0.17ms, 10.5MB)
테스트 16 〉	통과 (0.27ms, 10.9MB)
테스트 17 〉	통과 (0.30ms, 10.7MB)
테스트 18 〉	통과 (0.49ms, 10.8MB)
테스트 19 〉	통과 (0.47ms, 10.7MB)
테스트 20 〉	통과 (0.47ms, 10.8MB)
테스트 21 〉	통과 (0.41ms, 10.7MB)
테스트 22 〉	통과 (0.21ms, 10.7MB)
테스트 23 〉	통과 (0.38ms, 10.8MB)
테스트 24 〉	통과 (0.15ms, 10.8MB)
테스트 25 〉	통과 (0.41ms, 10.7MB)
"""

import unittest

def parse_balanced_parenthesis_string(w):
    lstack, rstack = [], []
    for i, parenthesis in enumerate(w):
        if parenthesis == '(':
            lstack.append(parenthesis)
        else:
            #stack.pop()
            rstack.append(parenthesis)
        #if len(stack) == 0:
        if len(lstack) == len(rstack):
            u = w[:i+1]
            v = w[i+1:]
            return u, v

def parse_correct_parenthesis_string(w):
    return ''

def is_balanced_parenthesis_string(w):
    lstack, rstack = [], []
    for parenthesis in w:
        if parenthesis == '(':
            lstack.append(parenthesis)
        else:
            rstack.append(parenthesis)
    return len(lstack) == len(rstack)

def is_correct_parenthesis_string(w):
    stack = []
    for parenthesis in w:
        if parenthesis == '(':
            stack.append(parenthesis)
        else:
            try:
                stack.pop()
            except IndexError:
                return False
    return len(stack) == 0

def solution(p):
    """
    균형잡힌 괄호 문자열: (()))(
    올바른 괄호 문자열: (())()
    """
    # 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if not p:
        return ''
    elif is_correct_parenthesis_string(p):
        return p
    # 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
    u, v = parse_balanced_parenthesis_string(p)
    #print('p:', p)
    #print('u: %s, v: %s' % (u, v))
    # 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    if is_correct_parenthesis_string(u):
        # 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        u += solution(v)
        #_u, v = parse_balanced_parenthesis_string(v)
        #u += _u
        answer = u
    # 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    else:
        # 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
        answer = '('
        # 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
        answer += solution(v)
        # 4-3. ')'를 다시 붙입니다.
        answer += ')'
        # 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        answer += ''.join(['(' if p == ')' else ')' for p in u[1:-1]])
    # 4-5. 생성된 문자열을 반환합니다.
    #answer = ''
    return answer

class SolutionTest(unittest.TestCase):

    def test_01(self):
        p = "(()())()"
        result = "(()())()"
        self.assertEqual(solution(p), result)

    def test_02(self):
        p = ")("
        result = "()"
        self.assertEqual(solution(p), result)

    def test_03(self):
        p = "()))((()"
        result = "()(())()"
        self.assertEqual(solution(p), result)

if __name__ == "__main__":
    unittest.main()
    #p = input('p: ')
    #result = input('result: ')
    #s = solution(p)
    #print('solution == result:', s == result)