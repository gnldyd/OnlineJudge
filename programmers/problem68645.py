# 월간 코드 챌린지 시즌1 - 삼각달팽이

def solution(n):
    answer = [[0] * i for i in range(1, n + 1)]
    end = sum([i for i in range(1, n + 1)])
    pr = pc = r = c = t = 0
    answer[r][c] = i = 1
    i += 1
    while i <= end:
        if t == 0:
            pr = r
            r += 1
        elif t == 1:
            pc = c
            c += 1
        elif t == 2:
            pr = r
            pc = c
            r -= 1
            c -= 1
        if r >= n or c >= n or answer[r][c] > 0:
            r = pr
            c = pc
            t = (t + 1) % 3
            continue
        answer[r][c] = i
        i += 1
    return sum(answer, [])

if __name__=="__main__":
    parameter = 6
    answer = [1,2,15,3,16,14,4,17,21,13,5,18,19,20,12,6,7,8,9,10,11]
    print("Solution =", solution(parameter))
    print("Answer =", answer)