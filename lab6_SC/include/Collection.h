#ifndef COLLECTION_H
#define COLLECTION_H

template<class... Infos>

class Collection : public Infos... // ��������� ������� ������, ��� ��

{

    public:

        Collection(){};

        Collection(const Infos&&... infos) : Infos(infos)... {}; //

};
#endif // COLLECTION_H
