#ifndef DEQUE_H_
#define DEQUE_H_

#include "iostream"

using namespace std;

/* Forward declararations */
template<typename TN> class Node;
template<typename TN> class Deque;

template<typename TN>
class Node
{
    public:
        Node<TN> *mNext;
        Node<TN> *mPrev;
        TN* mDataPtr;
        Node(TN *dataPtrParam);
};

template<typename TN>
Node<TN>::Node(TN *dataPtrParam)
{
    this->mNext = NULL;
    this->mPrev = NULL;
    mDataPtr = dataPtrParam;
}

template<typename TN>
class Deque
{
public:
    Deque();
    ~Deque();

    /* Cheking status of the queue*/
    bool empty();
    long size();
    void clear();
    
    /* Initializing and resizing*/
    void resize(long newSizeParam, TN* dataPtrParam[], int directionParam);

    /* Deque Operations*/
    /* The Object is allocated and pushed inside the Deque Node as Object */
    void pushBack(TN* dataPtrParam);
    void pushFront(TN* dataPtrParam);
    /* It is application/user responsibility to free the object returned */
    TN*  popBack();
    TN*  popFront();

    /* Getters */
    TN* front();
    TN* back();
    
    /* Overloading operators */
    TN* operator[](long postionParam);

protected:
    /* A function to debug if needed, dump all the node information */
    void pPrintAllNodeInfo();
    /* Member vaiables to maintain the Deque. */
    Node<TN>* mFrontPtr;
    Node<TN>* mRearPtr;
    long mCurrentSize;
 
};

template<typename TN>
TN* Deque<TN>::operator[](long postionParam)
{
    Node<TN>* sTempPtr = NULL;
    if(postionParam>=0)
    {
        if(postionParam < mCurrentSize)
        {
            sTempPtr = mFrontPtr;
            for(int i = 0;i<postionParam;i++)
            {
                if(sTempPtr)
                {
                    sTempPtr = sTempPtr->mNext;
                }
            }
        }
    }
    else
    {
        postionParam = postionParam * -1;
        if(postionParam <= mCurrentSize)
        {
            for(int i = 0;i<postionParam;i++)
            {
                if(sTempPtr)
                {
                    sTempPtr = sTempPtr->mPrev;
                }
                else
                {
                    sTempPtr = mRearPtr;
                }
            }
        }
    }

    if(sTempPtr)
    {
        return sTempPtr->mDataPtr;
    }
    else
    {
        return NULL;
    }
}

template<typename TN>
Deque<TN>::Deque()
{
    mCurrentSize = 0;
    mFrontPtr = mRearPtr =  NULL;
}

template<typename TN>
Deque<TN>::~Deque()
{
    Node<TN>* sTempPtr = mFrontPtr;
    
    while(sTempPtr!=NULL)
    {
        Node<TN>* sTempNextPtr = sTempPtr->mNext;
        delete sTempPtr->mDataPtr;
        delete sTempPtr;
        sTempPtr = sTempNextPtr;
    }

    mCurrentSize =0;
    mFrontPtr = mRearPtr =  NULL;
}

template<typename TN>
void Deque<TN>::resize(long newSizeParam, TN* dataPtrParam[], int directionParam)
{
    long sCount = newSizeParam - mCurrentSize;
   
    if(newSizeParam < 0 || sCount == 0)
    {
        cout<<"***\nNew size either negative or Same as current size\n***"<<endl;
        return;
    }

    if(sCount>0)
    {
        /* Here we need to add elements */
        if(directionParam>0)
        {
            for(int itr = 0;itr<newSizeParam;itr++)
            {
                pushBack(*dataPtrParam[itr]);
            }
        }
        else
        {
            for(int itr = 0;itr<newSizeParam;itr++)
            {
                pushFront(*dataPtrParam[itr]);
            }
        }
    }
    else
    {
        sCount = sCount * (-1);
        if(mCurrentSize != 0)
        {
            /* These are are number of elements to drop from  */
            if(directionParam>0)
            {
                /* drop elemets at end. */
                while(mCurrentSize-newSizeParam>0)
                {
                    TN* sDataPtr = popBack();
                    cout<<"Data popped from back = ";
                    cout<<*sDataPtr;
                    if(sDataPtr)
                    {
                        delete sDataPtr;
                    }
                    cout<<endl;
                    sCount--;
                } 
            }
            else
            {
                /* drop elements at beginning */
                while(mCurrentSize-newSizeParam>0)
                {
                    TN* sDataPtr = popFront();
                    cout<<"Data popped from front = ";
                    cout<<*sDataPtr;
                    if(sDataPtr)
                    {
                        delete sDataPtr;
                    }
                    cout<<endl;
                    sCount--;
                }
            }
        }
    }
}

template<typename TN>
bool Deque<TN>::empty()
{
    if(mFrontPtr == NULL){
        return true;
    }
    else
        return false;
}

template<typename TN>
long Deque<TN>::size()
{
    return mCurrentSize;
}

template<typename TN>
TN* Deque<TN>::front()
{
    if(!empty())
        return mFrontPtr->mDataPtr;
    else
        return NULL;
}

template<typename TN>
TN* Deque<TN>::back()
{
    if(!empty())
        return mRearPtr->mDataPtr;
    else
        return NULL;
}

template<typename TN>
void Deque<TN>::pushBack(TN* dataPtrParam)
{
    Node<TN> *sNewNodePtr = new Node<TN>(dataPtrParam);
    /*Empty Deque*/
    if(mFrontPtr == NULL)
    {
        mFrontPtr = mRearPtr = sNewNodePtr;
    }
    else
    {
        sNewNodePtr->mPrev = mRearPtr;
        mRearPtr->mNext = sNewNodePtr;
        mRearPtr = sNewNodePtr;
    }
    mCurrentSize++;
}

template<typename TN>
void Deque<TN>::pushFront(TN* dataPtrParam)
{
    Node<TN> *sNewNodePtr = new Node<TN>(dataPtrParam);
    /*Empty Deque*/
    if(mFrontPtr == NULL)
    {
        mFrontPtr = mRearPtr = sNewNodePtr;
    }
    else
    {
        sNewNodePtr->mNext = mFrontPtr;
        mFrontPtr->mPrev = sNewNodePtr;
        mFrontPtr = sNewNodePtr;
    }
    mCurrentSize++;
}

template<typename TN>
TN* Deque<TN>::popBack()
{
    TN* sRetDequeObjPtr = NULL;
    
    if(empty())
    {
        cout<<"Deque is Empty so cannot pop the element from back"<<endl;
    }
    else if(mFrontPtr == mRearPtr) /* Only one node exists */
    {
        sRetDequeObjPtr = mRearPtr->mDataPtr;
        delete mRearPtr;
        mFrontPtr = mRearPtr = NULL;
        mCurrentSize--;
    }
    else
    {
        sRetDequeObjPtr = mRearPtr->mDataPtr;
        Node<TN>* temp = mRearPtr;
        mRearPtr = mRearPtr->mPrev;
        mRearPtr->mNext = NULL;
        delete temp;
        mCurrentSize--;
    }

    return sRetDequeObjPtr;
}

template<typename TN>
TN* Deque<TN>::popFront()
{
    TN* sRetDequeObjPtr = NULL;

    if(empty())
    {
        cout<<"Deque is Empty so cannot pop the element from front"<<endl;
    }
    else if(mFrontPtr == mRearPtr) /* Only one node exists */
    {
        sRetDequeObjPtr = mFrontPtr->mDataPtr;
        delete mFrontPtr;
        mFrontPtr = mRearPtr = NULL;
        mCurrentSize--;
    }
    else
    {
        sRetDequeObjPtr = mFrontPtr->mDataPtr;
        Node<TN>* temp = mFrontPtr;
        mFrontPtr = mFrontPtr->mNext;
        mFrontPtr->mPrev = NULL;
        delete temp;
        mCurrentSize--;
    }
    return sRetDequeObjPtr;
}

template<typename TN>
void Deque<TN>::clear()
{
    cout<<"\n ******* Clearing deque ******* \n"<<endl;
    resize(0, NULL, 1);
    mCurrentSize = 0;
}

template<typename TN>
void Deque<TN>::pPrintAllNodeInfo()
{
    Node<TN>* temp = mFrontPtr;
    if(!temp)
        return;
    long count=0;
    cout<<"\n ******* All Nodes in Allocated DLL Deque ******* \n"<<endl;

   do
   {
       cout<<count++<<".) "<<temp->mDataPtr<<" temp = "<<temp<<" mPrev = "<<temp->mPrev<<" mNext = "<<temp->mNext<<endl;
       temp = temp->mNext;
   } while(temp != NULL);
    cout<<"\n******* End of information ******* \n"<<endl;
}

#endif

