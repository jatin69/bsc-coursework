#ifndef CONVERTPREFIX_H
#define CONVERTPREFIX_H


class ConvertPrefix
{
    public:
        ConvertPrefix();

    bool is_operator(char );
    bool is_operand(char );

    bool checkPre(char, char );                //returns true if precedence of op1 > op2

    char* infix_to_prefix(char* );
    char* prefix_to_infix(char* );

};

#endif // CONVERTPREFIX_H
