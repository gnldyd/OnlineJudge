# 월간 코드 챌린지 시즌2 - 110 옮기기

def solution(s):
    ooz = '110'
    ooo = '111'
    answer = []
    for n in s:
        oozi = n.find(ooz)
        count = 0
        stack = ''
        for i in range(len(n)):
            stack += n[i]
            if stack[-3:] == ooz:
                stack = stack[:-3]
                count += 1
        n = stack
        zi = n.rfind('0')
        oooi = n.find(ooo)
        if n.count('1') == len(n):
            n = ooz * count + n
        elif oooi >= 0:
            n = n[:oooi] + ooz * count + n[oooi:]
        elif zi >= 0:
            n = n[:zi+1] + ooz * count + n[zi+1:]
        else:
            n += ooz * count
        answer.append(n)
    return answer

if __name__=="__main__":
    parameter = ["1110", "100111100", "0111111010", "1011110","01110","101101111010"]
    answer = ["1101", "100110110", "0110110111", "1011011","01101","101101101101"]
    print("Solution =", solution(parameter))
    print("Answer =", answer)