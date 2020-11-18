#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let len = gas.len() as i32;
        let (sum, (_, idx)) = gas.into_iter().zip(cost.into_iter()).enumerate().fold(
            (0, (i32::MAX, usize::MAX)),
            |(mut s, (mut m, mut mi)), (i, (v, c))| {
                s += v - c;
                if m > s {
                    m = s;
                    mi = i
                }
                (s, (m, mi))
            },
        );
        if sum < 0 {
            -1
        } else {
            (1 + idx as i32) % len
        }
    }
}

fn main() {}
