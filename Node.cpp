#include <stdlib.h>
#include <iostream>
#include <QDebug>
#include <QByteArray>
#include <QTextStream>
#include "Node.h"

Node::Node (QString name)
    :mName (name)
{
    mLeft = NULL;
    mRight = NULL;
}

Node::Node (Node* left, Node* right)
    :mName ("")
{
    mLeft = left;
    mRight = right;
}

Node::~Node ()
{
    if (mLeft != NULL)
    {
        delete mLeft;
    }

    if (mRight != NULL)
    {
        delete mRight;
    }
}

Node* Node::getLeft () const
{
    return mLeft;
}

Node* Node::getRight () const
{
    return mRight;
}

QString Node::getName () const
{
    return mName;
}
