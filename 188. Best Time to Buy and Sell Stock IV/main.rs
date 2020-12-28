#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let k = (prices.len() / 2).min(k as usize);
        let mut buy = vec![i32::MIN; k + 1];
        let mut sell = vec![0; k + 1];
        for v in prices {
            for i in 1..=k {
                buy[i] = buy[i].max(sell[i - 1] - v);
                sell[i] = sell[i].max(buy[i] + v);
            }
        }
        sell[k]
    }
}

fn main() {}
