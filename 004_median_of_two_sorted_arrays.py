# a wrong sol
#ref: sol3 of https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/8999/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        k = (m+n+1)//2
        last_1, last_2 = 0, 0

        is_on_1 = True
        while k >= 1:
            step = k//2
            if last_1 == m:
                last_2 += k-1
                is_on_1 = False
                break
            if last_2 == n:
                last_1 += k-1
                is_on_1 = True
                break
            if k == 1:
                if nums1[last_1] >= nums2[last_2]:
                    is_on_1 = False
                    break
                else:
                    is_on_1 = True
                    break
            if nums1[last_1 + step -1] >= nums2[last_2 + step -1]:
                last_2 += step
                is_on_1 = True
            else:
                last_1 += step
                is_on_1 = False
            k -= step
        if (m+n)%2 == 1:
            return nums1[last_1] if is_on_1 else nums2[last_2]
        if (m+n)%2 == 0:
            if last_1 == m:
                return (nums2[last_2] + nums2[last_2+1])/2
            if last_2 == n:
                return (nums1[last_1] + nums1[last_1+1])/2
            else:
                if is_on_1:
                    if last_1 == m-1:
                        return (nums1[last_1] + nums2[last_2])/2
                    return (nums1[last_1] + min(nums1[last_1+1], nums2[last_2]))/2
                else:
                    if last_2 == n-1:
                        return (nums1[last_1] + nums2[last_2])/2
                    return (nums2[last_2] + min(nums2[last_2+1], nums1[last_1]))/2
