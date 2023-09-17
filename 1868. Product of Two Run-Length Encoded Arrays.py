class Solution:
    def findRLEArray(self, encoded1: List[List[int]], encoded2: List[List[int]]) -> List[List[int]]:
        n1, n2 = len(encoded1), len(encoded2)
        array1, array2= [], []
        array3 = []
        encoded3 = []

        i1, i2 = 0, 0

        while i1 < n1 or i2<n2:
            if i1 < n1:
                array1.extend([encoded1[i1][0]]*encoded1[i1][1])
                i1 += 1
            if i2 < n2:
                array2.extend([encoded2[i2][0]]*encoded2[i2][1])
                i2 += 1

            a_min = min(len(array1), len(array2))
            for i in range(a_min):
                array3.append(array1[i]*array2[i])
            array1 = array1[a_min:]
            array2 = array2[a_min:]

            i = 0        
            while i < len(array3):
                j = i
                while j < len(array3) and array3[j] == array3[i]:
                    j += 1
                if encoded3 and array3[i] == encoded3[-1][0]:
                    encoded3[-1][1]+=(j-i)
                else:
                    encoded3.append([array3[i], j-i])
                i = j
            array3 = []

        return encoded3
        
            


            
            
        
