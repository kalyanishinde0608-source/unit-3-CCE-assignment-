Database Index Maintenance Application Using a Binary Search Tree (BST)
1. Aim
To develop a Database Index Maintenance Application that identifies unbalanced nodes in a Binary Search Tree (BST) and applies rotations to restore balance.

2. Objectives
Create a BST to store database index keys.

Identify unbalanced nodes using the balance factor.

Apply left and right rotations to restore balance.

Maintain the BST property after rotations.

Improve searching efficiency by reducing tree height.

3. Theory
A Binary Search Tree is a data structure in which smaller keys are stored in the left subtree and larger keys in the right subtree.

An unbalanced BST may become skewed, increasing the time required for searching. The balance factor is calculated as:

Balance Factor = Height of Left Subtree − Height of Right Subtree

A node is considered unbalanced when its balance factor is greater than 1 or less than −1.

Four rotation cases are used to restore balance:

LL (Left-Left): Right rotation.

RR (Right-Right): Left rotation.

LR (Left-Right): Left rotation followed by right rotation.

RL (Right-Left): Right rotation followed by left rotation.

4. Algorithm
Create a BST by inserting database index keys.

Calculate the height and balance factor of each node.

Identify nodes whose balance factor is outside the range −1 to +1.

Determine the appropriate rotation for each unbalanced node.

Apply the required single or double rotation.

Update node heights and links.

Display the balanced tree and verify the inorder traversal.

Terminate the application.

5. Applications
Database index organization.

Efficient record searching.

Maintaining balanced search trees.

Educational demonstrations of tree rotations and data structures.

6. Result
The Database Index Maintenance Application identifies unbalanced nodes in a BST and restores balance using appropriate rotations while preserving the ordering of keys.

7. Conclusion
The project demonstrates how tree rotations can maintain a balanced search structure and improve search efficiency. It provides a basic understanding of database indexing and balanced binary search trees.


