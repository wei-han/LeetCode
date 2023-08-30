#a wrong solution
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        res = []
        def remove(s, last_i, last_pos, left, right, reverse):
            n = len(s)
            stack = 0
            for i in range(last_i, n):
                if s[i] == left:
                    stack += 1
                elif s[i] == right:
                    stack -= 1
                
                if stack >= 0:
                    continue
                else:
                    for j in range(last_pos, i+1):
                        if s[j] == right and (j == last_pos or s[j-1] != right):
                            remove(s[:j] + s[j+1:], i, j, left, right, reverse)
                return
            
            if reverse:
                res.append(s[::-1])
            else:
                res.append(s)
        remove(s, 0, 0,'(', ')', False)
        remove(s[::-1], 0, 0, ')', '(', True)
        return res
