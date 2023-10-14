# Problem NO : 2413
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        SmallestEvenNumber = 2
        if(n % SmallestEvenNumber == 0):
            return n
        return (SmallestEvenNumber * n)
        
