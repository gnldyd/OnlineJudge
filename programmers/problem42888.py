# 2019 KAKAO BLIND RECRUITMENT - 오픈채팅방

def solution(record):
    answer = []
    dic = {}
    for r in record:
        spl = r.split()
        if spl[0] != 'Leave':
            dic[spl[1]] = spl[2]
    for r in record:
        spl = r.split()
        if spl[0] == 'Enter':
            answer.append(dic[spl[1]] + '님이 들어왔습니다.')
        elif spl[0] == 'Leave':
            answer.append(dic[spl[1]] + '님이 나갔습니다.')
    return answer


if __name__=="__main__":
    parameter = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    answer = ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
    print("Solution =", solution(parameter))
    print("Answer =", answer)