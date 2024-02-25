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

### Week 5 - Hash Tables
- On average we want Search: O(1), Insert: O(1) and Delete: O(1)
- Heuristics
    - For a hash function of type k mod m, m should not be a power of 2.
    - The keys and m should not have a common divisor
    - m should be a prime number not too close to a power of 2 or 10
    - Take a look at the multiplication method in lecture slides.
    - Universal hashing is a technique where the actual hashing function has a few random components to protect against intentional performance hacking.
- Direct hashing
    - We have as many bslots as the range of keys. In a 32 bit system thats 2^32 entries.
    - Takes a LOT of memory, not feasible.
    - However, you will never have any collisions.
- Chaining
    - We add an element to the END of the linked list for elements that map to the same space.
    - If keys are uniformly alloted to each slot we will have n/m keys in a slot on average.
    - n is the number of keys and m is the number of slots. alpha = n/m (load factor)
    - The time complexity to unsuccesfully search is then O(1 + alpha/2)
    - As long as m is in O(n), time to search is constant.
- Perfect hashing
    - Only works when you know all the keys beforehand, good for stuff like dictionaries, file extensions etc.
    - Design a hash function that has no collisions
    - The other way to implement this is using two level hash tables.
    - The collisions in the first level are solved by making a new hash table for that slot.
    - The initial numbetr of slots can be m = n^2, so that our probability of collision is less than 1/2\
- Open Addressing
    - Linear probing: h(k) = (h'(k) + i) mod m, m distinct probe sequences
    - Quadratic probing: h(k, i) = (h’(k) + c * i + d * i^2 ) mod m, m distinct probe sequences
    - Both of them cause localised clustering, linear probing causes the most localization
    - Localization is not desired when assigning keys and hence we use double hashing
    - h(k, i) = (h 1(k) + i*h 2(k)) mod m
- Open addressing vs chaining
    - Open addressing uses only m slots
    - Better locality is achieved in open addressing as it avoids linked list
    - Open addressing needs a good hashing function
    - Open addressing sensitive to load factor. (alpha < 1)

### Uninformed Search Algorithms
> This section is inspired from the content taught to me by Prof. Bahar Ameri from the University of Toronto, Canada.

In a graph or grid setting, we rely on certain on certain search algorithms to find a solution. Before we discuss the algorithms, we need to be familiar with the following terminologies.

- Completeness: Will the search always find a solution if a solution exists?
- Optimality: Will the search always find the least cost solution? (when actions have costs)
- Time complexity: What is the maximum number of nodes that can be expanded or generated?
- Space complexity: What is the maximum number of nodes that have to be stored in memory?
- Solution depth: Usually denoted by d.
- Maximum branching factor: Usually denoted by b.

We will first go over a bunch of uninformed search techniques:

- Breadth-First: 
    - Explores the search tree level by level
    - Place the children of the current node at the end of the Frontier
    - Frontier is a queue. Always extract first element of the Frontier
    - One can optimize BFS by stopping once the goal node is added to the queue

- Depth-First Search: 
    - Frontier is a stack, always extract first element of the Frontier
    - An infinite graph can break completeness of a solution
    - DFS never gaurantees the most optimal solution
    - Here we define m as the length of the longest path in the state space
    - The time and space complexity will be represented in terms of m

- Depth-Limited Search:
    - Truncate the DFS search by looking only at paths of length D or less
    - No nodes with path of length greater than D is placed on the Frontier
    - Pro: Infinite length paths are not a problem
    - Cons: Only finds a solution if a solution of depth less than or equal to D exists

- Iterative-Deepening Search:
    - Starting at depth limit d = 0, iteratively increase the depth limit and perform a depth limited search for each depth limit
    - Stop if a solution is found, or if the depth limited search failed without cutting off any nodes because of the depth limit
    - If no nodes were cut off, the search examined all nodes in the state space and found no solution, hence no solution exists
    - Note that if we apply cycle checking to IDS, the space complexity is the same as BFS

- Uniform-Cost Search:
    - Always expand the least cost node on the Frontier
    - Uses a min heap for its frontier, all costs are $>= epsilon; > 0$
    - Identical to BFS if all actions have the same cost
    - All nodes with cost strictly less than C are expanded before all nodes with cost equal to C
    - The first path found to a state is the cheapest path to that state
    - Here we define C* as the optimum cost to the goal state

| Algorithm | Completeness | Optimality | Time Complexity | Space Complexity | Resources |
| --------- | --------------- | ------------- | -------------- | ---------------- | ------- |
| BFS | Yes | Yes (Shortest solution path) | O(b<sup>d + 1</sup>) | O(b<sup>d + 1</sup>) | https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/ |
| Optimized BFS | Yes | Yes (Shortest solution path) | O(b<sup>d</sup>) | O(b<sup>d</sup>) | https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/ |
| DFS | No | No | O(b<sup>m</sup>) | O(b * m) | https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/ |
| DLS with depth D| No (If solution has a depth > D) | No (If solution has depth < D) | O(b<sup>D</sup>) | O(b * D) | https://www.educative.io/answers/what-is-depth-limited-search |
| IDS (without cycle checking) | Yes | Yes (For length - Assuming D is incremented by 1) | O(b<sup>d</sup>) | O(b * d) | https://www.geeksforgeeks.org/iterative-deepening-searchids-iterative-deepening-depth-first-searchiddfs/ |
| IDS (with cycle checking) | Yes | Yes (For length - Assuming D is incremented by 1) | O(b<sup>d</sup>) | O(b<sup>d</sup>) | https://www.geeksforgeeks.org/iterative-deepening-searchids-iterative-deepening-depth-first-searchiddfs/ |
| UCS | Yes | Yes | O(b<sup>s + 1</sup>) | O(b<sup>s + 1</sup>) | Here $s = floor(C* / epsilon) + 1$ https://www.geeksforgeeks.org/uniform-cost-search-dijkstra-for-large-graphs/ |

In graph search algorithms we have two types of redundancy checks:
- Path checking: 
    - Make sure that the next node being explored is not part of the current path
    - Does not increase space or time complexity of the algo
    - Helps algorithms identify circular loops in the same path
- Cycle checking: 
    - Keep track of the all nodes previously expanded during the search using a list called the closed list.
    - Adds to the space complexity
    - Identifies all loops in a graph, not just the ones that stem from a single path.
    - Requires O(b<sup>d</sup>) space

### Informed (Heuristic) Search Algorithms
> This section is inspired from the content taught to me by Prof. Bahar Ameri from the University of Toronto, Canada.

- Develop a domain specific heuristic function $h(n)$ such that $h(n)$ guesses the cost of getting to a goal state from a node n
- $h(n)$ is a function only of the state of n
- h must be defined so that $h(n)$ = 0 for every goal node

There are two very important properties for heuristics in informed search:

- Admissible heuristics: 
    - h(n) <= h<sup>\*</sup>(n), where h<sup>*</sup>(n) is the actual minimal cost to reach the goal from that state
    - An admissible heuristic never over-estimates the cost to reach the goal, i.e., it is optimistic.

- Consistent heuristics: 
    - $h(n1) <= cost(n1, n2) + h(n2)$, where $cost(n1, n2)$ is the cost to go from state n1 to n2
    - Monotonicity implies admissibility
    - With a monotone heuristic, the first time A* expands a node n, n must be a minimum cost solution to n.state

For the informed search space, we have the following search algorithms:

- Greedy Best-First Search:
    - Use h(n) to rank the nodes on the Frontier
    - Always expand a node with lowest h-value
    - The solution returned by a greedy search can be very far from optimal

- A star:
    - Take into account the cost of the path as well as the heuristic
    - We define $f(n) = g(n) + h(n)$, and always expand the node with lowest f-value on the Frontier

- Iterative deepening A star:
    - Like iterative deepening, but now the cutoff is the f-value rather than the depth
    - At each iteration, the cutoff value is the smallest f-value of any node that exceeded the cutoff on the previous iteration.

| Algorithm | Completeness | Optimality |
| --------- | --------------- | ------------- |
| GBFS | No | No |
| A Star | Yes | Yes (With an admisible heuristic) |
| IDA Star | Yes | Yes (With an admisible heuristic) |

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
 






