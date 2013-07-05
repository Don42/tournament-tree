#include <stdlib.h>
#include <QDebug>
#include "Tree.h"

Node* buildTreeWithLoserBracket (std::unique_ptr< QList<QString> > list);
int randInt(int low, int high);

Tree::Tree (std::unique_ptr< QList<QString> > names)
{
    mRootNode = buildTreeWithLoserBracket (std::move(names));
}

Tree::~Tree ()
{
    if (mRootNode)
    {
        delete mRootNode;
    }
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

Node* buildTreeWithLoserBracket (std::unique_ptr< QList<QString> > list)
{
    if (list->size() == 1)
    {
        return new Node (list->at(0));
    }
    std::unique_ptr< QList<QString> > leftList (new QList<QString>());
    std::unique_ptr< QList<QString> > rightList (new QList<QString>());
    while (list->size() >= 2)
    {
        leftList->append (list->takeAt (randInt (0, list->size() - 1)));
        rightList->append (list->takeAt (randInt (0, list->size() - 1)));
    }
    if (list->size() > 0)
    {
        leftList->append (list->takeAt (0));
    }
    return new Node (buildTreeWithLoserBracket (std::move (leftList)),
                        buildTreeWithLoserBracket (std::move (rightList)));
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

void Tree::show (QGraphicsScene* scene, QGraphicsView* view) const
{
    QProcess* p = new QProcess;
    QByteArray a = prepareGraph (this->mRootNode);

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

    pixmap.loadFromData (data);

    scene->addPixmap (pixmap);
    view->show ();
}

int randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}
