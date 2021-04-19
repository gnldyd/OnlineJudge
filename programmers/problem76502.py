# 월간 코드 챌린지 시즌2 - 괄호 회전하기

def solution(s):
    bracket = ['(', ')', '[', ']', '{', '}']
    answer = 0
    for i in range(len(s)):
        letter = s[i:] + s[:i]
        stack = []
        for ch in letter:
            if bracket.index(ch) % 2 == 0:
                stack.append(ch)
            elif len(stack) > 0 and bracket.index(ch) % 2 == 1 and bracket.index(ch) - bracket.index(stack[-1]) == 1:
                stack.pop()
            else:
                break
        else:
            if len(stack) == 0:
                answer += 1
    return answer


if __name__=="__main__":
    parameter = "[](){}"
    answer = 3
    print("Solution =", solution(parameter))
    print("Answer =", answer)