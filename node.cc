// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {

	previous_node = nullptr;
	next_node = nullptr;
	node_data = data;

  return;
}

char Node::GetData() {
	return node_data;
}

Node* Node::GetPreviousNode() {
	return previous_node;
}

Node* Node::GetNextNode() {
	return next_node;
}

Node* Node::InsertPreviousNode(char data) {
	Node* insertNode = new Node(data);
	Node* prevNode = this->previous_node;

	insertNode->next_node = this;
	this->previous_node = insertNode;

	if (prevNode == nullptr)
		return insertNode;

	prevNode->next_node = insertNode;
	insertNode->previous_node = prevNode;

	return insertNode;
}

Node* Node::InsertNextNode(char data) {
	Node* insertNode = new Node(data);
	Node* nextNode = this->next_node;

	this->next_node = insertNode;
	insertNode->previous_node = this;

	if (nextNode == nullptr)
		return insertNode;

	insertNode->next_node = nextNode;
	nextNode->previous_node = insertNode;

	return insertNode;
}

bool Node::ErasePreviousNode() {
	Node* eraseNode = this->previous_node;

	if (eraseNode == nullptr)
		return false;

	Node* prevNode = eraseNode->previous_node;

	if (prevNode != nullptr)
		prevNode->next_node = this;
	
	this->previous_node = prevNode;

	delete eraseNode;

  return true;
}

bool Node::EraseNextNode() {
	Node* eraseNode = this->next_node;

	if (eraseNode == nullptr)
		return false;

	Node* nextNode = eraseNode->next_node;

	this->next_node = nextNode;
	if (nextNode != nullptr)
		nextNode->previous_node = this;

	delete eraseNode;

	return true;
}
