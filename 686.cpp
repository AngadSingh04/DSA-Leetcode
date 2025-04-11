class Solution(object):
    def repeatedStringMatch(self, a, b):
        count = 1
        lengthl = a
        while len(lengthl) < len(b):
            lengthl = lengthl+a
            count += 1

        if b in lengthl:
            return count 

        lengthl += a
        count+=1
        if b in lengthl:
            return count
            
        return -1
        