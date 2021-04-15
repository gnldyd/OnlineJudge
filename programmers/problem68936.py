# 월간 코드 챌린지 시즌1 - 쿼드압축 후 개수 세기

def solution(arr):
    l = len(arr)
    if l == 1:
        return [sum(arr, []).count(0), sum(arr, []).count(1)]
    else:
        if sum(arr, []).count(0) == l ** 2:
            return [1, 0]
        elif sum(arr, []).count(1) == l ** 2:
            return [0, 1]
        else:
            answer = [0, 0]
            for i in range(4):
                sub = [arr[j][0 if i % 2 == 0 else l // 2:l // 2 if i % 2 == 0 else l] for j in range(0 if i < 2 else l // 2,l // 2 if i < 2 else l)]
                answer = [a + b for a, b in zip(answer, solution(sub))]
            return answer


if __name__=="__main__":
    parameter = [[1,1,1,1,1,1,1,1],[0,1,1,1,1,1,1,1],[0,0,0,0,1,1,1,1],[0,1,0,0,1,1,1,1],[0,0,0,0,0,0,1,1],[0,0,0,0,0,0,0,1],[0,0,0,0,1,0,0,1],[0,0,0,0,1,1,1,1]]
    answer = [10,15]
    print("Solution =", solution(parameter))
    print("Answer =", answer)