#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let (mut res, mut inc, mut dec, mut prv) = (1, 1, 0, 1);
        for i in 1..ratings.len() {
            if ratings[i - 1] <= ratings[i] {
                dec = 0;
                prv = if ratings[i - 1] == ratings[i] {
                    1
                } else {
                    prv + 1
                };
                res += prv;
                inc = prv
            } else {
                dec += 1;
                if dec == inc {
                    dec += 1
                }
                res += dec;
                prv = 1;
            }
        }
        res
    }
}

fn main() {
    dbg!(Solution::candy(vec![1, 0, 2]));
    dbg!(Solution::candy(vec![1, 2, 2]));
}
