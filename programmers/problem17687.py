# 2018 KAKAO BLIND RECRUITMENT - [3차] n진수 게임

def trans_dictionary(base = 16):
    dictionary = {}
    for i in range(base):
        dictionary[i] = chr(48 + i) if i < 10 else chr(55 + i)
    return dictionary


def num2base(number, base, dictionary):
    result = '' if number > 0 else '0'
    while number > 0:
        result = str(dictionary[number % base]) + result
        number //= base
    return result


def solution(n, t, m, p):
    answer = ''
    dictionary = trans_dictionary(n)
    number = 0
    while len(answer) < m * t:
        answer += num2base(number, n, dictionary)
        number += 1
    return answer[p - 1:m * t:m]


if __name__=="__main__":
    parameter1 = 16
    parameter2 = 16
    parameter3 = 2
    parameter4 = 2
    answer = "13579BDF01234567"
    print("Solution =", solution(parameter1, parameter2, parameter3, parameter4))
    print("Answer =", answer)