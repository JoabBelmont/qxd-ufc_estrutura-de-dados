/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
	m_head = new Node(0, nullptr);
	m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
	m_head = new Node(0, nullptr);
	m_size = lst.m_size;
	Node *lstCurrent = lst.m_head->next;
	Node *thisLast = m_head;
	while(lstCurrent != nullptr) {
		thisLast->next = new Node(lstCurrent->value, nullptr);
		lstCurrent = lstCurrent->next;
		thisLast = thisLast->next;
	}
}

bool ForwardList::empty() const {
	return m_head->next == nullptr;
}

int ForwardList::size() const {
	return m_size;
}

void ForwardList::clear() {
	while(m_head->next != nullptr) {
		Node *aux = m_head->next;
		m_head->next = aux->next;
		delete aux;
	}
	m_size = 0;
}

ForwardList::~ForwardList() {
	clear();
	delete m_head;
}

Item& ForwardList::operator[](int index) {
	int count = 0;
	Node *current = m_head->next;
	while(count < index) {
		current = current->next;
		count++;
	}
	return current->value;
}

const Item& ForwardList::operator[](int index) const {
	int count = 0;
	Node *current = m_head->next;
	while(count < index) {
		current = current->next;
		count++;
	}
	return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
	int count = 0;
	Node *current = m_head;
	while(count < index) {
		current = current->next;
		count++;
	}
	Node *newNode = new Node(val, current->next);
	current->next = newNode;
	m_size++;
}

void ForwardList::remove_at(int index) {
	int count = 0;
	Node *current = m_head;
	while(count < index) {
		current = current->next;
		count++;
	}
	Node *temp = current->next;
	current->next = temp->next;
	delete temp;
	m_size--;
}

std::string ForwardList::toString() {
	std::string str = "[ ";
	Node *ptr = m_head->next;
	while(ptr != nullptr) {
		str += std::to_string(ptr->value) + " ";
		ptr = ptr->next;
	}
	str += "]";
	return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList &lst) { // certo
	Node *auxNode = m_head;
	while(auxNode->next)
		auxNode = auxNode->next;
	auxNode->next = lst.m_head->next;
	this->m_size += lst.m_size;
	lst.m_head->next = nullptr;
	lst.m_size = 0;
}

void ForwardList::remove(const Item &val) { // certo
	if(m_head == nullptr) return;
	Node *auxNode = m_head;
	while(auxNode->next) {
		if(auxNode->next->value == val) {
			Node *auxNext = auxNode->next;
			auxNode->next = auxNext->next;
			delete auxNext;
			auxNext->next = nullptr;
			m_size--;
		} else
			auxNode = auxNode->next;
	}
}

ForwardList *ForwardList::clone() { // certo
	ForwardList *clonedList = new ForwardList();
	Node *aux1 = this->m_head;
	Node *aux2 = clonedList->m_head;
	while(aux1->next) {
		Node *newNode = new Node(aux1->next->value, nullptr);
		aux2->next = newNode;
		aux1 = aux1->next;
		aux2 = aux2->next;
	}
	clonedList->m_size = this->m_size;
	return clonedList;
}

void ForwardList::appendVector(const std::vector<Item> &vec) { // certo
	Node *auxNode = m_head;
	while(auxNode->next)
		auxNode = auxNode->next;
	for(int i : vec) {
		Node *newNode = new Node(i, nullptr);
		auxNode->next = newNode;
		auxNode = auxNode->next;
		m_size++;
	}
	auxNode->next = nullptr;
}

void ForwardList::swap(ForwardList &lst) {
	// switches the lists' elements
	Node *auxNode = this->m_head->next;
	this->m_head->next = lst.m_head->next;
	lst.m_head->next = auxNode;

	// switches the lists' sizes
	int auxSize = lst.m_size;
	lst.m_size = this->m_size;
	this->m_size = auxSize;
}

bool ForwardList::equals(const ForwardList &lst) const { // certo
	Node *aux1 = this->m_head;
	Node *aux2 = lst.m_head;
	if(this->m_size != lst.m_size) return false;
	while(aux1 && aux2) {
		if(aux1->value != aux2->value) return false;
		aux1 = aux1->next;
		aux2 = aux2->next;
	}
	return true;
}

void ForwardList::reverse() {
	Node *aux1 = nullptr, *aux2 = nullptr;
	while(m_head->next) {
		aux2 = m_head->next->next;
		m_head->next->next = aux1;
		aux1 = m_head->next;
		m_head->next = aux2;
	}
	m_head->next = aux1;
}

Item &ForwardList::get(int index) { // certo
	Node *current = m_head;
	if(index < 0 || index >= m_size)
		throw std::range_error("Index out of range");
	else {
		for(int i = 0; i < index; ++i)
			current = current->next;
		return current->next->value;
	}
}

const Item &ForwardList::get(int index) const { // certo
	Node *current = m_head;
	if(index < 0 || index >= m_size)
		throw std::range_error("Index out of range");
	else {
		for(int i = 0; i < index; ++i)
			current = current->next;
		return current->next->value;
	}
}
