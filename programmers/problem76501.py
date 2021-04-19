# 월간 코드 챌린지 시즌2 - 음양 더하기

def solution(absolutes, signs):
    return sum([n if s else -n for n, s in zip(absolutes, signs)])


if __name__=="__main__":
    parameter1 = [4, 7, 12]
    parameter2 = [True, False, True]
    answer = 9
    print("Solution =", solution(parameter1, parameter2))
    print("Answer =", answer)