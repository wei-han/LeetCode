#a wrong answer
class Solution:
    def possiblyEquals(self, s1: str, s2: str) -> bool:

        def dfs(s1, s2, wc1, wc2):
            s1_len = len(s1)
            s2_len = len(s2)

            if (s1_len == 0 and wc1 == 0) and (s2_len == 0 and wc2 == 0):
                return True
            elif (s1_len == 0 and wc1==0) or (s2_len == 0 and wc2==0):
                return False
            if wc1*wc2 != 0:
                if wc1 > 0:
                    if s2[0].isalpha():
                        return dfs(s1, s2[1:], wc1-1, 0)
                    else:
                         for i in range(0, min(3, s2_len)):
                            if not s2[i].isdigit():
                                break
                            num = int(s2[:i+1])
                            min_num = min(num, wc1)
                            if dfs(s1, s2[i+1:], wc1-min_num, num-min_num):
                                return True
                if wc2>0:
                    s1, s2 = s2, s1
                    wc1, wc2 = wc2, wc1
                    if s2[0].isalpha():
                        return dfs(s1, s2[1:], wc1-1, 0)
                    else:
                         for i in range(0, min(3, s2_len)):
                            if not s2[i].isdigit():
                                break
                            num = int(s2[:i+1])
                            min_num = min(num, wc1)
                            if dfs(s1, s2[i+1:], wc1-min_num, num-min_num):
                                return True

            if s1[0].isalpha() and s2[0].isalpha() and wc1+wc2 == 0:
                if s1[0] == s2[0]:
                    return dfs(s1[1:], s2[1:], 0, 0)
                return False
            
            if s1_len > 0 and s1[0].isalpha():
                for i in range(0, min(3, s2_len)):
                    if not s2[i].isdigit():
                        break
                    num = int(s2[:i+1])
                    if dfs(s1[1:], s2[i+1:],0,num-1):
                        return True
            
            if s2_len > 0 and s2[0].isalpha():
                s1, s2 = s2, s1
                for i in range(0, min(3, s1_len)):
                    if not s2[i].isdigit():
                        break
                    num = int(s2[:i+1])
                    if dfs(s1[1:], s2[i+1:],0,num-1):
                        return True
            for i in range(0, min(3, s1_len)):
                if not s1[i].isdigit():
                    break
                for j in range(0, min(3, s2_len)):
                    if not s2[j].isdigit():
                        break
                    num1 = int(s1[:i+1])
                    num2 =int(s2[:j+1])
                    min_num = min(num1, num2)
                    if dfs((str(num1-min_num) if num1 >min_num else "") + s2[i+1:], (str(num2-min_num) if num2 >min_num else "") + s2[j+1:], num1-min_num, num2-min_num):
                        return True
            return False
        return dfs(s1, s2, 0, 0)
