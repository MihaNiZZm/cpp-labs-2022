#include <iostream>

#include "LinkedHashSet.h"

int main(int argc, char** argv) {
	LinkedHashSet::linkedhs set1;
	LinkedHashSet::linkedhs set2;

	LinkedHashSet::element stud1(17, "Vasya");
	LinkedHashSet::element stud2(17, "Bibra");

	set1.insert(stud1);
	set2.insert(stud2);

	set1.print();
	set2.print();

	set1.swap(set2);

	set1.print();
	set2.print();
	
	return 0;
}
