class Solution {
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && nums[l] > nums[largest])
            largest = l;

        if (r < n && nums[r] > nums[largest])
            largest = r;

        if (largest != i) {
            int temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;
            heapify(nums, n, largest);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
            heapify(nums, i, 0);
        }

        return nums;
    }
};