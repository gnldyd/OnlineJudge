# 그래프 - 가장 먼 노드

def solution(n, edge):
    path = [[] for i in range(n + 1)]
    for e in edge:
        path[e[0]].append(e[1])
        path[e[1]].append(e[0])
    size = 0
    visit = [0] * (n + 1)
    visit[1] = 1
    queue = [1]
    while len(queue) > 0:
        size = len(queue)
        for _ in range(size):
            start = queue[0]
            queue = queue[1:]
            for a in path[start]:
                if visit[a] == 0:
                    visit[a] = 1
                    queue.append(a)
    return size


if __name__=="__main__":
    parameter1 = 6
    parameter2 = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
    answer = 3
    print("Solution =", solution(parameter1, parameter2))
    print("Answer =", answer)