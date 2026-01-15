'''

102. Binary Tree Level Order Traversal


Given the root of a binary tree, 
return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


'''

from collections import deque;

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        
        # Handle Empty tree condition
        if not root:
            return []
        
        res = []
        queue = deque([root])
        while len(queue)>0 :
            level = []
            n = len(queue);
            
            for _ in range(n):
                
                node = queue.popleft();
                if node is not None:
                    level.append(node.val);
                
                for child in [node.left, node.right]:
                    if child is not None:
                        queue.append(child)
            
            res.append(level)
        
        return res
                