// PBDS -> policy based data structure
#include <iostream>

// 1. Include PBDS headers
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// 2. Use the PBDS namespace
using namespace __gnu_pbds;

// 3. Define the Ordered Set
typedef tree<
    int,                                     // 1. Key type (can be int, long long, pair, etc.)
    null_type,                               // 2. Mapped-policy (null_type means it acts like a Set. If it were int, it would act like a Map)
    less<int>,                               // 3. Comparator (less<int> for ascending order, greater<int> for descending)
    rb_tree_tag,                             // 4. Underlying data structure (Red-Black Tree)
    tree_order_statistics_node_update        // 5. Node update policy (This is what enables the two superpower functions!)
> ordered_set;

int main() {
    ordered_set st;
    
    // Inserting elements (O(log N))
    st.insert(10);
    st.insert(2);
    st.insert(7);
    st.insert(7); // It's a set, so duplicates are ignored.
    st.insert(15);

    // The set currently contains: {2, 7, 10, 15}

    // --- SUPERPOWER 1: find_by_order ---
    // Finds the element at a specific index (0-based)
    cout << "Element at index 0: " << *st.find_by_order(0) << "\n"; // Outputs 2
    cout << "Element at index 2: " << *st.find_by_order(2) << "\n"; // Outputs 10

    // --- SUPERPOWER 2: order_of_key ---
    // Finds the number of strictly smaller elements
    cout << "Number of elements less than 10: " << st.order_of_key(10) << "\n"; // Outputs 2 (the elements are 2, 7)
    cout << "Number of elements less than 8: " << st.order_of_key(8) << "\n";   // Outputs 2 (the elements are 2, 7)
    cout << "Number of elements less than 20: " << st.order_of_key(20) << "\n"; // Outputs 4

    // Removing an element (O(log N))
    st.erase(7);
    // The set now contains: {2, 10, 15}
    
    return 0;
}