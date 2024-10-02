#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H
#include <string>

class Identifiable
{
    public:
        Identifiable();
        virtual ~Identifiable();
        virtual std::string getID() const = 0;
        virtual void setID (const std::string&) = 0;
};

#endif // IDENTIFIABLE_H
