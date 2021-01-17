#include "./Quaternion.h"

void IM::Quaternion::print() {
    switch (this->flag) {
    case 0: {
        std::cout << this->__op_str__() << "\t" << this->args[0].literal << "\t" << this->args[1].literal << "\t" << this->args[2].literal << std::endl;
        break;
    }
    case 1: {
        if (args[0].var == NULL) std::cout << this->__op_str__() << "\t-\t" << this->args[1].literal << "\t" << this->args[2].literal << std::endl;
        else std::cout << this->__op_str__() << "\t" << this->args[0].var->getName() << "\t" << this->args[1].literal << "\t" << this->args[2].literal << std::endl;
        break;
    }
    case 2: {
        if (args[1].var == NULL) std::cout << this->__op_str__() << "\t" << this->args[0].literal << "\t" << this->args[1].var->getName() << "\t" << this->args[2].literal << std::endl;
        else std::cout << this->__op_str__() << "\t" << this->args[0].literal << "\t-\t" << this->args[2].literal << std::endl;
        break;
    }
    case 3: {
        if (args[0].var == NULL) {
            if (args[1].var == NULL) std::cout << this->__op_str__() << "\t-\t-\t" << this->args[2].literal << std::endl;
            else std::cout << this->__op_str__() << "\t-\t" << this->args[1].var->getName() << "\t" << this->args[2].literal << std::endl;
        } else {
            if (args[1].var == NULL) std::cout << this->__op_str__() << "\t" << this->args[0].var->getName() << "\t-\t" << this->args[2].literal << std::endl;
            else std::cout << this->__op_str__() << "\t" << this->args[0].var->getName() << "\t" << this->args[1].var->getName() << "\t" << this->args[2].literal << std::endl;
        }
        break;
    }
    case 4: {
        if (args[2].var == NULL) std::cout << this->__op_str__() << "\t" << this->args[0].literal << "\t" << this->args[1].literal << "\t-" << std::endl;
        else std::cout << this->__op_str__() << "\t" << this->args[0].literal << "\t" << this->args[1].literal << "\t" << this->args[2].var->getName() << std::endl;
        break;
    }
    case 5: {
        if (args[0].var == NULL) std::cout << this->__op_str__() << "\t-\t" << this->args[1].literal << "\t";
        else std::cout << this->__op_str__() << "\t" << this->args[0].var->getName() << "\t" << this->args[1].literal << "\t";
        if (args[2].var == NULL) std::cout << "-" << std::endl;
        else std::cout << this->args[2].var->getName() << std::endl;
        break;
    }
    case 6: {
        if (args[1].var == NULL) std::cout << this->__op_str__() << "\t" << this->args[0].literal << "\t-\t";
        else std::cout << this->__op_str__() << "\t" << this->args[0].literal << "\t" << this->args[1].var->getName() << "\t";
        if (args[2].var == NULL) std::cout << "-" << std::endl;
        else std::cout << this->args[2].var->getName() << std::endl;
        break;
    }
    case 7: {   
        if (args[0].var == NULL) std::cout << this->__op_str__() << "\t-\t";
        else std::cout << this->__op_str__() << "\t" << this->args[0].var->getName() << "\t";
        if (args[1].var == NULL) std::cout << "-\t";
        else std::cout << this->args[1].var->getName() << "\t";
        if (args[2].var == NULL) std::cout << "-" << std::endl;
        else std::cout << this->args[2].var->getName() << std::endl;
        break;
    }
    default:
        break;
    }
}