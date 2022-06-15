#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn smallest_distance_pair(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let n = nums.len();
        let (mut l, mut r) = (-1, nums[n - 1] - nums[0]);
        let check = |g: i32| {
            let (mut l, mut r, mut cnt) = (0, 1, 0);
            while cnt < k {
                while r < n && nums[r] - nums[l] <= g {
                    r += 1;
                }
                cnt += (r - l - 1) as i32;
                l += 1;
                if l == n {
                    break;
                }
                if l == r {
                    r += 1;
                }
            }
            cnt >= k
        };
        while r - l > 1 {
            let m = (l + r) / 2;
            if check(m) {
                r = m;
            } else {
                l = m;
            }
        }
        l + 1
    }
}

fn main() {
    dbg!(Solution::smallest_distance_pair(vec![1, 3, 1], 1), 0);
    dbg!(Solution::smallest_distance_pair(vec![1, 3, 1], 2), 2);
    dbg!(Solution::smallest_distance_pair(vec![1, 3, 1], 3), 2);
    dbg!(Solution::smallest_distance_pair(vec![1, 6, 1], 3), 5);
}
