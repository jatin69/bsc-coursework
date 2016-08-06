#ifndef CONVERTPOSTFIX_H
#define CONVERTPOSTFIX_H


class ConvertPostfix
{
public:
        ConvertPostfix();
    bool is_operator(char );
    bool is_operand(char );
    bool checkPrepost(char, char );                //returns true if precedence of op1 > op2
    char* infix_to_postfix(char* );
    char* postfix_to_infix(char* );
    int postfixEva(char*);
    int performOp( int ,int, char);
    int getvalue(char );
    protected:
    private:

};

#endif // CONVERTPOSTFIX_H
