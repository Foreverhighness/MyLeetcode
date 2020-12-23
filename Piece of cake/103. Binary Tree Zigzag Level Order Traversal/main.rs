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
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        if root.is_none() {
            return vec![];
        }
        let mut res = Vec::new();
        let mut que = VecDeque::new();
        que.push_back(root.unwrap());
        while !que.is_empty() {
            let mut v = Vec::new();
            for _ in 0..que.len() {
                let cur = que.pop_front().unwrap();
                v.push(cur.borrow().val);
                if let Some(left) = cur.borrow_mut().left.take() {
                    que.push_back(left);
                };
                if let Some(right) = cur.borrow_mut().right.take() {
                    que.push_back(right);
                };
            }
            res.push(v);
        }
        res.iter_mut()
            .skip(1)
            .step_by(2)
            .for_each(|row| row.reverse());
        res
    }
}

fn main() {}
