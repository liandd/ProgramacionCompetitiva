"""
CIDR Solution for GNY Regional 2021
Author: Borja Sotomayor

This solution just relies on Python lists and strings without
having to resort to bit-level fiddling. We basically convert
the IP addresses to binary strings (which is fairly easy
in python using the built-in "format" function), and then
find the longest prefix by checking whether all the bits
in index 0 (across all addresses) are equal, then index 1,
then index 2, etc. stopping when we encounter a bit where
all the addresses don't have the same value.
"""

import sys

# Read input
tokens = [t.strip() for t in sys.stdin.read().strip().split()]
tokens.reverse()

n_addr = int(tokens.pop())
assert n_addr == len(tokens)

# Convert addresses to binary strings
addrs = []
for t in tokens:
    addr = ""
    bytes = t.split(".")
    for byte in bytes:
        bin = format(int(byte), "08b")
        addr += bin

    assert len(addr) == 32
    addrs.append(addr)

# Find the longest prefix
for i in range(32):
    first = addrs[0][i]
    all_equal = all(first == a[i] for a in addrs)
    if not all_equal:
        print(i)
        break
else:
    print(32)
