#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        prices.windows(2).map(|x| 0.max(x[1] - x[0])).sum()
    }
    pub fn max_profit_dp(prices: Vec<i32>) -> i32 {
        let (mut a, mut b) = (-prices[0], 0);
        for v in prices.into_iter().skip(1) {
            let (c, d) = (a.max(b - v), b.max(a + v));
            a = c;
            b = d;
        }
        b
    }
}

fn main() {}
