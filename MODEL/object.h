#ifndef OBJECT_H
#define OBJECT_H

#include "status.h"
//ho dovuto creare questa classe per avere possibilità di fare rtti nella funzione esegui resente in businesslogic, altrimenti mi sarebbe stato impossibile
class Object
{
public:
    virtual ~Object();
    virtual Status getStatus() const;
};

#endif // OBJECT_H
