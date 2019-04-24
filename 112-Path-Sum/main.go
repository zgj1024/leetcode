package main
type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func hasPathSum(root *TreeNode, sum int) bool {
    if root == null {
        return false
    }

    if root.Val == sum && root.Left == nil && root.Right == nil {
        return true
    }
    val:=sum-root.Val
    return hasPathSum(root.Left,val) || hasPathSum(root.Right,val);
}
