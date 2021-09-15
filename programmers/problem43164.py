# 깊이/너비 우선 탐색(DFS/BFS) - 여행경로

def solution(tickets):
    adj = {}
    for start, end in tickets:
        if start in adj:
            adj[start] = sorted(adj[start] + [end], reverse=True)
        else:
            adj[start] = [end]
    stack = ['ICN']
    answer = []
    while len(stack) > 0:
        start = stack[-1]
        if start not in adj or len(adj[start]) == 0:
            answer.append(stack.pop())
        else:
            stack.append(adj[start].pop())
    answer.reverse()
    return answer


if __name__=="__main__":
    parameter = [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]
    answer = ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
    print("Solution =", solution(parameter))
    print("Answer =", answer)