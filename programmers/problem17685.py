# 2018 KAKAO BLIND RECRUITMENT - [3차] 자동완성

def common_count(word1, word2):
    count = 0
    length1 = len(word1)
    length2 = len(word2)
    while count < length1 and count < length2:
        if word1[count] == word2[count]:
            count += 1
        else:
            break
    return count


def solution(words):
    answer = 0
    words.sort()
    for i in range(0, len(words)):
        pre_common = next_common if i > 0 else 0
        next_common = common_count(words[i], words[i + 1]) if i < len(words) - 1 else 0
        max_common = max(pre_common, next_common)
        answer += max_common if len(words[i]) == max_common else max_common + 1
    return answer


if __name__=="__main__":
    parameter = ["word", "war", "warrior", "world"]
    answer = 15
    print("Solution =", solution(parameter))
    print("Answer =", answer)