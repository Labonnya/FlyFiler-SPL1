#include<bits/stdc++.h>
using namespace std;

#define Z 'Z'
#define CAN_NOT_POP -1
int q0=0, q1=1, qf=2;
int EMPTY_STACK_BUT_STRING_REMAINS=100;
stack<int>pda_stack;

//functions
int push(int c_state, char alpha, char s_top);
int pop(int c_state, char alpha, char s_top);
void clear_stack();
bool npda(string str);


int main(void)
{
    string str;
    cin >> str;
    cout << npda(str) << endl;
    return 0;
}

int push(int c_state, char alpha, char s_top)
{
        if(c_state == q0 && alpha == 'a' && s_top == Z)
            {

            printf("push(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.push(alpha);
            return q1;

            }

        else if(c_state == q0 && alpha == 'a' && s_top == 'a')
            {

            printf("push(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.push(alpha);
            return q1;


            }

        else if(c_state == q0 && alpha == 'b' && s_top == Z)
            {

            printf("push(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.push(alpha);
            return q0;

            }

        else if(c_state == q0 && alpha == 'b' && s_top=='b')
        {
            printf("push(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.push(alpha);
            return q0;

        }
        else if(c_state == q0 && alpha == 'a' && s_top == 'b')
        {

            printf("push(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.push(alpha);
            return q0;

        }

        else if(c_state == q0 && alpha == 'b' && s_top=='a')
        {

            printf("push(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.push(alpha);
            return q0;

        }

        else
        {

            printf("Unknown Push command!\n");
            exit(1);

        }
}
int pop(int c_state, char alpha, char s_top)
{
        if(c_state == q0 && alpha == 'a' && s_top == Z)
            {

            printf("Pop(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.pop();
            return q1;

            }

        else if(c_state == q0 && alpha == 'a' && s_top == 'a')
            {

            printf("pop(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.pop();
            return q1;


            }

        else if(c_state == q0 && alpha == 'b' && s_top == Z)
            {

            printf("pop(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.pop();
            return q1;

            }

        else if(c_state == q0 && alpha == 'b' && s_top=='b')
        {
            printf("pop(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.pop();
            return q1;

        }
        else if(c_state == q0 && alpha == 'a' && s_top == 'b')
        {

            printf("pop(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.pop();
            return q1;

        }

        else if(c_state == q0 && alpha == 'b' && s_top=='a')
        {

            printf("pop(%d,%c,%c)\n",c_state, alpha, s_top);
            pda_stack.pop();
            return q1;

        }

        else
    {

        return CAN_NOT_POP;
    }
}
void clear_stack()
{
    while(!pda_stack.empty()) pda_stack.pop();
}

bool npda(string str){
  bool value = false;

  for(int mid_point = 1; mid_point < str.size()-1; mid_point++){
        int c_state = q0;
        clear_stack();
        pda_stack.push(Z);

	printf("Assumed mid = %d-----------------\n",mid_point);

	int i = 0;
        for(i = 0; i < str.size(); i++){
            if(i < mid_point)
                {
                    c_state = push(c_state, str[i], pda_stack.top());
                }
            else if(i >= mid_point)
            {
                c_state = pop(c_state, str[i], pda_stack.top());
            }

            if(pda_stack.size() == 1)
            {
                value=false;
                break;
            }
            else if(c_state==CAN_NOT_POP)
            {
                value=false;
                break;
            }
        }
        c_state = pop(c_state, '\0', pda_stack.top());

        if(c_state==qf && i==str.size()-1)
            {
              return true;
            }

  }
  return value;
}

