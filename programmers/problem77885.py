# 월간 코드 챌린지 시즌2 - 2개 이하로 다른 비트

# one line function
# def solution(numbers):
#     return [n + 2 ** (len(bin(n)[2:]) - bin(n)[2:].rfind('0') - 2) if bin(n)[-1] == '1' else n + 1 for n in numbers]

def solution(numbers):
    answer = []
    for number in numbers:
        binary = bin(number)
        if binary[-1] == '1':
            answer.append(number + 2 ** (len(binary[2:]) - binary[2:].rfind('0') - 2))
        else:
            answer.append(number + 1)
    return answer

if __name__=="__main__":
    parameter = [2, 7]
    answer = [3, 11]
    print("Solution =", solution(parameter))
    print("Answer =", answer)