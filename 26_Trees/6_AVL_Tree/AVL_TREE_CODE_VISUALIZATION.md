
# AVL Tree Visualization

## Overview

An AVL tree is a self-balancing binary search tree (BST) where the height of the left and right subtrees of any node differ by at most one. If the difference becomes greater than one, the tree performs rotations to maintain balance.

## Operations in AVL Tree

1. **Insertion**: Inserting a node into an AVL tree is similar to inserting a node into a BST, but after insertion, the tree checks and maintains balance using rotations.

2. **Rotations**:
   - **Right Rotation** (`LL Rotation`): Used when the left subtree of a left child is causing the imbalance.
   - **Left Rotation** (`RR Rotation`): Used when the right subtree of a right child is causing the imbalance.
   - **Left-Right Rotation** (`LR Rotation`): Used when the right subtree of a left child is causing the imbalance.
   - **Right-Left Rotation** (`RL Rotation`): Used when the left subtree of a right child is causing the imbalance.

## Example Walkthrough with Visualization

Let's walk through the example with the array `{9, 5, 10, 0, 6, 11, -1, 1, 2}`.

### Step 1: Insert 9
- **Tree**: 
  ```
  9
  ```
- **Balance Factor**: 0

### Step 2: Insert 5
- **Tree**: 
  ```
    9
   /
  5
  ```
- **Balance Factor**: +1 (for node 9)

### Step 3: Insert 10
- **Tree**:
  ```
    9
   / \
  5   10
  ```
- **Balance Factor**: 0 (for node 9)

### Step 4: Insert 0
- **Tree**:
  ```
      9
     / \
    5   10
   /
  0
  ```
- **Balance Factor**: +2 (for node 9, causing imbalance)
- **Action**: Right rotation on node 9
- **New Tree**:
  ```
    5
   / \
  0   9
       \
       10
  ```

### Step 5: Insert 6
- **Tree**:
  ```
    5
   / \
  0   9
     / \
    6   10
  ```
- **Balance Factor**: +1 (for node 9)

### Step 6: Insert 11
- **Tree**:
  ```
    5
   / \
  0   9
     / \
    6   10
          \
          11
  ```
- **Balance Factor**: 0 (for node 9)

### Step 7: Insert -1
- **Tree**:
  ```
    5
   / \
  0   9
  /   / \
 -1  6   10
          \
          11
  ```
- **Balance Factor**: 0 (for node 0)

### Step 8: Insert 1
- **Tree**:
  ```
    5
   / \
  0   9
  / \ / \
 -1 1 6 10
          \
          11
  ```
- **Balance Factor**: -1 (for node 0)

### Step 9: Insert 2
- **Tree**:
  ```
        5
       / \
      0   9
     / \ / \
   -1  1 6 10
        \   \
        2   11
  ```
- **Balance Factor**: -2 (for node 0, causing imbalance)
- **Action**: Left-Right rotation on node 0
- **New Tree**:
  ```
        5
       / \
      1   9
     / \ / \
   -1  2 6 10
            \
            11
  ```

## Conclusion

By following these steps and visualizing the tree at each insertion, you'll better understand how an AVL tree maintains balance and ensures efficient operations.
