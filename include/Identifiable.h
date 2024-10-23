#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H
#include <string>

class Identifiable
{
    public:
        Identifiable();
        virtual ~Identifiable();
        virtual const std::string &GetID() const = 0;
        virtual void SetID (const std::string&) = 0;
};

#endif // IDENTIFIABLE_H
