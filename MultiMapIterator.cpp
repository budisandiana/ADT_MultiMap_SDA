#include "MultiMapIterator.h"
#include "MultiMap.h"


//Theta(1)
MultiMapIterator::MultiMapIterator(const MultiMap& c) : col{ c }
{
	this->current_elem = c.head;
}

//Theta(1)
void MultiMapIterator::first()
{
	this->current_elem = this->col.head;
}

//Theta(1)
void MultiMapIterator::next()
{
	if (this->current_elem == NULL)
		throw std::exception("Invalid iterator!");
	this->current_elem = this->current_elem->next;
}

//Theta(1)
bool MultiMapIterator::valid() const
{
	if (this->current_elem == NULL)
		return false;
	return true;
}

//Theta(1)
TElem MultiMapIterator::getCurrent() const
{
	if (!valid()) {
		exception ex;
		throw ex;
	}
	else {
		return this->current_elem->value;
	}
	return NULL_TELEM;
}



