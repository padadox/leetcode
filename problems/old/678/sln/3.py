class Solution(object):
# The idea is, we firstly treat * as left (, then we need to make sure the left ( is always more than or equal to ).
# We can use a stack to do this.
# Then similarly, we treat * as a right ), we go through s from right to left, to make sure the right ) is always
# more than or equal to (. If both experiments succeed, then return True.

# O(n) time, O(n) space
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # stack 1, try to test all the ( and * can balance all the )
        S=[]        
        # go through s from left to right
        for x in s:
            if x=='(' or x=='*':
                S.append(x)
            else:
                if len(S)>0:
                    S.pop()
                else:
                    return False        # this means left ( is not enough
        
        # stack 2, try to test all the ) and * can balance all the (
        S=[]        
        # go through s from right to left
        for x in s[::-1]:
            if x==')' or x=='*':
                S.append(x)
            else:
                if len(S)>0:
                    S.pop()
                else:
                    return False        # this means right ) is not enough
        
        return True
