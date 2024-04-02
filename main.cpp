#include <iostream>
#include "set.h"

using namespace std;

int main() {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);
    cout << "Set1: " << set1 << "\n";

    Set<int> set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);
    cout << "Set2: " << set2 << "\n";

    Set<int>connectSet = set1.connectSet(set2);
    cout << "Set1 <3 Set2: " << connectSet << "\n";

    Set<int> intersectionSet = set1.intersection(set2);
    cout << "Intersection: " << intersectionSet << "\n";

    Set<int> differenceSet = set1.difference(set2);
    cout << "Difference: " << differenceSet << "\n";

    Set<int> differenceSet2 = set2.difference(set1);
    cout << "Difference: " << differenceSet2 << "\n";
    return 0;
}