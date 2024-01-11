# C++ STL Overview

## [Officia Website](https://en.cppreference.com/w/cpp/container)

The C++ Standard Template Library (STL) provides a rich set of data structures and algorithms that can be used to perform various operations efficiently.

## Sequence Containers

### `std::vector`

Dynamic array.

### `std::list`

Doubly linked list.

### `std::deque`

Double-ended queue.

## Associative Containers

### `std::set`

Ordered set of unique keys.

### `std::map`

Ordered map of key-value pairs.

### `std::multiset`

Ordered set of keys (allows duplicates).

### `std::multimap`

Ordered map of key-value pairs (allows duplicates).

## Unordered Containers (Hash-based)

### `std::unordered_set`

Unordered set of unique keys.

### `std::unordered_map`

Unordered map of key-value pairs.

### `std::unordered_multiset`

Unordered set of keys (allows duplicates).

### `std::unordered_multimap`

Unordered map of key-value pairs (allows duplicates).

## Container Adapters

### `std::stack`

LIFO (Last In, First Out) container adapter.

### `std::queue`

FIFO (First In, First Out) container adapter.

### `std::priority_queue`

Priority queue.

## Iterators

- `begin()`, `end()`, `rbegin()`, `rend()`: Iterators for the beginning and end of a container.

## Algorithms

A wide range of algorithms such as sorting (`std::sort`), searching (`std::find`), and manipulating (`std::copy`, `std::transform`, etc.).

## Utilities

### `std::pair`

Pair of values, commonly used in associative containers.

### `std::tuple`

Tuple of values.

### `std::bitset`

Fixed-size sequence of bits.

### `std::optional`

Represents an optional (nullable) value.

## Memory Management

### `std::allocator`

Allocator class template.

### `std::shared_ptr`, `std::unique_ptr`, `std::weak_ptr`

Smart pointers for managing dynamic memory.
