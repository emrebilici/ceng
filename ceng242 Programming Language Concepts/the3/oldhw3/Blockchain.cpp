#include "Blockchain.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Blockchain::Blockchain(int id) : head(nullptr), id(id), softForked(false) {}

Blockchain::Blockchain(int id, Koin *head) : head(head), id(id), softForked(false) {}

Blockchain::Blockchain(int id, Koin *head, bool p) : head(head), id(id), softForked(p) {}

Blockchain::Blockchain(const Blockchain& rhs) : id(rhs.id), head(nullptr), softForked(false) {
 	if (rhs.head != nullptr) {
	 	head = new Koin(rhs.head -> getValue());
		Koin* p(head);
		Koin* q(rhs.head -> getNext());
		while (q != nullptr) {
			p -> setNext(new Koin(q -> getValue()));
			p = p -> getNext();
			q = q -> getNext();
 		}
 	}
 }

Blockchain& Blockchain::operator=(Blockchain&& rhs) noexcept {
 	std::swap(this -> head, rhs.head);
 	std::swap(this -> softForked, rhs.softForked);
 	return *this;
 }

Blockchain::~Blockchain() {
	Koin* p(head);
	Koin* q(nullptr);
	while (p != nullptr) {
		q = p -> getNext();
		delete p;
		p = q;
	}
}

int Blockchain::getID() const {
	return id;
}

Koin* Blockchain::getHead() const {
	return head;
}

void Blockchain::setHead(Koin* new_head) {
	head = new_head;
}

bool Blockchain::getSoftForked() const {
    return softForked;
}

void Blockchain::setSoftForked(bool p) {
    softForked = p;
}

 double Blockchain::getTotalValue() const {
 	double total(0);
 	Koin* p(head);
 	while (p != nullptr) {
 		total += p -> getValue();
 		p = p -> getNext();
 	}
 	return total;
 }

 long Blockchain::getChainLength() const {
 	long length(0);
 	Koin* p(head);
 	while (p != nullptr) {
 		length++;
 		p = p -> getNext();
 	}
 	return length;
 }

void Blockchain::operator++() {
	Koin* new_koin = new Koin(Utilizer::fetchRandomValue());
	if (head == nullptr) {
		head = new_koin;
	}
	else {
		Koin* p(head);
		while (p -> getNext() != nullptr) {
			p = p -> getNext();
		}
		p -> setNext(new_koin);
	}
}

void Blockchain::operator--() {
	if (head != nullptr) {
		if (head -> getNext() == nullptr) {
			if (head -> getSoftForked() == false) {
				delete head;
				head = nullptr;
			}
		}
		else {
			Koin* p(head);
			Koin* q(nullptr);
			while (p -> getNext() != nullptr) {
				q = p;
				p = p -> getNext();
			}
			if (p -> getSoftForked() == false) {
				delete p;
				q -> setNext(nullptr);
			}
		}
	}
}

Blockchain& Blockchain::operator*=(int multiplier) {
	Koin* p(head);
	while (p != nullptr) {
		(*p) *= multiplier;
		p = p -> getNext();
	}
}

Blockchain& Blockchain::operator/=(int divisor) {
	Koin* p(head);
	while (p != nullptr) {
		(*p) /= divisor;
		p = p -> getNext();
	}
}

std::ostream& operator<<(std::ostream& os, const Blockchain& blockchain) {
	os.precision(Utilizer::koinPrintPrecision());
	os << std::fixed;
	if (blockchain.head == nullptr) {
		os << "Block " << blockchain.getID() << ": " << "Empty.";
		return os;
	}
	os << "Block " << blockchain.getID() << ": " << (*(blockchain.head)) << "(" << (blockchain.getTotalValue()) << ")";
	return os;
}
