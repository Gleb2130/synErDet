#pragma once


template<class T>
struct Node
{
	T value;
	Node* next;

	Node(const T& value) : value(value), next(nullptr) {}
};
