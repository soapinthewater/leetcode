/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#define SUCCESS 1
#define FAIL -1
//typedef char stackElem;

typedef struct stack{
    struct stackNode *top, *base;
}stack;

typedef struct stackNode{
    struct stackNOde *next;
    //stackElem val;
    char val;
}stackNode;
 
void stackInit(stack *s){
    
    s->top = s->base = (stackNode*)malloc(sizeof(stackNode));
    s->top->next = NULL;
    s->top->val = '#';
}

void stackPush(stack *s, char x){
    s->top->val = x;
    stackNode *p = (stackNode*)malloc(sizeof(stackNode));
    p->next = s->top;
    s->top = p;
    printf("%c", x);

}

int stackPop(stack *s, char *x){
    
    if(s->top != s->base){
        stackNode *p = s->top;
        s->top = s->top->next;
        *x = s->top->val;
        free(p);
        return SUCCESS;
    }
    else 
        return FAIL;
}

bool isValid(char * s){
    char *p = s;
    char buff;
    stack st;
    stackInit(&st);

    while(*p != '\0'){
        if( ')'||']'||'}' == *p){
            if(SUCCESS == stackPop(&st, &buff)){
                if(*p - buff > 2)
                    return false;
                else
                    printf("%c", *p);
                    
            }
            else
                return false;   
        }

        if( '('||'['||'{' == *p){
            stackPush( &st,*p);
        }

        p++;
    }

    if(FAIL == stackPop(&st, buff))
        return true;
    else
        return false;
}


// @lc code=end

