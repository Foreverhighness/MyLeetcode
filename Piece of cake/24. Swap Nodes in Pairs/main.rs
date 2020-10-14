#![allow(dead_code)]
// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}
impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut remain = head;
        let mut dummy = ListNode::new(-1);
        let mut prev = &mut dummy.next;
        while let Some(mut left) = remain.take() {
            if let Some(mut right) = left.next.take() {
                remain = right.next.replace(left); // remain = right.next.take(); right.next = Some(left);
                prev.replace(right);
                prev = &mut prev.as_mut().unwrap().next.as_mut().unwrap().next;
                // prev.replace(right);
                // prev = &mut prev.as_mut().unwrap().next;
                // remain = prev.replace(left);
                // prev = &mut prev.as_mut().unwrap().next;
            } else {
                prev.replace(left);
            }
        }
        dummy.next
    }
}

fn main() {
    
}
struct Solution;