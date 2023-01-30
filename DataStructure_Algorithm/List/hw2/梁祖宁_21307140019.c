#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<malloc.h>

typedef struct WNode{
    int id;
    int ability;
    int score;
    int coins;
    struct WNode *next;
}WorkList;//定义矿工能力链表

typedef struct LNode{
    int id;
    int coins;
    int date;

    struct LNode* next;
}LinkNode;//定义挖矿记录链表


//记录链表函数
LinkNode* CreateEmptyList();//创建空链表
LinkNode* List_pushback(LinkNode* prior,int id,int coins,int date);//链表尾插法添加元素

//矿工能力链表函数
WorkList* CreateEmptyWList();
WorkList* WList_pushback(WorkList* prior,int id,int ability);//链表尾插法添加元素

int main()
{
    int workers_num;//第一行输入
    int i,d,r,times;//临时变量
    int id=1,ability;//第二行输入
    int days; //第三行输入
    int total_score=0,good_peoples=0;//记录总分（判断是否全0），记录有成绩的人数
    scanf("%d",&workers_num);//获取工人数量
    
    WorkList* w_head = CreateEmptyWList();//创建工人名单链表
    WorkList* wn=w_head;

    LinkNode* head = CreateEmptyList();//创建金币收入记录表
    LinkNode* n = head;

    for(i=0;i<workers_num;i++)
    {
        if(scanf("%d",&ability))
            wn=WList_pushback(wn,id++,ability);
        else break;
    }//给每个矿工的对应能力、编号赋值，输入进链表WorkList
    
    srand(time(NULL));

    scanf("%d",&days);
    for(d=0;d<days;d++)//开始挖矿,遍历日期
    {
        total_score=0;good_peoples=0;//初始化
        for(wn=w_head->next;wn!=NULL;wn=wn->next)
            wn->score=0;//初始化矿工成绩参数
        for(wn=w_head->next;wn!=NULL;wn=wn->next)//遍历每个矿工
        {
            for(times=0;times<wn->ability;times++)//遍历挖矿能力
            {
                r=rand()%1000+1;
                if(r>=991 && r<=1000)
                    wn->score++;//记录挖到矿的次数score
            }
        }

        
        for(wn=w_head->next;wn!=NULL;wn=wn->next)// 统计今日挖矿数据
        {
            total_score+=wn->score;
            if(wn->score>0)
                good_peoples++;
        }
        if(good_peoples==0) continue;//判断是否为全0
        
        if(good_peoples==1)//判断是否只有一个人有成绩
        {
            for(wn=w_head->next;wn!=NULL;wn=wn->next)
                if(wn->score>0)
                    {
                        n=List_pushback(n,wn->id,50,d);
                        wn->coins+=50;
                    }//记录唯一挖到矿的人获得金币
        }
        //计算哪个矿工获得奖励
        else
        {
            r=rand()%total_score;
            for(wn=w_head->next;wn!=NULL;wn=wn->next)
            {
                if(wn->score==0) continue;//跳过没挖到的人
                if(wn->score>r) 
                {
                    n=List_pushback(n,wn->id,50,d);
                    wn->coins+=50;
                }//找到了挖到矿的人
                if(wn->score<r) r-=wn->score;//让r减去当前的数，去和下一个有成绩的人比对
            }
        }
    }

    for(wn=w_head->next;wn!=NULL;wn=wn->next)//输出挖矿成绩
    {
        printf("Worker %d : %d\n",wn->id,wn->coins);
    }
    
    // for(n=head->next;n!=NULL;n=n->next)//输出挖矿记录
    // {
    //     printf("id:%d\tdate:%d\n",n->id,n->date);
    // }



    return 0;
}

LinkNode* CreateEmptyList(){
    LinkNode* n= (LinkNode*)malloc(sizeof(LinkNode));
    n->id=-1;
    n->coins=-1;
    n->date = -1;
    n->next=NULL;
    return n;
}

LinkNode* List_pushback(LinkNode* prior,int id,int coins,int date){

    LinkNode* n= (LinkNode*)malloc(sizeof(LinkNode));
    n->next=NULL;
    n->id=id;
    n->coins=coins;
    n->date=date;
    prior->next=n;
    return n;
}

WorkList* CreateEmptyWList(){
    WorkList* wn= (WorkList*)malloc(sizeof(WorkList));
    wn->ability = -1;
    wn->id = -1;
    wn->score = -1;
    wn->coins = -1;
    wn->next = NULL;

    return wn;
}

WorkList* WList_pushback(WorkList* prior,int id,int ability){
    WorkList* wn= (WorkList*)malloc(sizeof(WorkList));
    wn->next=NULL;
    wn->id=id;
    wn->score=0;
    wn->coins =0;
    wn->ability = ability;
    prior->next=wn;
    return wn;
}