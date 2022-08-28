#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn preimage_size_fzf(k: i32) -> i32 {
        let k = k as i64;
        fn f(mut x: i64) -> i64 {
            let mut res = 0;
            while x >= 5 {
                x /= 5;
                res += x;
            }
            res
        }
        let (mut l, mut r) = (0, 1_000_000_000_0);
        while r - l > 1 {
            let m = (l + r) / 2;
            let kk = f(m);
            if kk == k {
                return 5;
            } else if kk < k {
                l = m;
            } else {
                r = m;
            }
        }
        0
    }
}

fn main() {
    assert_eq!(Solution::preimage_size_fzf(0), 5);
    assert_eq!(Solution::preimage_size_fzf(3), 5);
    assert_eq!(Solution::preimage_size_fzf(5), 0);
    assert_eq!(Solution::preimage_size_fzf(1_000_000_000), 5);
}