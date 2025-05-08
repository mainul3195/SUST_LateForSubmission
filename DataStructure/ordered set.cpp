#include<ext/pb_ds/assoc_container.hpp>#include<ext/pb_ds/tree_policy.hpp>using namespace std;using namespace __gnu_pbds;
template<class T> using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
//1 2 2 3 3 7
//greater->>descending order => 7 3 2 1
//less ->>ascending order => 1 2 3 7
//less_equal -> ascending but in duplicate value => 1 2 2 3 3 7 so this will work as multiset
// finding kth element - 4th query
cout << "0th element: " << *A.find_by_order(0) << endl;
// finding number of elements smaller than X - 3rd query
cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; //
