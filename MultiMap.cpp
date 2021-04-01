#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

//complexitate: theta(1)
MultiMap::MultiMap(): head { NULL }
{
}

//complexitate: theta(1)
void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	std::pair <TKey, TValue> elem;
	elem = std::make_pair(c, v); //am creat o noua pereche de TKey c si TValue v
	SLLNode* new_node = new SLLNode[1]; //creem un nou nod
	new_node->value = elem; //adaugam perechea la noul nod
	new_node->next = this->head;
	this->head = new_node;
}

//complexitate: 
//best case: theta(1) - daca mmp e gol
//worst/avg case: O(n) - n = lungime mmp
bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	std::pair <TKey, TValue> elem = std::make_pair(c, v); //creem un element cu valorile date ca argument
	SLLNode* current = this->head; //punem in nodul curent head ul ca sa cautam de la inceput 
	SLLNode* prev = NULL;
	if (isEmpty()) {
		return false;
	}
	//incepem sa cautam elemente
	while (current != NULL && current->value != elem)
	{
		//prev = elementul dinaintea elementului pe care vrem sa il stergem
		prev = current; //il 
		current = current->next;
	}
	//cazul in care prev == NULL => am sters chiar head ul
	if (current != NULL && prev == NULL)
	{
		//setam head ul pe urmatorul element dupa current
		this->head = this->head->next;
		delete current;
		return true;
	}
	//cazul daca prev nu e NULL
	else if (current != NULL)
	{
		//ii dam la elementul dinainte, next ul elementului curent
		prev->next = current->next;
		current->next = NULL; //stergem next ul elementului curent
		delete current;
		return true;
	}
	//daca nu a gasit niciun element => false
	delete current;


	return false;
}

//complexitate: 
//best case: theta(1) - daca mmp e gol
//worst/avg case: O(n) - n = lungime multimap
vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	vector<TValue> v{}; //in v vom avea toate elementele cu key=c
	//daca e gol returneaza vector gol
	if (isEmpty())
		return {};
	//daca nu e gol, ne plimbam prin tot container ul, incepand de la head
	SLLNode* current = this->head;
	while (current != NULL)
	{
		//punem in vector elementele care au key = c
		if (current->value.first == c)
		{
			v.push_back(current->value.second);
		}
		current = current->next;
	}

	return v;
}

//complexitate:
//best case: theta(1) - mmp e gol
//worst/avg: O(n) - n = lungime mmp
int MultiMap::size() const {
	//TODO - Implementation
	int count = 0; //initializam cu lungime 0
	SLLNode* current = this->head;
	if (isEmpty()) {
		return 0;
	}
	//parcurg elementele din multimap
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

//complexitate: theta(1)
bool MultiMap::isEmpty() const {
	//TODO - Implementation
	if (head == NULL)
		return true;
	else
		return false;
}


MultiMapIterator MultiMap::iterator() const {
	MultiMapIterator m_it{ *this };
	return m_it;
}

//complexitate: 
//best case: theta(1) - mmp e gol
//worst/avg case: O(n) - n = lungime mmp
MultiMap::~MultiMap() {
	//TODO - Implementation
	SLLNode* aux = this->head; //initializez un nod cu head ul
	while (aux != NULL)
	{
		this->head = aux->next;
		delete aux;
		aux = this->head;
	}
}

