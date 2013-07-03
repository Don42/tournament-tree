#ifndef NODE
#define NODE

#include <memory>
#include <QString>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QProcess>

class Node
{
    public:
        Node (QString);
        Node (Node*, Node*);
        ~Node ();
        Node* getLeft () const;
        Node* getRight () const;
        QString getName () const;
        void show (QGraphicsScene* scene, QGraphicsView* view) const;
    private:
        Node* mLeft = 0;
        Node* mRight = 0;
        QString mName;
};

#endif
