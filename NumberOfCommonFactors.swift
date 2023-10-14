/**
Problem NO : 2427
*/
class Solution {
    func commonFactors(_ a: Int, _ b: Int) -> Int {
        var countOfCommonFactors = 0 
        let smallerNumber = min(a,b) 

        for i in 1...smallerNumber{
            if a % i == 0 && b % i == 0{
                countOfCommonFactors += 1 ;
            }
        }

        return countOfCommonFactors ;


        
    }
}
