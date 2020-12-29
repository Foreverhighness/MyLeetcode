#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn min_patches(nums: Vec<i32>, n: i32) -> i32 {
        let (mut r, mut res) = (0, 0);
        for v in nums {
            if r >= n {
                return res;
            }
            while r < v - 1 {
                r = r.saturating_add(r + 1);
                res += 1;
                if r >= n {
                    return res;
                }
            }
            r = r.saturating_add(v);
        }
        while r < n {
            r = r.saturating_add(r + 1);
            res += 1;
        }
        res
    }
}

fn main() {
    assert_eq!(Solution::min_patches(vec![1, 3], 6), 1);
    assert_eq!(Solution::min_patches(vec![1, 5, 10], 20), 2);
    assert_eq!(Solution::min_patches(vec![1, 2, 2], 5), 0);
    assert_eq!(Solution::min_patches(vec![], 8), 4);
    assert_eq!(Solution::min_patches(vec![1,2,31,33],2147483647), 28);
    assert_eq!(Solution::min_patches(vec![1,7,21,31,34,37,40,43,49,87,90,92,93,98,99],12), 2);
    assert_eq!(
        Solution::min_patches(
            vec![1, 2, 2, 6, 34, 38, 41, 44, 47, 47, 56, 59, 62, 73, 77, 83, 87, 89, 94],
            20
        ),
        1
    );
}
