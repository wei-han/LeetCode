#a wrong answer, should try the largest number on the highest pos
class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        res_len = n*2-1
        res = []
        max_res = 0

        def dfs(n, path):
            if n == 1:
                for i in range(res_len):
                    if path[i] == 0:
                        path[i] = 1
                        res = path
                        return True
                return False
            
            for i in range(res_len):
                if i + n < res_len and path[i] ==0 and path[i+n] == 0:
                    path[i] = n
                    path[i+n] = n
                    if dfs(n-1, path):
                        return True
                    path[i] = 0
                    path[i+n] = 0
            return False
        dfs(n, [0]*(res_len))
        return res
