# 이분탐색 - 입국심사

def solution(n, times):
    times.sort()
    answer = [1, n * times[-1]]
    while answer[0] <= answer[-1]:
        mid = sum(answer) // len(answer)
        k = sum(mid // time for time in times)
        if k >= n:
            answer[-1] = mid - 1
        else:
            answer[0] = mid + 1
    return answer[-1] + 1


if __name__=="__main__":
    parameter1 = 6
    parameter2 = [7, 10]
    answer = 28
    print("Solution =", solution(parameter1, parameter2))
    print("Answer =", answer)