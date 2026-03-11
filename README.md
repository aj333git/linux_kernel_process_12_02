# Linux Kernel Memory Zones Module

A simple Linux Kernel Module (LKM) that inspects the system's memory
layout and prints information about memory zones in the kernel log.

The module walks through each memory node and zone and prints how many
pages are managed by each zone.

This project is intended for learning Linux kernel internals and memory
management concepts.

---

## Memory Analogy

Think of computer memory like a city:

Building (Node) → pglist_data  
Floor (Zone) → struct zone  
Rooms (Pages) → struct page  

Example:

Node (building)
 ├── Zone DMA (floor)
 ├── Zone DMA32 (floor)
 └── Zone Normal (floor)

Each zone contains many memory pages (rooms).

---

## Kernel Concepts Used

| Concept | Description |
|-------|-------------|
| pglist_data | Memory node descriptor |
| struct zone | Memory zone structure |
| zone_managed_pages() | Returns number of pages in zone |
| populated_zone() | Checks if zone contains memory |
| for_each_online_node() | Iterates over active memory nodes |

Headers used:


