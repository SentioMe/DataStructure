#pragma once
#include "IEnumrable.h"
#include "..\Utility\CommonUtil.h"
#include <iostream>

namespace SALibrary
{
	template<class T>
	class LinkedList;

	template<class T>
	class LinkedListNode sealed
	{
		friend class LinkedList<T>;
	private:
		T _value;
		LinkedListNode* _prev;
		LinkedListNode* _next;

	public:
		LinkedListNode(const T& value)
			: _value(value), _prev(nullptr), _next(nullptr)
		{
		}
		LinkedListNode(const T& value, LinkedListNode* prev, LinkedListNode* next)
			: _value(value), _prev(prev), _next(next)
		{
		}
		~LinkedListNode(void)
		{
			_prev = nullptr;
			_next = nullptr;
		}

	private:
		LinkedListNode* AddAfter(const T& value, bool isForce)
		{
			if (isForce)
			{
				auto newNode = new LinkedListNode(value, this, _next);
				if (_next != nullptr)
					_next->_prev = newNode;

				this->_next = newNode;
			}
			else
			{
				if (_next != nullptr)
					return _next->AddAfter(value, isForce);

				_next = new LinkedListNode(value, this, nullptr);
			}

			return _next;
		}
		LinkedListNode* AddBefore(const T& value, bool isForce)
		{
			if (isForce)
			{
				auto newNode = new LinkedListNode(value, _prev, this);
				if (_prev != nullptr)
					_prev->_next = newNode;

				this->_prev = newNode;
			}
			else
			{
				if (_prev != nullptr)
					return _prev->AddBefore(value, isForce);

				_prev = new LinkedListNode(value, nullptr, this);
			}

			return _prev;
		}
		bool Remove(const T& value)
		{
			if (_value == value)
			{
				if (_prev != nullptr)
					_prev->_next = this->_next;
				if (_next != nullptr)
					_next->_prev = this->_prev;

				delete this;
				return true;
			}

			return (_next != nullptr) ? _next->Remove(value) : false;
		}
		void RemoveAfter(bool isForce)
		{
			if (isForce)
			{
				LinkedListNode* node = (_next != nullptr) ? _next->_next : nullptr;
				
				if (node != nullptr)
					node->_prev = this;

				delete _next;
				_next = node;
			}
			else
			{
				if (_next != nullptr)
					_next->RemoveAfter(isForce);
				else
				{
					if (_prev != nullptr)
						_prev->_next = nullptr;

					delete this;
				}
			}
		}
		void RemoveBefore(bool isForce)
		{
			if (isForce)
			{
				LinkedListNode* node = (_prev != nullptr) ? _prev->_prev : nullptr;

				if (node != nullptr)
					node->_next = this;

				Terminate(&_prev);
				_prev = node;
			}
			else
			{
				if (_prev != nullptr)
					_prev->RemoveBefore(isForce);
				else
				{
					if (_next != nullptr)
						_next->_prev = nullptr;

					delete this;
				}
			}
		}
	};

	template<class T>
	class LinkedList
	{
	private:
		LinkedListNode<T>* _head;

	public:
		LinkedList(void)
			: _head(nullptr)
		{
		}
		~LinkedList(void)
		{
			this->Clear();
		}

		void AddLast(const T& value)
		{
			if (_head == nullptr)
				_head = new LinkedListNode<T>(value);
			else
				_head->AddAfter(value, false);

		}
		void AddFirst(const T& value)
		{
			_head = (_head == nullptr) ? new LinkedListNode<T>(value) : _head->AddBefore(value, false);
		}
		bool Remove(const T& value)
		{
			if (_head == nullptr)
				return false;

			if (_head->_value == value)
			{
				auto node = _head;
				_head = _head->_next;
				_head->_prev = nullptr;
				
				delete node;
				return true;
			}

			return _head->Remove(value);
		}

		void Clear()
		{
			if (_head == nullptr)
				return;

			LinkedListNode<T>* node = _head;
			LinkedListNode<T>* next = node->_next;

			while (_head->_next != nullptr)
				_head->RemoveAfter(false);

			delete _head;
			_head = nullptr;
		}
		void Print()
		{
			int i = 0;
			for (auto node = _head; node != nullptr; node = node->_next)
				std::cout << "[" << i++ << "] = " << node->_value << ",";
		}
	};

}