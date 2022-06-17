#pragma once

//https://fr.wikipedia.org/wiki/Arbre_AVL
namespace ft
{
	template <typename T>
	struct node
	{
		T value;
		node *left;
		node *right;
		node *parent;
		bool last;

		node(T v, node *l, node *r, node *p, bool e = false) : value(v), left(l), right(r), parent(p), last(e) {}
		~node() {}
	};
}