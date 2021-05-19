# 월간 코드 챌린지 시즌2 - 2개 이하로 다른 비트

def solution(numbers):
    answer = []
    for number in numbers:
        binary = bin(number)
        if binary[-1] == '1':
            binary = binary[2:]
            point = len(binary) - binary.rfind('0') - 2 # rfind() is none = -1
            answer.append(number + 2 ** point)
        else:
            answer.append(number + 1)
    return answer

if __name__=="__main__":
    parameter = [2, 7]
    answer = [3, 11]
    print("Solution =", solution(parameter))
    print("Answer =", answer)