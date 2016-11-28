#ifndef UEXCEPTION_H
#define UEXCEPTION_H


class UException
{
    private:
        char* msg;
    public:
        UException(char* message);
        ~UException();

        void show(void);
};

#endif // UEXCEPTION_H
