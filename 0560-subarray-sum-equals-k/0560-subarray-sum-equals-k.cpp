class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    std::unordered_map<int, int> sumCount;
    sumCount[0] = 1;  // Initialize with sum 0 to handle cases where subarray starts from index 0
    int currentSum = 0;
    int result = 0;

    for (int num : nums) {
        currentSum += num;
        // Check if there is a prefix subarray we can remove to get sum k
        if (sumCount.find(currentSum - k) != sumCount.end()) {
            result += sumCount[currentSum - k];
        }
        // Store the currentSum in the hash map
        sumCount[currentSum]++;
    }
    return result;
}
};