#include "BST.h"

using Dict = BST;

int main()
{
	Dict dict;

	dict.insert(22, "Jane");
	dict.insert(22, "Mary");
	dict.insert(0, "Harold");
	dict.insert(9, "Edward");
	dict.insert(37, "Victoria");
	dict.insert(4, "Matilda");
	dict.insert(26, "Oliver");
	dict.insert(42, "Elizabeth");
	dict.insert(19, "Henry");
	dict.insert(4, "Stephen");
	dict.insert(24, "James");
	dict.insert(-1, "Edward");
	dict.insert(31, "Anne");
	dict.insert(23, "Elizabeth");
	dict.insert(1, "William");
	dict.insert(26, "Charles");

	//dict.displayEntries();

	std::cout << "Initial Tree\n" << std::endl;

	dict.displayTree();

	dict.insert(7, "James");
	dict.insert(43, "Kelly");

	std::cout << "\nTree after insert 7, 43\n" << std::endl;
	dict.displayTree();

	dict.lookup(37);
	dict.lookup(-1);
	dict.lookup(43);
	dict.lookup(19);

	dict.remove(7);
	//dict.remove(43);

	/*dict.remove(-1);
	dict.remove(1);
	dict.remove(19);
	dict.remove(23);
	dict.remove(23);
	dict.remove(31);
	dict.remove(42);*/

	std::cout << "\nTree after remove 7\n" << std::endl;

	dict.displayTree();

	dict.remove(24);
	dict.remove(42);

	std::cout << "\nTree after remove 24, 42\n" << std::endl;

	dict.displayTree();
}