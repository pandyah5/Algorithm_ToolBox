# ECE345 - Intro. to ALgorithms
This is a repository to track my progress in ECE 345 - Introduction to algorithms @ UofT. These include naive/intuitive algorithms as well as improved and fast versions of them.

# Notes

### Week 1 - Time Complexity Analysis

- 2D Peak problem: To find a peak in an array the brute force solution takes O(n) time
- The smart approach is to use divide and conquer, which uses the following approach:
    - We start at the middle and check if there is a peak
    - If yes, we stop, if not, we go toward the rising edge and drop the rest
    - This is done recursively and hence, the runtime complexity is O (log n)
- Asymptotic notation
    - f(n) = O (g(n)) implies, f(n) < c g(n) for some c and n > n0
    - f(n) = Omega (g(n)) implies, f(n) > c g(n) for some c and n > n0
    - f(n) = Theta (g(n)) implies, f(n) > c g(n) and f(n) < c g(n) for some c and n > n0
    - O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)
    - To compare new expressions try taking log both sides and it usually becomes simple
- Master's Theorem: T(n) = a T(n/b) + f(n)
    - T(n) = Theta(n^log_b(a)): If f(n) = O(n^log_b(a) - epsilon, where epsilon > 0
    - T(n) = Theta(n^log_b(a) * log(n)): If f(n) = Theta (n^log_b(a)), where epsilon > 0
    - T(n) = Theta(f(n)): If f(n) = Omega (n^log_b(a) + epsilon) AND a f(n/b) < c f(n), where epsilon > 0 and c < 1
---

### Week 2 - Sorting Algorithms
- The sorting table for a quick summary is in Appendix 1.0
- Insertion Sort: This is like sorting cards.
    - This is an in-place algorithm
    - Best case complexity is in O(n): The array is sorted
    - Average case complexity is in O(n^2)
    - Worst case complexity is in O(n^2): The array is in descending order
- Merge sort: This is a divide and conquer algorithm similar to dividing the deck of cards into subdecks
    - The implementation in class requires auxiliary space in O(n) but an in-place variant exists! [Appendix 2.0]
    - Best case time complexity is in O(n*log(n))
    - Avg case time complexity is in O(n*log(n))
    - Worst case time is in O(n*log(n))
- Heap
    - Heap is a complete binary tree: All levels are completely filled except possibly the last level and the last level has all keys as left as possible
    - In a max heap the root is the largest element and nodes at a particular level have values greater than those present at larger depths.
    - Parent: i, Left-child: floor(2i), Right-child: floor(2i + 1)
- Heapsort: It uses Heapify and buildheap to sort the array [Assuming Max heap]
    - In heapsort, we pop the root of a max heap, add it to the end and call heapify on the new root recursively.
    - Best case time complexity is in O(n*log(n))
    - Avg case time complexity is in O(n*log(n) 
    - Worst case time complexity is in O(n*log(n))
- Heapify
    - It is a top down approach
    - It is called on a specific node and compares the max element with left and right child
    - Then it replaces the node with max element and recursively calls itself on the child that was swapped
    - Runtime complexity is in O(log(n)) for worst case
    - Best case complexity is in O(1)
    - Average time complexity is in O(log(n))
    - It's an in-place algorithm
- Buildheap
    - Build heap calls heapify from the bottom up
    - It starts from the middle of the array and calls heapify on every node from len/2 to 1
    - It is an in-place algorithm
    - Runtime complexity is O(n)
    - It looks like the complexity should be O(n*log(n)) but O(n) is a tighter bound [Appendix 3.0]
- Quicksort
    - This is an in-place algorithm
    - We first relocate the pivot and the comparison that triggers a swap is "less than"
    - The left of pivot and right of pivot are recursively fed to quicksort and the result is merged
    - Worst case time complexity is in O(n^2): Sorted array, with end element as pivot
    - Best case time complexity is in O(n * log(n)): When the division is nearly equal
    - Average case time complexity is in O(n*log(n)): Partially unequal division
    - Randomized quicksort uses random pivot

### Week 3 - Binary Search Trees and AVL Trees
- In a BST we have the following properties:
    - The value of a node is greater than its left subtree and less than its right subtree
- The time it takes to search in a BST is log(h), where h is the height of the tree.
- Height of the tree can range between [log(n), n].
- Insertion time and deletion time are also O(h).
- For BST insert watch this: https://youtu.be/nVJI8sUlwSs
- For BST delete watch this: https://youtu.be/g0mjZwYRErM
- BST Traversals are as follows:
    - In-order: LNR, helps in sorting
    - Pre-order: LRN
    - Post-order: NLR
- To sort an array we do the following:
    - Feed array in BST: O(n*h)
    - BST in-order traversal: O(n)
    - Total time: O(n*h)
- Non recursive implementations are more efficient
- BST's can be used to implement priority queue
- Find minimum or maximum: O(h)
- Finding successor or predecesor: O(h)
    - You have two cases: Search the subtree is it exits or track back until you find a right parent or left parent respectively.
- We use AVL trees to make height in O(log(n))
- Balance factor = height of left subtree – height of right subtree
- AVL trees have a balance factor of 1, 0 or -1
- AVL uses rotations:
    - Left rotation
    - Right rotation
    - Left-right rotation (Double rotations)
    - Right-left rotation (Double rotations)
- Insertion uses atmost two rotations: Watch this to learn insertion: https://youtu.be/CdGVkgMuq_4
- Deletion can use upto log(n) rotations: Watch this to learn deletion: https://youtu.be/kD_xn7mZ6v8
- Sorting in AVL tree takes O(n*log(n)
- BST is a form a quicksort!
- Quicksort is better than AVL sort:
    - Requires less space
    - No special DS required
    - Has better constants

### Week 4 - More sorting
- Perfect skip lists
    - Has header and sentinel nodes at the start and end respectively4
    - Search time: O(log(n))
    - Insertion, Deletion: Breaks stuff, need to make the skip list again!
- Randomized skip list:
    - Search: O(log(n))
    - Insert, delete: O(1)
- Linear time sorting requires more space
- Comparison sort takes minimun O(nlog(n)) time
- Counting sort is a stable sort: Time = O(n + k) and Space = O(n + k), k is range of numbers
- Radix sort is based on sorting LSD: Time = O(dn + dk), d is the number of digits
    - Radix sort uses a stable sorting algorithm like counting sort
- Bucket sort is used when input is obtained from a uniform distribution.
- It works in O(n) time and space complexity. Bucket sort is stable if the underlying algorithm is stable.
- Review randomized selection algo at the end of lecture slides.


### Appendix
- Appendix 1.0

| Algorithm | Worst-Case Time | Avg Case Time | Best Case Time | Space Complexity | Comments |
| --------- | --------------- | ------------- | -------------- | ---------------- | ------- |
| Insertion Sort | O(n^2) | O(n^2) | O(n) | O(1) | - |
| Merge Sort | O(n * log(n)) | O(n * log(n)) | O(n * log(n)) | O(n) [Can be O(1)] | - |
| Heapify | O(log n) | O(log n) | O(1) | O(1) | - |
| Buildheap | O(n) | O(n) | O(n) | O(1) | - |
| Heapsort | O(n * log(n)) | O(n * log(n)) | O(n * log(n)) | O(1) | - |
| Quicksort | O(n^2) | O(n * log(n)) | O(n * log(n)) | O(1) | Fast in practice |
| BST Insert | O(n) | O(log n) | O(1) | O(1) | - |
| BST Delete | O(n) | O(log n) | O(1) | O(1) | - |
| BST Search | O(n) | O(log n) | O(1) | O(1) | - |
| BST Sort   | O(n^2) | O(n * log(n)) | O(n * log(n)) | O(n) | - |
| AVL Insert | O(log n) | O(log n) | O(1) | O(1) | Tree is already formed |
| AVL Delete | O(log n) | O(log n) | O(1) | O(1) | Tree is already formed |
| AVL Search | O(log n) | O(log n) | O(1) | O(1) | Tree is already formed |
| AVL Sort   | O(n * log n) | O(n * log n) | O(n * log n) | O(n) | - |
| Skip List (randomized) Search | O(log n) | O(log n) | O(log n) | O(1) | - |
| Skip List (randomized) Delete /Insert | O(1) | O(1) | O(1) | O(1) | If search is already called |
| Skip List (randomized) Min/Max | O(1) | O(1) | O(1) | O(1) | - |
| Skip List (randomized) Successor/Predecessor | O(1) | O(1) | O(1) | O(1) | - |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(n + k) | n: number of elements, k: range of elemensts|
| Radix Sort | O(dn + 10d) | O(dn + 10d) | O(dn + 10d) | O(n + 10) | [For decimal base] d: max number of digits in an elem; Using counting sort|
| Bucket Sort | O(n^2) | O(n) | O(n + k) | O(n + k) | n: number of buckets, k: avg. elements in each bucket |
 






