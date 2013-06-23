#include <stdlib.h>
#include <QDebug>
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


Node* buildTree (std::auto_ptr< QList<QString> > list)
{
    if (list->size() == 1)
    {
        return new Node (list->at(0));
    }
    std::auto_ptr< QList<QString> > leftList (new QList<QString>());
    std::auto_ptr< QList<QString> > rightList (new QList<QString>());
    while (list->size() >= 2)
    {
        leftList->append (list->takeAt (randInt (0, list->size() - 1)));
        rightList->append (list->takeAt (randInt (0, list->size() - 1)));
    }
    if (list->size() > 0)
    {
        leftList->append (list->takeAt (0));
    }
    return new Node (buildTree  (leftList), buildTree (rightList));
}


int randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void printTree (const Node* node, QString indent)
{
    if (node != NULL)
    {
        QString newIndent = indent + "--------";
        qDebug () << indent << node->getName();
        printTree(node->getLeft(), newIndent);
        printTree(node->getRight(), newIndent);
    }
}
