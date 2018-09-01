* Arrays.binarySearch
    *  搜索值不是数组元素，且在数组大小范围内，从0开始计数，得“ - 插入点索引值 -1”；
    * 搜索值是数组元素，从0开始计数，得搜索值的索引值；
    * 搜索值不是数组元素，且大于数组内元素，索引值为 – (length + 1)，其实也是 - 插入点索引值 -1，只不过在此插入点索引值为length;
    *  搜索值不是数组元素，且小于数组内元素，索引值为 – 1( - 0 -1=-1)。
* https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation.