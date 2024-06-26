// #include "BinaryNode.h"

namespace dats
{
///////////////////////////////////////////////////////////////////////////
// BinaryNode::BinaryNode()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>::BinaryNode(T t) : m_value(t), m_left(nullptr), m_right(nullptr)
{
}

///////////////////////////////////////////////////////////////////////////
// BinaryNode::BinaryNode()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>::BinaryNode(T t, BinaryNode* left, BinaryNode* right)
    : m_value(t), m_left(left), m_right(right)
{
}

///////////////////////////////////////////////////////////////////////////
// BinaryNode::getValue()
///////////////////////////////////////////////////////////////////////////
template <typename T>
T& BinaryNode<T>::getValue()
{
    return m_value;
}

///////////////////////////////////////////////////////////////////////////
// BinaryNode::setValue()
///////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryNode<T>::setValue(T t)
{
    m_value = t;
}

///////////////////////////////////////////////////////////////////////////
// BinaryNode::getLeftChild()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>*& BinaryNode<T>::getLeftChild()
{
    return m_left;
}

///////////////////////////////////////////////////////////////////////////
// BinaryNode::setLeftChild()
///////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryNode<T>::setLeftChild(BinaryNode<T>* left)
{
    m_left = left;
}

///////////////////////////////////////////////////////////////////////////
// BinaryNode::getRightChild()
///////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryNode<T>*& BinaryNode<T>::getRightChild()
{
    return m_right;
}

///////////////////////////////////////////////////////////////////////////
// BinaryNode::setRightChild()
///////////////////////////////////////////////////////////////////////////
template <typename T>
void BinaryNode<T>::setRightChild(BinaryNode<T>* right)
{
    m_right = right;
}

} // namespace dats
