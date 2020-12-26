#include "./Quaternion.h"

std::string IM::Quaternion::__str__() {
    switch (this->op)
    {
    case OperatorCode::JUMP:
        return "     JUMP     ";
    case OperatorCode::JUMP_SMALL:
        return "  JUMP_SMALL  ";
    case OperatorCode::JUMP_EQ_SMALL:
        return "JUMP_EQ_SMALL ";
    case OperatorCode::JUMP_GREAT:
        return "  JUMP_GREAT  ";
    case OperatorCode::JUMP_EQ_GREAT:
        return "JUMP_EQ_GREAT ";
    case OperatorCode::JUMP_EQUAL:
        return "  JUMO_EQUAL  ";
    case OperatorCode::JUMP_NOT_EQUAL:
        return "JUMP_NOT_EQUAL";
    case OperatorCode::PLUS:
        return "     PLUS     ";
    case OperatorCode::MINUS:
        return "    MINUS     ";
    case OperatorCode::TIMES:
        return "    TIMES     ";
    case OperatorCode::DIV:
        return "     DIV      ";
    case OperatorCode::MOD:
        return "     MOD      ";
    case OperatorCode::POWER:
        return "    POWER     ";
    case OperatorCode::NEGATIVE:
        return "   NEGATIVE   ";
    case OperatorCode::ASSIGN:
        return "    ASSIGN    ";
    case OperatorCode::ASSIGN_ARRAY:
        return " ASSIGN_ARRAY ";
    case OperatorCode::ASSIGN_STRUCT:
        return "ASSIGN_STRUCT ";
    case OperatorCode::GET_ADDRESS:
        return " GET_ADDRESS  ";
    case OperatorCode::ASSIGN_POINTER:
        return "ASSIGN_POINTER";
    case OperatorCode::PARAM:
        return "    PARAM     ";
    case OperatorCode::CALL:
        return "     CALL     ";
    case OperatorCode::RETURN:
        return "    RETURN    ";
    case OperatorCode::FUNC_DEF:
        return "   FUNC_DEF   ";
    case OperatorCode::END_FUNCTION:
        return " END_FUNCTION ";
    case OperatorCode::LABEL:
        return "     LABEL    ";
    case OperatorCode::GET_VALUE:
        return "  GET_VALUE   ";
    case OperatorCode::GET_ARRAY:
        return "  GET_ARRAY   ";
    case OperatorCode::GET_STRUCT:
        return "  GET_STRUCT  ";
    case OperatorCode::NONE:
        return "     NONE     ";
    default:
        break;
    }
}

void IM::Quaternion::print() {
    switch (this->flag)
    {
    case 0:
    {
        std::cout << this->__str__() << "\t" << this->args[0].literal << "\t" << this->args[1].literal << "\t" << this->args[2].literal << std::endl;
        break;
    }
    case 1:
    {
        if (args[0].var == NULL)
            std::cout << this->__str__() << "\t-\t" << this->args[1].literal << "\t" << this->args[2].literal << std::endl;
        else
            std::cout << this->__str__() << "\t" << this->args[0].var->getName() << "\t" << this->args[1].literal << "\t" << this->args[2].literal << std::endl;
        break;
    }
    case 2:
    {
        if (args[1].var == NULL)
            std::cout << this->__str__() << "\t" << this->args[0].literal << "\t" << this->args[1].var->getName() << "\t" << this->args[2].literal << std::endl;
        else
            std::cout << this->__str__() << "\t" << this->args[0].literal << "\t-\t" << this->args[2].literal << std::endl;
        break;
    }
    case 3:
    {
        if (args[0].var == NULL)
        {
            if (args[1].var == NULL)
                std::cout << this->__str__() << "\t-\t-\t" << this->args[2].literal << std::endl;
            else
                std::cout << this->__str__() << "\t-\t" << this->args[1].var->getName() << "\t" << this->args[2].literal << std::endl;
        }
        else
        {
            if (args[1].var == NULL)
                std::cout << this->__str__() << "\t" << this->args[0].var->getName() << "\t-\t" << this->args[2].literal << std::endl;
            else
                std::cout << this->__str__() << "\t" << this->args[0].var->getName() << "\t" << this->args[1].var->getName() << "\t" << this->args[2].literal << std::endl;
        }
        break;
    }
    case 4:
    {
        if (args[2].var == NULL)
            std::cout << this->__str__() << "\t" << this->args[0].literal << "\t" << this->args[1].literal << "\t-" << std::endl;
        else
            std::cout << this->__str__() << "\t" << this->args[0].literal << "\t" << this->args[1].literal << "\t" << this->args[2].var->getName() << std::endl;
    }
    break;
    case 5:
    {
        if (args[0].var == NULL)
            std::cout << this->__str__() << "\t-\t" << this->args[1].literal << "\t";
        else
            std::cout << this->__str__() << "\t" << this->args[0].var->getName() << "\t" << this->args[1].literal << "\t";

        if (args[2].var == NULL)
            std::cout << "-" << std::endl;
        else
            std::cout << this->args[2].var->getName() << std::endl;
    }
    break;
    case 6:
    {
        if (args[1].var == NULL)
            std::cout << this->__str__() << "\t" << this->args[0].literal << "\t-\t";
        else
            std::cout << this->__str__() << "\t" << this->args[0].literal << "\t" << this->args[1].var->getName() << "\t";
        if (args[2].var == NULL)
            std::cout << "-" << std::endl;
        else
            std::cout << this->args[2].var->getName() << std::endl;
    }
    break;
    case 7:
    {   
        if (args[0].var == NULL)
            std::cout << this->__str__() << "\t-\t";
        else
            std::cout << this->__str__() << "\t" << this->args[0].var->getName() << "\t";
        if (args[1].var == NULL)
            std::cout << "-\t";
        else
            std::cout << this->args[1].var->getName() << "\t";
        if (args[2].var == NULL)
            std::cout << "-" << std::endl;
        else
            std::cout << this->args[2].var->getName() << std::endl;
    }
    default:
        break;
    }
}