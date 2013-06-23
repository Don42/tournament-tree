#ifndef NODE
#define NODE

#include <memory>
#include <QString>
#include <QList>

class Node
{
    public:
        Node (QString);
        Node (Node*, Node*);
        ~Node ();
        Node* getLeft() const;
        Node* getRight() const;
        QString getName() const;
    private:
        Node* mLeft;
        Node* mRight;
        QString mName;
};

Node* buildTree (std::auto_ptr< QList<QString> > list);
int randInt (int low, int high);

void printTree (const Node* node, QString indent);

#endif
