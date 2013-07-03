#include "Node.h"

class Tree
{
    public:
        Tree(std::unique_ptr< QList<QString> > names);
        ~Tree();
        void show (QGraphicsScene* scene, QGraphicsView* view) const;
    private:
        Node* mRootNode = 0;
        void printTree (const Node* node, QString indent) const;
};
