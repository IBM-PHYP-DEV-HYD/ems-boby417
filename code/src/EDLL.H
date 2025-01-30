#ifndef EDLL_H
#define EDLL_H

#include "Deque.H"

template<typename TN>
class EDLL : public Deque<TN>
{
public:
    EDLL(){}
    void addElementAtPosition(int posParam, TN* elementPtrParam);
    /*It responsibility of user to delete returned pointer*/
    TN* removeElementAtPosition(int posParam);

    Node<TN>* getNodeAtPosition(int posParam);

};

template<typename TN>
Node<TN>* EDLL<TN>::getNodeAtPosition(int posParam)
{
    Node<TN>* sTempPtr = this->mFrontPtr;
    for(int i = 0;i<posParam;i++)
    {
        if(sTempPtr)
        {
            sTempPtr = sTempPtr->mNext;
        }
    }
    return sTempPtr;
}

template<typename TN>
void EDLL<TN>::addElementAtPosition(int posParam, TN* elementPtrParam)
{
    
    if(posParam > this->mCurrentSize || posParam < 0)
    {
        cout<<"Invalid position parameter"<<endl;
    }
    else if(posParam == this->mCurrentSize) //add in the Rear of Deque
    {
        this->pushBack(elementPtrParam);
    }
    else if(posParam == 0) // Add in the Front of Deque
    {
        this->pushFront(elementPtrParam);
    }
    else // Add at position
    {
        Node<TN>* sNewNodePtr = new Node<TN>(elementPtrParam);
        Node<TN>* sTempNodePtr = getNodeAtPosition(posParam-1);
        sNewNodePtr->mNext = sTempNodePtr->mNext;
        sNewNodePtr->mPrev = sTempNodePtr;
        sTempNodePtr->mNext = sNewNodePtr;
        sNewNodePtr->mNext->mPrev = sNewNodePtr;
        this->mCurrentSize++;
    }

    return;
}

template<typename TN>
TN* EDLL<TN>::removeElementAtPosition(int posParam)
{
    TN *sDataPtr = NULL;
    if(posParam >= this->mCurrentSize || posParam < 0) // Invalid position
    {
        cout<<"Position parameter is invalid"<<endl;
    }
    else
    {
        if(posParam == 0)
        {
            sDataPtr = this->popFront();
        }
        else if(posParam == this->mCurrentSize-1)
        {
            sDataPtr = this->popBack();
        }
        else
        {
            Node<TN>* sTempNodePtr = getNodeAtPosition(posParam);
            sTempNodePtr->mPrev->mNext = sTempNodePtr->mNext;
            sTempNodePtr->mNext->mPrev = sTempNodePtr->mPrev;
            sDataPtr = sTempNodePtr->mDataPtr;
            delete sTempNodePtr;
            this->mCurrentSize--;
        }
    }
    return sDataPtr;
}

#endif // EDLL_H