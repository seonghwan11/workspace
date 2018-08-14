// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {

  cursor = nullptr;
  headnode = nullptr;
  tailnode = nullptr;
  nodesize = 0;

  headnode = new Node('H');

  if (headnode != nullptr)
	  tailnode = headnode->InsertNextNode('T');

  cursor = tailnode;

  return;
}

void TypingMachine::HomeKey() {

	cursor = headnode->GetNextNode();
  return;
}

void TypingMachine::EndKey() {
	cursor = tailnode;
  return;
}

void TypingMachine::LeftKey() {
	if (cursor->GetPreviousNode() != headnode)
		cursor = cursor->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
	if (cursor != tailnode)
		cursor = cursor->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {

	if (IsValidInput(key) && nodesize<100) {
		cursor->InsertPreviousNode(key);
		nodesize++;
		return true;
	}

  return false;
}

bool TypingMachine::EraseKey() {
	Node* previous_node;

	previous_node = cursor->GetPreviousNode();
	if (nodesize > 0 && previous_node != headnode)
	{
		cursor->ErasePreviousNode();
		nodesize--;
		return true;
	}
	
  return false;
}

std::string TypingMachine::Print(char separator) {

	std::string str;
	char data;
	Node* currentnode;

	currentnode = headnode->GetNextNode();

	for (int i = 0; i <= nodesize; i++)
	{
		if (cursor == currentnode)
		{
			if (separator!=0)
				str.push_back(separator);
		}
			
		if (currentnode == tailnode)
			break;

		data = currentnode->GetData();
		str.push_back(data);	
		currentnode = currentnode->GetNextNode();
	}

	return str;
}

bool TypingMachine::IsValidInput(char key)
{
	if ((32 <= key && key <= 126))
		return true;
	else
		return false;
}