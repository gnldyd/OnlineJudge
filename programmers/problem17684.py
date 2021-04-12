# 2018 KAKAO BLIND RECRUITMENT - [3차] 압축

def basic_dictionary():
    dictionary = {}
    ascii_A = 65
    for c in range(ascii_A, ascii_A + 26):
        dictionary[chr(c)] = len(dictionary) + 1
    return dictionary


def solution(msg):
    dictionary = basic_dictionary()
    answer = []
    while len(msg) > 0:
        for length in range(len(msg), 0, -1):
            if msg[:length] in dictionary:
                break
        answer.append(dictionary[msg[:length]])
        dictionary[msg[:length + 1]] = len(dictionary) + 1
        msg = msg[length:]
    return answer


if __name__=="__main__":
    parameter = "TOBEORNOTTOBEORTOBEORNOT"
    answer = [20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34]
    print("Solution =", solution(parameter))
    print("Answer =", answer)