#pragma once
#include <string>
#include <stdexcept>
#include <ostream>

namespace ssuds
{

	enum class LinkedListIteratorType { forward, backwards };

	template <class T>
	class LinkedList
	{
		// IMPORTANT DESIGN CONSIDERATION: User shouldn't be able to see any Nodes!!
	private:
		
		class Node			// Each instance corresponds to an orange "box" in the slides
		{
		public:
			T mData;
			Node* mNext;
			Node* mPrevious;
		};

		// Attributes
		Node* mStart;			// Sometimes called the "head"
		Node* mEnd;				// Sometimes called the "tail"
		unsigned int mSize;


		Node* remove_internal(Node* node_to_remove)
		{
			int start = 0;
			int end = 0;
			Node* next_node = node_to_remove->mNext;
			if (node_to_remove->mPrevious != nullptr) {
				if (node_to_remove->mNext != nullptr) {
					node_to_remove->mNext->mPrevious = node_to_remove->mPrevious;
				}
				else {
					end = 1;
				}
			}
			else {
				mStart = node_to_remove->mNext;
				start = 1;
			}
			if (node_to_remove->mNext != nullptr && start == 0) {
				node_to_remove->mPrevious->mNext = node_to_remove->mNext;
			}

			else {
				mEnd = node_to_remove->mPrevious;
				
			}
			delete node_to_remove;
			return next_node;

			// Checks for whether that's the start/end node, actually
			// free up the memory, adjust pointers, etc.

			// Then return the pointer to the node *after* the one we
			// just deleted.
		};
		Node* clearer(Node* node_to_remove) {
			Node* next_node = node_to_remove->mNext;
			delete node_to_remove;
			return next_node;
		}


	public:

		class LinkedListIterator
		{
		protected:
			/// <summary>
			/// A pointer to the containing LinkedList
			/// </summary>
			

			/// <summary>
			/// The current position within the linked list.  Anything from 0...LinkedListSize-1 is considered
			/// "valid", all other values are invalid
			/// </summary>

			Node* mCurNode;

			/// <summary>
			/// Which type of iterator are we?
			/// </summary>
			LinkedListIteratorType mType;



		public:
			/// <summary>
			/// The main constructor
			/// </summary>
			/// <param name="arr">The LinkedList we are to traverse</param>
			/// <param name="tp">What type of traversal to do</param>
			/// <param name="start_index">The index to start on</param>
			LinkedListIterator(Node* cur_node, LinkedListIteratorType dir){
				mCurNode = cur_node;
				mType = dir;
			}

			LinkedListIterator() {
				mCurNode = nullptr;
				mType = LinkedListIteratorType::forward;
			}

			void operator++() {
				if (mType == LinkedListIteratorType::forward)
					mCurNode = mCurNode->mNext;
				else
					mCurNode = mCurNode->mPrevious;

				return LinkedListIterator(mCurNode, mType);
			}

			bool operator==(const LinkedListIterator& other) {
				if (mCurNode == other.mCurNode && mType == other.mType) {
					return true;
				};
			}

			bool operator!=(const LinkedListIterator& other) {
				return !(*this == other);
			}

			LinkedListIterator operator+(int num) {
				if (num >= 0) {
					for (int i = 0; i != num; i++) {
						this++;
					}
				}
				else {
					num *= -1;
					for (int i = 0; i != num; i++) {
						this--;
					}
				}
			}

		};
		/// <summary>
		/// Main Constructor
		/// </summary>
		LinkedList()
		{
			mStart = nullptr;
			mEnd = nullptr;
			mSize = 0;
		}

		
		/// <summary>
		/// Destructor
		/// </summary>
		~LinkedList() {
			delete mEnd;
		}

		/// <summary>
		/// Move Constructor
		/// </summary>
		/// <param name="other"></param>
		LinkedList(LinkedList&& other)
		{
			other.clear;
		}

		/// <summary>
		/// Copy Constructor
		/// </summary>
		/// <param name="other"></param>
		LinkedList(const LinkedList& other) : mSize(other.mSize)
		{
			
		}

		/// <summary>
		/// Removes every node in a linked list
		/// </summary>
		void clear() {
			Node* cur_node = mStart;
			while (cur_node != nullptr) {
				cur_node = clearer(cur_node);
				mSize--;
			}
			mStart = nullptr;
			mEnd = nullptr;
		}

		/// <summary>
		/// Adds a node to the end of a linked list with the value given
		/// </summary>
		/// <param name="val"></param>
		void append(const T& val)
		{

			if (mSize == 0)
			{
				// Case1: list is empty
				// a. Make a new Node
				// b. Make mStart and mEnd point to it.
				Node* new_node = new Node;
				mStart = mEnd = new_node;			// Maybe add a constructor to Node??
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
			}
			else
			{
				// Case2: list has data in it
				Node* new_node = new Node;
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
				// Make the current last node point to this new one
				mEnd->mNext = new_node;
				// Make the new node point to the *CURRENT* end node
				new_node->mPrevious = mEnd;
				// Make the new node THE last node
				mEnd = new_node;
			}
			// Increase size
			mSize++;
		}


		/// <summary>
		/// Adds a node to the beginning of a linked list with the value given
		/// </summary>
		/// <param name="val"></param>
		void prepend(const T& val) {
			if (mSize == 0)
			{
				// Case1: list is empty
				// a. Make a new Node
				// b. Make mStart and mEnd point to it.
				Node* new_node = new Node;
				mStart = mEnd = new_node;			// Maybe add a constructor to Node??
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
			}
			else
			{
				// Case2: list has data in it
				Node* new_node = new Node;
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
				// Make the current last node point to this new one
				mStart->mPrevious = new_node;
				// Make the new node point to the *CURRENT* end node
				new_node->mNext = mStart;
				// Make the new node THE last node
				mStart = new_node;
			}
			// Increase size
			mSize++;
		}


		/// <summary>
		/// Returns how many nodes are in a linked list
		/// </summary>
		/// <returns></returns>
		unsigned int size() const
		{
			return mSize;
		}

		/// <summary>
		/// Displays all of the nodes in a linked list
		/// </summary>
		/// <param name="os"></param>
		void output(std::ostream& os)
		{
			// Output in python-list style output: [A, B, C, D, E].  This pattern
			// is called ITERATING (not iterator) through all the nodes -- very
			// common pattern in the linked list.
			os << "[";
			Node* cur_node = mStart;		// Might be nullptr!!
			for (unsigned int i = 0; i < mSize; i++)
			{
				//os << mData[i];		// Not a thing here!!!
				os << cur_node->mData;
				cur_node = cur_node->mNext;
				if (i < mSize - 1)
					os << ", ";
			}
			os << "]";
		}

		/// <summary>
		/// Uses output to work with cout
		/// </summary>
		/// <param name="os"></param>
		/// <param name="llist"></param>
		/// <returns></returns>
		friend std::ostream& operator <<(std::ostream& os, const LinkedList& llist) {
			llist.output(os);
			return os;
		}

		/// <summary>
		/// Places a new node in a linked list at the location given with the value given
		/// </summary>
		/// <param name="val"></param>
		/// <param name="index"></param>
		void insert(const T& val, unsigned int index)
		{
			
			if (index > mSize)
				throw std::out_of_range("Invalid index: " + std::to_string(index));
			else if (index == mSize)
				append(val);
			else
			{

				// Move all elements at or after the given index down one spot
				Node* new_node = new Node;
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
				// Make the current last node point to this new one


				Node* cur_node = mEnd;

				for (unsigned int i = mSize; i > index; i--) {

					
					if (i == index + 1) {
						new_node->mNext = cur_node;
						cur_node->mPrevious = new_node;
					}
					else {
						cur_node = cur_node->mPrevious;
					}
					

				}
				// Put our new elements in spot index and increase our size
				cur_node = cur_node->mPrevious;
				new_node->mPrevious = cur_node;
				cur_node->mNext = new_node;
				mSize++;
			}
		}

		/// <summary>
		/// Takes in a value to search for, checks each node in order, and returns the location of the first instance of the value in the LinkedList
		/// </summary>
		/// <param name="val"></param>
		/// <param name="start_index"></param>
		/// <returns></returns>
		int find(const T& val, const unsigned int start_index = 0) const
		{
			if (start_index >= mSize)
				return -1;

			Node* cur_node = mStart;

			for (unsigned int i = start_index; i < mSize; i++)
			{
				T temp = at(i);
				if (temp == val)
					return i+1;
				cur_node = cur_node->mNext;
			}

			// We didn't find it
			return -1;
		}

		/// <summary>
		/// Same as the previous find, but uses an iterator
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		LinkedListIterator find_it(const T& val) const
		{
			Node* cur_node = mStart;
			// Make a copy of the LinkedListIterator we were given and one to hold the end iterator value
			LinkedListIterator temp(cur_node, LinkedListIteratorType::forward);
			


			// Now, continue until we reach the end or one of the values
			while (temp != this->end())
			{
				if (temp == val)
					return temp;
				else
					++temp;
			}

			return temp;
		}

		LinkedListIterator rbegin() const
		{
			return LinkedListIterator(this, LinkedListIteratorType::backwards, mSize - 1);
		}


		LinkedListIterator end() const
		{
			Node* e = new Node;
			e->mNext = nullptr;
			e->mPrevious = nullptr;
			e->mData = mEnd->mData;
			LinkedListIterator temp(e, LinkedListIteratorType::forward);
			return temp;
		}

		LinkedListIterator begin() const
		{
			return LinkedListIterator(mStart);
		}

		/// <summary>
		/// Returns a special value indicating we're done iterating backwards or that this iterator is invalid
		/// </summary>
		/// <returns>A special end value for backwards iteration</returns>
		LinkedListIterator rend() const
		{
			return LinkedListIterator(this, LinkedListIteratorType::backwards, -1);
		}

		/// <summary>
		/// Searches through a linked list and removes the first node that contains the same value given
		/// </summary>
		/// <param name="val"></param>
		void remove(const T& val) {
			Node* cur_node = mStart;

			int found = 0;

			for (unsigned int i = 0; i < mSize; i++)
			{
				T temp = at(i);
				if (temp == val) {
					found = 1;
					break;
				}
				cur_node = cur_node->mNext;
			}
			if (found == 1) {
				if (cur_node != mStart)
					cur_node->mPrevious->mNext = cur_node->mNext;
				if (cur_node != mEnd)
					cur_node->mNext->mPrevious = cur_node->mPrevious;
				delete cur_node;
				mSize--;
			}
			

			

		}
		
		/// <summary>
		/// Same as remove but for every node with the matching value
		/// </summary>
		/// <param name="val"></param>
		void remove_all(const T& val) {

			Node* cur_node = mStart;
			while (cur_node != nullptr)
			{
				if (cur_node->mData == val) {
					cur_node = remove_internal(cur_node);
					mSize--;
				}
				else {
					// not one to delete -- move on.
					cur_node = cur_node->mNext;
				}
			}
		}


		T& operator[](int index) const
		{
			Node* cur_node = mStart;
			for (unsigned int i = 0; i > index; i++) {
				cur_node = cur_node->mNext;
			}
			return cur_node->mData;
		}

		/// <summary>
		/// Finds the value in the node at the location given in a linked list and returns it
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		T& at(const unsigned int index) const
		{
			if (index >= mSize)
				throw std::out_of_range("Invalid index (" + std::to_string(index) + ")");
			Node* cur_node = mStart;
			for (unsigned int i = 0; i < index; i++) {
				cur_node = cur_node->mNext;
			}
			return cur_node->mData;
		}
		
		LinkedListIterator& operator=(const LinkedListIterator& other)
		{
			for (T val : other) {
				this->append(val);
			}
		}

		
		/// <summary>
		/// Initializer list constructor
		/// </summary>
		/// <param name="ilist"></param>
		LinkedList(std::initializer_list<T> ilist)
		{
			for (T val : ilist) {
				this->append(val);
			}
		}


		

	};

}
