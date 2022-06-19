#![allow(dead_code)]
struct Solution;
// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;
impl Solution {
    pub fn find_frequent_tree_sum(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        fn dfs(
            node: &Option<Rc<RefCell<TreeNode>>>,
            cnt: &mut HashMap<i32, i32>,
            max: &mut i32,
        ) -> i32 {
            if let Some(node) = node {
                let mut sum = node.borrow().val;
                sum += dfs(&node.borrow().left, cnt, max);
                sum += dfs(&node.borrow().right, cnt, max);
                let entry = cnt.entry(sum).or_default();
                *entry += 1;
                *max = *max.max(entry);
                sum
            } else {
                0
            }
        }

        let mut cnt = HashMap::new();
        let mut max = 0;
        dfs(&root, &mut cnt, &mut max);
        cnt.into_iter()
            .filter(|&(_, v)| v == max)
            .map(|(k, _)| k)
            .collect()
    }
}

fn main() {}
