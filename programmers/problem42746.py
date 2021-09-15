# 정렬 - 가장 큰 수

def solution(numbers):
    return str(int(''.join(reversed(sorted(map(str, numbers), key = lambda x: x * 3)))))


if __name__=="__main__":
    parameter = [3, 30, 34, 5, 9]
    answer = "9534330"
    print("Solution =", solution(parameter))
    print("Answer =", answer)