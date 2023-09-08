import heapq

# Step 1: Initialize an empty list to represent the max-heap
max_heap = []

# Step 2 (Optional): Heapify an existing list
existing_list = [4, 10, 3, 5, 1]
# Negate values to create a max-heap
max_heap = [-x for x in existing_list]
heapq.heapify(max_heap)
print("Max-Heap from existing_list:", [-x for x in max_heap])

# Step 3: Insert elements into the max-heap (negate values)
heapq.heappush(max_heap, -8)
heapq.heappush(max_heap, -12)
heapq.heappush(max_heap, -2)
heapq.heappush(max_heap, -9)
heapq.heappush(max_heap, -6)
print("Max-Heap after insertions:", [-x for x in max_heap])

# Step 4: Get the maximum element from the max-heap (without removing)
max_element = -max_heap[0]
print("Maximum element in the max-heap (without removal):", max_element)

# Step 5: Remove the maximum element from the max-heap (with negation)
max_element_removed = -heapq.heappop(max_heap)
print("Removed maximum element from the max-heap:", max_element_removed)
print("Max-Heap after removal:", [-x for x in max_heap])

