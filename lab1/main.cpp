#include <iostream>

#include "LinkedHashSet.h"

int main(int argc, char** argv) {
	LinkedHashSet::linkedhs newSet;
	newSet.insert(LinkedHashSet::element(17, "Vasya Pupkin"));
	newSet.insert(LinkedHashSet::element(17, "Pupa"));
	newSet.insert(LinkedHashSet::element(17, "Lupa"));
	newSet.insert(LinkedHashSet::element(17, "Vasya Pupkin"));
	newSet.remove(LinkedHashSet::element(17, "Lupa"));
	newSet.remove(LinkedHashSet::element(17, "Vasya Pupkin"));
	newSet.remove(LinkedHashSet::element(17, "Lupa"));
	newSet.remove(LinkedHashSet::element(17, "Pupa"));
	return 0;
}
