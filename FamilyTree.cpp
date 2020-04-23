#include "FamilyTree.hpp"

using namespace family;


Tree :: Tree(string name)
{
    root = new Node(name);
    root->setRel("me");
}


Tree &Tree :: addFather(string child, string father)
{
    Node * n = findNode(root, child);

    if (n != NULL)
    {
        if(n->getFather() == NULL)
        {
            Node * f = new Node(father);
            f->setGender("M");
            f->setLevel(n->getLevel()+1);
            f->setRel(f->getGender(), f->getLevel());
            n->setFather(f);
            return *this;
        }
        throw runtime_error("already have a father");
    }
        throw runtime_error("the child doesnt exists");
}

Tree &Tree :: addMother(string child, string mother)
{
    Node * n = findNode(root, child);

    if (n != NULL)
    {
        if(n->getMother() == NULL)
        {
            Node * m = new Node(mother);
            m->setGender("F");
            m->setLevel(n->getLevel()+1);
            m->setRel(m->getGender(), m->getLevel());
            n->setMother(m);
            return *this;
        }
        throw runtime_error("already have a mother");
    }
        throw runtime_error("the child doesnt exists");
}

Node * Tree :: findNode(Node * n, string name)
{
    if(n == NULL)
    {
        return NULL;
    }

    if(n->getName() == name)
    {
        return n;
    }
    Node * father = findNode(n->getFather(), name);

    if(father != NULL)
    {
        return father;
    }
    return findNode(n->getMother(), name);
}

string Tree :: relation(string name)
{
    if(root->getName() == name)
    {
        return "me";
    }

    if(root->getFather() != NULL && root->getFather()->getName() == name)
    {
        return "father";
    }

    if(root->getMother() != NULL && root->getMother()->getName() == name)
    {
        return "mother";
    }
    
    Node * n = Help(root, name,0);

    if(n == NULL)
    {
        return "unrelated";
    }

    int level = n->getLevel();
    string ans = "";
    while(level-- > 3)
    {
        ans += "great-";
    }
    if(n->getGender() == "F")
    {
        ans += "grandmother";
    }
    else
    {
        ans += "grandfather";
    }

    return ans; 
}
Node * Tree :: Help(Node * root, string name, int level)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->getFather() == NULL && root->getMother() == NULL)
    {
        if(root->getName() == name)
        {
            root->setLevel(level + 1); 
            
            return root;
        }
        return NULL;
    }

    if(root->getName() == name)
    {
        root->setLevel(level + 1);
        return root;
    }

    Node * father = Help(root->getFather(), name, level + 1);

    if(father != NULL)
    {
        return father;
    }
    return Help(root->getMother(), name, level + 1);
}

Node * Tree :: relationHelp(Node * n, string relation)
{
     if(n == NULL)
    {
        return NULL;
    }

    if(n->getRel() == relation)
    {
        return n;
    }
    Node * father = relationHelp(n->getFather(), relation);

    if(father != NULL)
    {
        return father;
    }
    return relationHelp(n->getMother(), relation);
}


 string Tree :: find(string name)
 {
    Node* c = relationHelp(root, name);

    if(c!= NULL)
    {
        return c->getName();
    }
    throw std::runtime_error("No such relation!"); 
 }

void Tree :: display()
{
    display(root);
}

void Tree :: display(Node * root)
{
     if(root != NULL)
    {
        display(root->getFather());
        cout << root->getName() << endl;
        display(root->getMother());
    }
    return;
}

void Tree ::remove(string name)
{
    return;
}