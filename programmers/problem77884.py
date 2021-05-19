# 월간 코드 챌린지 시즌2 - 약수의 개수와 덧셈

def solution(left, right):
    answer = 0
    for n in range(left, right + 1):
        if int(n**0.5) == n**0.5:
            answer -= n
        else:
            answer += n
    return answer


if __name__=="__main__":
    parameter1 = 24
    parameter2 = 27
    answer = 52
    print("Solution =", solution(parameter1, parameter2))
    print("Answer =", answer)