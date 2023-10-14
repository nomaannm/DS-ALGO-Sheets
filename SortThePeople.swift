// Problem No : 2418
class Solution {
    func sortPeople(_ names: [String], _ heights: [Int]) -> [String] {
        Array(zip(names,heights)).sorted(by : {$0.1 > $1.1}).map{$0.0}
        
    }
}
