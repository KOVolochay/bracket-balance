#include "balance.h"

class c_stack{//создаем свой собственный стек
private:
     char * d;
     int cap;
     int Ind;
public:
     explicit c_stack(int size): d(new char[size]), cap(size), Ind(-1) {}
     ~c_stack(){
          delete[] d;
     }
     c_stack(const c_stack&) = delete;
     c_stack& operator=(const c_stack&) = delete;
     bool empty() const{
          return Ind == -1;
     }
     void push(char v){
          if(Ind + 1 < cap){
               d[++Ind] = v;
          }
     }
     char pop(){
          return d[Ind--];
     }
};
//проверки на то, символ у нас открывающая, закрывающая скобка и являются ли они парой
static bool Op(char c){
     return (c == '(' || c == '[' || c == '{');
}

static bool Cl(char c){
     return (c == ')' || c == ']' || c == '}');
}

static bool m(char o, char c){
     return ((o == '[' && c == ']') || (o == '(' && c == ')') || (o == '{' && c == '}'));
}

bool Balance(const string& in){//в стек отрпавляем открывающую скобку и если видим закрывающую - проверяем, лежит ли у нас такая последней в стеке
     c_stack stack(static_cast<int>(in.size()));
     for(char c: in){
          if(Op(c)){
               stack.push(c);
          }
          else if(Cl(c)){
               if(stack.empty()){
                    return false;
               }
               if(!m(stack.pop(), c)){
                    return false;
               }
          }
     }
     return stack.empty();
}