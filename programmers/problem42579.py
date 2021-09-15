# 해시 - 베스트앨범

from collections import defaultdict

def solution(genres, plays):
    clas = defaultdict(lambda: {})
    [clas[g].update({i: p}) for i, (g, p) in enumerate(zip(genres, plays))]
    clas = dict(sorted(clas.items(), reverse=True, key=lambda v: sum(v[1].values())))
    return [t[0] for g in clas for t in sorted(clas[g].items(), reverse=True, key=lambda s: s[1])[:2]]


if __name__=="__main__":
    parameter1 = ["classic", "pop", "classic", "classic", "pop"]
    parameter2 = [500, 600, 150, 800, 2500]
    answer = [4, 1, 3, 0]
    print("Solution =", solution(parameter1, parameter2))
    print("Answer =", answer)