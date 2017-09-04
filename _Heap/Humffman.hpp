
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
	T _weight;   //   Ȩֵ
	T _data;
};
template <class T>
struct ComplareNode//ע��ѵıȽ����Ƚϲ��˴˴�������ָ�룬����Ҫ����д�Ƚ���
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
		Heap<Node<T>*,ComplareNode<T>> hp;//����һ���ѣ��������ɭ��

        for(size_t idx=0; idx<size; ++idx)//��Ȩֵת��Ϊ�ڵ�������
        {
            hp.Insert(new Node<T>(array[idx]));
        }
     
        while(hp.Size()>1)
        {
            Node<T>* pLeft = hp.Top();//�ڶ���ѡȡ������СȨֵ�Ľڵ㣬��Ϊ���Һ����齨���µ���
            hp.Remove();
            Node<T>* pRight = hp.Top();
            hp.Remove();

            Node<T>* pParent = new Node<T>(pLeft->_weight+pRight->_weight);
            pParent->_pLeft = pLeft;
            pParent->_pRight = pRight;

            hp.Insert(pParent);//��������ɭ��
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


