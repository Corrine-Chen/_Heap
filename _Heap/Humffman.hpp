
#include "_Heap.hpp"

template<class T>
struct Node
{
	Node(const T& weight, const T data = T())
		: _weight(weight)
		, _pLeft(NULL)
		, _pRight(NULL)
	{}

	Node<T>* _pLeft;
	Node<T>* _pRight;
	T _weight;   //   权值
	T _data;
};
template <class T>
struct ComplareNode//注意堆的比较器比较不了此处的两个指针，故需要重新写比较器
{
	 bool operator()(Node<T>* pLeft,Node<T>* pRight)
    {
        return pLeft->_weight<pRight->_weight;
    }
};
template<class T>
class HuffmanTree
{
public:
	HuffmanTree()
		: _pRoot(NULL)
	{}

	HuffmanTree(const T array[], size_t size)
	{
		_Create(array, size);
	}

protected:
	void _Create(const T array[], size_t size)
	{
		Heap<Node<T>*,ComplareNode<T>> hp;//创建一个堆，用来存放森林

        for(size_t idx=0; idx<size; ++idx)//将权值转化为节点存入堆中
        {
            hp.Insert(new Node<T>(array[idx]));
        }
     
        while(hp.Size()>1)
        {
            Node<T>* pLeft = hp.Top();//在堆中选取两个最小权值的节点，作为左右孩子组建成新的树
            hp.Remove();
            Node<T>* pRight = hp.Top();
            hp.Remove();

            Node<T>* pParent = new Node<T>(pLeft->_weight+pRight->_weight);
            pParent->_pLeft = pLeft;
            pParent->_pRight = pRight;

            hp.Insert(pParent);//将树放入森林
        }
        _pRoot = hp.Top();
	}

protected:
	Node<T>* _pRoot;
};


void Funtest()
{
	int array[] = {7,5,3,1};
	HuffmanTree<int> h(array, sizeof(array)/sizeof(array[0]));
}


