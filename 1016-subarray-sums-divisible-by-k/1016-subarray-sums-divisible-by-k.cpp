class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainderCount;
    remainderCount[0] = 1;  // Initial count for subarrays directly divisible by k
    int prefixSum = 0;
    int result = 0;

    for (int num : nums) {
        prefixSum += num;
        int remainder = ((prefixSum % k) + k) % k;  // Handle negative remainders

        if (remainderCount.find(remainder) != remainderCount.end()) {
            result += remainderCount[remainder];
        }

        remainderCount[remainder]++;
    }

    return result;
}
};