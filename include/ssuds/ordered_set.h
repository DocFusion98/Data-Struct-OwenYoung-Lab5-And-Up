#pragma once
#include <string>
#include <stdexcept>
#include <ostream>
#include <vector>
#include "array_list.h"
#include <stdio.h>

namespace ssuds
{
	template <class T>
	class OrderedSet
	{
	private:
		// Just like LinkedList, I don't want outside users to see this AT ALL!!!
		class Node
		{
		private:
			T mData;
			Node* mLeft;
			Node* mRight;
			Node* mParent;
		public:
			Node(const T& data, Node* left, Node* right, Node* parent) : mData(data), mLeft(nullptr),
				mRight(nullptr), mParent(nullptr)
			{
				// intentionally empty
			}

			// Other getters/setters
			
			/// <summary>
			/// Continuously loops through ordered set to add new nodes. Lesser values go towards the left, larger to the right
			/// </summary>
			/// <param name="new_val"></param>
			/// <returns></returns>
			bool insert_recursive(const T& new_val)
			{
				if (new_val == mData)
					return false;			// It's a duplicate -- stop!
				else if (new_val < mData)
				{
					// This should go to my left
					if (mLeft == nullptr)
					{
						// I don't have a left-child -- make a new node that BECOMES the left child.
						mLeft = new Node(new_val);
						return true;
					}
					else
					{
						// I DO have a left child
						mLeft->insert_recursive(new_val);
					}
				}
				else
				{
					if (mRight == nullptr)
					{
						// I don't have a left-child -- make a new node that BECOMES the left child.
						mRight = new Node(new_val);
						return true;
					}
					else
					{
						// I DO have a left child
						mRight->insert_recursive(new_val);
					}
					// This should go to my right -- similar to left case
				}
			}


			bool contains_recursive(const T& val, Node* cur_node) const
			{
				
				if (cur_node->mData == val) {
					return true;
				}
				else if (cur_node->mData > val) {
					if (cur_node->mLeft != nullptr) {
						cur_node = cur_node->mLeft;
						return contains_recursive(val, cur_node);

					}
					else {
						return false;
					}
				}
				else {
					if (cur_node->mRight != nullptr) {
						cur_node = cur_node->mRight;
						return contains_recursive(val, cur_node);

					}
					else {
						return false;
					}
				}

				// If I hold the value, return true.
				// If the value is less than my data it *WOULD* go to my left
				//     If I don't have a left child, return false
				//     If I do, ask the left child to compute the answer.
			}
		}; // end of Node class

		// Attributes for OrderedSet itself.
	private:
		unsigned int mSize;
		Node* mRoot;
	public:
		OrderedSet() : mSize(0), mRoot(nullptr)
		{
			// intentionally empty.
		}


		/// <summary>
		/// Creates a node in the ordered set
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		bool insert(const T& val)
		{
			if (mSize == 0)
			{
				// Nothing here -- make the new node the root
				mRoot = new Node(val);
				mSize = 1;
				return true;
			}
			else
			{
				// We already have a root -- let it handle the rest
				bool result = mRoot->insert_recursive(val);
				if (result)
					mSize++;
			}
		}
		/// <summary>
		/// Checks if an ordered set has a given value somewhere, and will return true or false based on its findings
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		bool contains(const T& val) const
		{
			if (!mRoot)
				return false;
			else
				return mRoot->contains_recursive(val, mRoot);
		}
		/// <summary>
		/// Changes the node looked at as the root
		/// </summary>
		void rebalance() {

		}
		/// <summary>
		/// Returns the amount of nodes in an ordered set
		/// </summary>
		/// <returns></returns>
		unsigned int size() {
			return mSize;
		}
		/// <summary>
		/// Removes all nodes in the ordered set
		/// </summary>
		void clear() {
			Node* cur_node = mRoot;
			if (mSize != 0) {
				if (cur_node->mLeft != nullptr) {

				}
				else if (cur_node->mRight != nullptr) {

				}
				else {

				}
			}
		}


		/*
		ssuds::ArrayList traversal() {

		}
		*/
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>


		/// <summary>
		/// Returns the amount of nodes from the root to the furthest leaf
		/// </summary>
		/// <returns></returns>
		unsigned int get_height() {

		}

		bool erase(const T& val) {

		}

		/// <summary>
		/// Returns pointer to the node above the one containing the given value
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		Node* get_parent(const T& val) {

		}

	};
}