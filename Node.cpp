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


void graphWalk (const Node* p, QTextStream* stream, int* emptyNodeCounter)
{
    if (p != NULL)
    {
        QString name (p->getName ());
        if (name.isEmpty())
        {
            name.setNum (*emptyNodeCounter);
            ++(*emptyNodeCounter);
        }
        *stream << "\t\t" << "n" << name <<
            "[label=\"" << name << "\"];" << "\n";

        if (p->getLeft () != NULL)
        {
            QString leftName (p->getLeft ()->getName ());
            if (leftName.isEmpty())
            {
                leftName.setNum (*emptyNodeCounter);
            }
            *stream << "\t\tn" << name << "--" << "n" <<
                leftName << ";" << "\n";
            graphWalk (p->getLeft (), stream, emptyNodeCounter);
        }

        if (p->getRight () != NULL)
        {
            QString rightName (p->getRight ()->getName ());
            if (rightName.isEmpty())
            {
                rightName.setNum (*emptyNodeCounter);
            }
            *stream << "\t\tn" << name << "--" << "n" <<
                rightName << ";" << "\n";
            graphWalk (p->getRight (), stream, emptyNodeCounter);
        }
    }
}


QByteArray prepareGraph (const Node* node)
{
    QByteArray a = QByteArray ();

    QTextStream stream (&a, QIODevice::ReadWrite);
    stream << "graph ""{" << "\n";
    stream << "\tnode[fontsize=10,margin=0,width=\".4\",height=\".3\"];" << "\n";
    stream << "\tsubgraph cluster17{" << "\n";

    int counter = 0;
    graphWalk (node, &stream, &counter);

    stream << "\t}\n" << "}" << "\n";
    stream.flush ();

    return a;
}


void Node::show (QGraphicsScene* scene, QGraphicsView* view) const
{
    QProcess* p = new QProcess;
    QByteArray a = prepareGraph (this);

    qDebug () << a;

    p->setProcessChannelMode (QProcess::MergedChannels);
    p->start ("dot", QStringList () << "-Tpng");
    p->write (a);

    QByteArray data;
    QPixmap pixmap = QPixmap ();

    while (p->waitForReadyRead(100))
    {
        data.append (p->readAll());
    }

    qDebug () << data;
    pixmap.loadFromData (data);

    scene->addPixmap (pixmap);
    view->show ();
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

