#![allow(dead_code)]
struct Solution;
fn merge(arr: &mut Vec<i32>, tmp: &mut Vec<i32>, l: usize, m: usize, r: usize) -> i32 {
    let mut res = 0;
    let (mut i, mut j) = (l, m);
    while i < m && j < r {
        if arr[i] as i64 <= 2 * arr[j] as i64 {
            i += 1;
        } else {
            res += m - i;
            j += 1;
        }
    }
    let (mut i, mut j, mut k) = (l, m, l);
    while i < m && j < r {
        if arr[i] < arr[j] {
            tmp[k] = arr[i];
            i += 1;
        } else {
            tmp[k] = arr[j];
            j += 1;
        }
        k += 1;
    }
    let mut t = if i < m { i } else { j };
    while k < r {
        tmp[k] = arr[t];
        t += 1;
        k += 1;
    }
    for i in l..r {
        arr[i] = tmp[i];
    }
    res as i32
}
fn merge_sort(arr: &mut Vec<i32>, tmp: &mut Vec<i32>, l: usize, r: usize) -> i32 {
    if r - l <= 1 {
        return 0;
    }
    let (mut res, m) = (0, (l + r) / 2);
    res += merge_sort(arr, tmp, l, m);
    res += merge_sort(arr, tmp, m, r);
    res += merge(arr, tmp, l, m, r);
    res
}
impl Solution {
    pub fn reverse_pairs(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        merge_sort(&mut nums, &mut vec![0; n], 0, n)
    }
}

fn main() {}
