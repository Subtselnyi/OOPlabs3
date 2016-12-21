#ifndef COLLECTION_H
#define COLLECTION_H

template<class... Infos>

class Collection : public Infos... // наследуем базовые классы, они же

{

    public:

        Collection(){};

        Collection(const Infos&&... infos) : Infos(infos)... {}; //

};
#endif // COLLECTION_H
