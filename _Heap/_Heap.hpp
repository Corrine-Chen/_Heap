
#pragma once

#include<iostream>
using namespace std;
#include <vector>

#include<assert.h>


// 仿函数
template<class T>
struct Less
{
	bool operator()(const T& left, const T& right)
	{
		return left<right;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

template<class T, class Compare = Less<T>>
class Heap
{
public:
        // 创建一个空堆
	Heap()
	{}

	Heap(const T array[], size_t size)
	{
		if(NULL != array && size>0)
		{
			for(int i=0; i<size; ++i)
			{
				_heap.push_back(array[i]);
			}

			for(int i=(size-1)/2; i>=0; --i)
			{
				_AdjustDown(i);
			}
		}
	}
	size_t Size()const
	{
		return _heap.size();
	}
	bool Empty()const
	{
		return _heap.empty();
	}
	void Insert(const T& data) //
	{
		_heap.push_back(data);
		if(_heap.size() == 1)
			return;
		_AdjustUp(_heap.size()-1);
	}
	void Remove()
	{
		assert(!_heap.empty());


		std::swap(_heap[0] , _heap[_heap.size()-1]);
		_heap.pop_back();
		if(_heap.size() == 1)
		{
			return ;
		}
		else
		{
			_AdjustDown(0);
		}
	}
	const T& Top()const
	{
		assert(!Empty());
		return _heap[0];
	}
protected:
	void _AdjustDown(size_t parent)//从下往上调整
	{
		size_t child=0;
		Compare com;
		while(child < _heap.size())
		{
			child = parent * 2 + 1;
			if(child+1 < _heap.size())//有右孩子
			{
				if(com(_heap[child+1] , _heap[child]))
				{
					child+=1;
				}
			}
			if(com(_heap[child] , _heap[parent]))
			{
				std::swap(_heap[child],_heap[parent]);
				parent = child;
				child =parent*2 +1;
			}
			else
			{
				return;
			}
		}
	}


	void _AdjustUp(size_t child)//从上往下调整
	{
		size_t parent;
		parent = (child-1)>>1;
		Compare com;
		while(child >0)
		{	
			if(com(_heap[child] ,_heap[parent]))
			{
				std::swap(_heap[parent] ,_heap[child]);
				child=parent ;
				parent=(child-1)>>1;
			}
			else
			{
				break;
			}
		}
	}

protected:
	std::vector<T> _heap;
};


void FunTest()
{
	int array[] = {53,17,78,9,45,65,87,23};
	Heap<int,Less<int>> hp(array, sizeof(array)/sizeof(array[0]));

//	hp.Insert(16);

 	hp.Remove();
}
/*


template<class T, class Compare = Less<T>>
class PriorityQueue
{
public:
	PriorityQueue()
	{}
	void Push(const T& data)
	{
		_hp.Insert(data);
	}
	void Pop()
	{
		_hp.Remove();
	}
	const T& Top()const
	{
		return _hp.Top();
	}
	size_t Size()const
	{
		return _hp.Size();
	}
	bool Empty()const
	{
		return _hp.Empty();
	}

protected:
	Heap<T, Compare> _hp;
};

void Test()
{
	PriorityQueue<int,Less<int>> q;
	q.Push(53);
	q.Push(17);
	q.Push(78);
	q.Push(9);
	q.Push(45);
	q.Push(65);
	q.Push(87);
	q.Push(23);

	q.Pop();
	

	int size= q.Size();
	bool Bool = q.Empty();
	int top = q.Top();
}
*/
