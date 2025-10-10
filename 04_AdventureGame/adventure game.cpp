#include <iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
using namespace std;
bool flag=false;//角色是否死亡
bool result=true;//是否挑战成功
bool send_potion=false;//是否拥有传送药水
bool success = false; // 是否成功过悬崖的标志
bool teeth=false;//是否拥有狼毫
vector<string>monster;//
//定义一个战斗机制
void fight(int *attack,int *health,int enemy_attack,int enemy_health,string a)
{
    cout<<"你正在与"<<a<<"战斗"<<endl;
    *(health)-=enemy_attack;
    if(*(health)<=0){
        flag=true;
    }
    else{
    if(*(attack)>=enemy_health){
        cout<<"恭喜你，战斗胜利"<<endl;
        cout<<"你的剩余生命值为："<<*(health)<<endl;
      result=true;
    }
    else{
        cout<<"你攻击了"<<a<<",但是没有战胜它"<<endl;

        cout<<"你的剩余生命值为："<<*(health)<<endl;
        result=false;
        cout<<"你没有获得任何奖励。"<<endl;
    }
    }
}
int main() {
    // 游戏加载
    string playerName;
    string weapon = "铁剑";
    int attack = 100;
    int health = 300;
    int* myhealth=&health;
    int*myattack=&attack;
    int enemy_attack=0;
    int enemy_health=0;
    int luck_num;//记录复活次数
    //游戏开始
    cout << "欢迎来到冒险对话游戏！" << endl;
    cout << "请输入你的名字: ";
    cin >> playerName;
      // 游戏身份加载
    cout << "你好，" << playerName << endl;
    cout << "你的初始武器: " << weapon << endl;
    cout << "你的攻击力: " << attack<< endl;
    cout << "你的生命值: " << health << endl;

    // 第一条岔路口,
    cout << "根据藏宝图的指引，你面前有两条路，左边通往密林，右边通往山洞，你会选择哪条路？\n(请输入左/右)" << endl;
    string choice;
    rechoice1:
    cin >> choice;
    if (choice == "左") {
        // 密林情节一:与熊战斗
        there:
        cout << "你进入了密林。" << endl;
        cout << "你面前有一只黑熊(生命值：50，攻击力：90)，你发现他的身后有一个宝箱，你选择：" << endl;
        monster.push_back("黑熊");
        cout << "1. 安静的离开，不惊动黑熊，继续往前走" << endl;
        cout << "2. 与黑熊战斗" << endl;
        int choice_num;
        cin >> choice_num;

        if(choice_num==1) {
            cout << "你安静地离开了黑熊，继续往前走。" << endl;
        }

        else if (choice_num == 2) {
            // 与黑熊战斗
            cout<<"你决定与黑熊战斗"<<endl;
            enemy_attack= 90;
            enemy_health= 50;
            fight(myattack,myhealth,enemy_attack,enemy_health,"黑熊");
            if(flag){return 0;}
            if(result){
            cout << "你得到了宝箱，打开宝箱，你获得了一把弓箭（攻击力+100）和一瓶小型回复药水(生命值+50)。" << endl;
            attack+=100;
            health+=50;}

            cout<<"你当前的攻击力为:"<<attack<<",你当前的生命值为："<<health<<endl;
        }

        // 密林情节二：跨越沼泽
        cout << "你继续往前走，发现了一片沼泽，你选择：" << endl;
        rechoose:
        cout << "1. 找别的路" << endl;
        cout << "2. 硬闯沼泽" << endl;
        int option;
        cin >> option;
        if (option== 1) {
            cout << "你找到了别的路，走出了密林。" << endl;
        }
        else if (option == 2) {
            cout << "你决定硬闯沼泽。" << endl;
            cout<<"硬闯沼泽，你不幸受伤（生命值-20）"<<endl;
            health-=20;
            if(health<=0){
                    cout<<"生命值不足，游戏结束"<<endl;
                    return 0;}
            cout<<"你当前的攻击力为:"<<attack<<",当前生命值为："<<health<<endl;
        }
    //若玩家选择无效，重新选择
    else {
        cout<<"无效选项，请重新选择"<<endl;
        goto rechoose;}
    }
    else if (choice == "右") {
        // 山洞情节一：三只蝙蝠
        cout << "你进入了山洞。" << endl;
        cout << "你点燃了火把，发现有蝙蝠(生命值：90，攻击力：60)正在守护一个宝箱，你选择：" << endl;
        monster.push_back("蝙蝠");
        cout << "1. 躲避蝙蝠的攻击，拼命往前跑" << endl;
        cout << "2. 与蝙蝠战斗" << endl;
        int choice_num;
        cin >> choice_num;
   if(choice_num==1) {
            cout << "你安静地离开了蝙蝠，继续往前走。" << endl;
        } else if (choice_num == 2) {
            // 与蝙蝠战斗
            enemy_attack= 60;
            enemy_health= 90;
            fight(myattack,myhealth,enemy_attack,enemy_health,"蝙蝠");
            if(flag){return 0;}
            if(result){
            cout << "你得到了宝箱，打开宝箱，你获得了法杖（攻击力+150）。" << endl;
            attack+=100;}
            cout<<"你当前的攻击力为:"<<attack<<",你当前的生命值为："<<health<<endl;
        }

            //山洞情节二：传送
          cout<<"你继续往前走"<<endl;
          cout<<"你遇到了邪恶的魔法师，他施展传送魔法，你被传送至密林"<<endl;
          goto there;
        }

    //若玩家选择无效，重新选择
    else {
        cout<<"无效选项，请重新选择"<<endl;
        goto rechoice1;}
    //悬崖情节


    cout << "你走出了密林，发现前面是悬崖。你会选择：" << endl;

    while (!success) {
        cout << "1. 跳下悬崖" << endl;
        cout << "2. 绳子攀爬悬崖" << endl;
        cout << "3. 滑翔翼飞过悬崖" << endl;

        int choice;
        cout << "请输入你的选择（1, 2, 或 3）: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "你选择跳下悬崖。很不幸，你的生命值降为1。" << endl;
                health = 1;
                cout<<"你当前的生命值为："<<health<<endl;
                success = true; // 成功过悬崖，跳出循环
                break;
            case 2:
                cout << "你选择使用绳子攀爬悬崖。被尖锐的岩石刺到，你的生命值-50。" << endl;
                health -= 50;
                cout<<"你当前的生命值为："<<health<<endl;
                success=true;
                break;
            case 3:
                cout << "你选择使用滑翔翼飞过悬崖。" << endl;
                success = true; // 成功过悬崖，跳出循环
                break;
            default:
                cout << "无效的选择。请重新选择。" << endl;
                continue; // 无效选择，继续下一轮循环
        }
    }

            cout << "成功通过悬崖，你的当前生命值: " << health << endl;

    //第二条岔路口
     cout << "当你通过悬崖，你面前有两条路，左边通往魔法小镇，右边通往魔法森林，你会选择哪条路？(请输入左/右)" << endl;
     string second_option;
     rechoice2:
     cin>>second_option;
     if(second_option=="左"){
            cout<<"你来到了魔法小镇"<<endl;
             //魔法小镇情节一：狼人
            cout<<"夜深人静时，在月光下你看见前面有人影，你选择"<<endl;
            monster.push_back("狼人");
            cout << "1. 不惊动他，悄悄离开" << endl;
            cout << "2. 上前寻求帮助" << endl;
            int third_option;
            cin >> third_option;
        if (third_option== 1) {
            cout << "借月色，你发现了那个人影正在变大，他是狼人！你悄悄离开。" << endl;
            }
        else if (third_option == 2) {
            cout << "借月色，你发现了那个人影正在变大，他是狼人(生命值：150，攻击力：100)！" << endl;
            cout<<"你与狼人展开战斗"<<endl;
            enemy_attack= 100;
            enemy_health= 150;
            fight(myattack,myhealth,enemy_attack,enemy_health,"狼人");
            if(flag){return 0;}
            if(result){
            cout << "战斗胜利，你得到了狼毫。" << endl;
            teeth=true;}

            cout<<"你当前的攻击力为:"<<attack<<",你当前的生命值为："<<health<<endl;
               }
           cout<<"你继续往前走，你遇见了女巫，她给你一次得到一瓶魔法药水的机会。"<<endl;
           cout<<"女巫在不同药水上贴上了不同的标签，不同药水对应不同数字"<<endl;
           potion_again:
           cout<<"请你输入数字1~7中的1个数字来获得一瓶对应的魔法药水。"<<endl;
           int potion_num;
                cout<<"请你输入魔法药水的序号："<<endl;
            cin>>potion_num;

            switch (potion_num) {
            case 1:
                cout << "你喝下了攻击力提升药水，攻击力翻倍" << endl;
                attack*=2;
                cout<<"你当前的攻击力为："<<attack<<endl;
                break;
            case 2:
                cout << "你喝下了攻击力减弱药水，攻击力减半" << endl;
                attack/=2;
                cout<<"你当前的攻击力为："<<attack<<endl;
                break;
            case 3:
                cout << "你喝下了传送药水，将会在离开魔法小镇时被传送至魔法森林。" << endl;
                send_potion=true;
                break;
            case 4:
                cout << "你喝下了复活药水，当生命值降为0时，恢复至300" << endl;
                luck_num++;
                break;
            case 5:
                cout << "你喝下了恢复药水，生命值+100。" << endl;
                health+=100;
                if(health>=300)health=300;
                cout<<"你当前的生命值为："<<health<<endl;
                break;
            case 6:
            cout << "你喝下了幸运药水，女巫决定帮助你一起打败恶龙" << endl;
             goto good_end;
            break;
            case 7:
                cout<<"你喝下了毒药，生命值-50"<<endl;
                health-=50;
                if(health<=0&&luck_num==0){
                    cout<<"生命值不足，游戏结束"<<endl;
                        return 0;}
                if(health<=0&&luck_num!=0){
                    cout<<"复活药水生效，生命值回满"<<endl;
                    health=300;
                }
                cout<<"你当前的生命值为："<<health<<endl;
            default:
                cout << "无效的选择。请重新选择。" << endl;
                // 无效选择，继续下一轮循环
        }

     if(teeth){
     cout<<"女巫注意到你拥有狼毫，你用狼毫与她交换，你再获得一次抽取魔法药水的机会"<<endl;
     teeth=false;
     goto potion_again;}

      cout<<"你离开了魔法小镇"<<endl;
      if(send_potion)goto magic_forest;
        }
     //进入魔法森林
     else if(second_option=="右"){
        magic_forest:
       cout<<"你进入了魔法森林，由于神秘力量的影响，森林里的怪物更强了，同时你获得魔法祝福，若战斗胜利则不会扣除你的生命值，你会不停地与你所遇到过的怪物战斗，每次与森林里的敌人战斗胜利时会得到宝箱。你只有当攻击力大于等于500时，才能离开魔法森林。"<<endl;
     while(attack<500){
            for(const auto& str : monster){
                    if(str=="黑熊"){
                        enemy_attack=100;
                        enemy_health=100;
                        cout<<"你遇到了黑熊（攻击力：100，生命值：100）"<<endl;
                    }
                    if(str=="蝙蝠"){
                        enemy_attack=80;
                        enemy_health=100;
                         cout<<"你遇到了蝙蝠（攻击力：80，生命值：100）"<<endl;
                    }
                    if(str=="狼人"){
                        enemy_attack=120;
                        enemy_health=200;
                         cout<<"你遇到了狼人（攻击力：150，生命值：200）"<<endl;
                    }
                    int win_choice=0;//记录玩家战斗胜利后选择的奖励
               fight(myattack,myhealth,enemy_attack,enemy_health,str);
               if(health<=0&&luck_num!=0){
                    cout<<"复活药水生效，生命值回满"<<endl;
                    health=300;
                    flag=false;
                }
               else if(flag){
                cout<<"生命值不足，游戏结束"<<endl;
                return 0;
               }
               if(result){
                cout<<"由于魔法祝福，你将恢复本场战斗扣除的生命值"<<endl;
                health+=enemy_attack;
                if(health>=300)health=300;
                cout<<"你当前的生命值为："<<health<<endl;
                cout<<"你可以从宝箱中选择一个奖励："<<endl;

                rechoice:
                cout<<"1.强力恢复药水(生命值+150)"<<endl;
                cout<<"2.获得弓箭(攻击力+100)"<<endl;
                cin>>win_choice;
               }
               else continue;
               if(win_choice==1){
                  health+=150;
                if(health>=300)health=300;
                cout<<"你当前的生命值为："<<health<<",你当前的攻击力为："<<attack<<endl;
               }
               else if(win_choice==2){
                attack+=100;
                cout<<"你当前的生命值为："<<health<<",你当前的攻击力为："<<attack<<endl;
               }
               else {
                    cout<<"无效选项，请重新选择"<<endl;
               goto rechoice;}
               if(attack>=500)break;
            }

     }
        cout << "你的攻击力已达到500以上，成功逃出了神秘的魔法密林！" << endl;
     }
    //若玩家选择无效，重新选择
    else {
        cout<<"无效选项，请重新选择"<<endl;
        goto rechoice2;}
       //决战开始
       cout<<"你发现面前出现了一只巨大的恶龙，你知道这是最后的关卡了"<<endl;
       cout<<"你与恶龙展开战斗"<<endl;
            enemy_attack= 200;
            enemy_health= 400;
            fight(myattack,myhealth,enemy_attack,enemy_health,"恶龙");

           if(flag){
                cout<<"战斗失败，生命值不足，游戏结束"<<endl;
                return 0;
               }
            if(result){
                good_end:
                cout<<"恶龙被击败以后，你找到了传说中的宝藏。恭喜你成功通过游戏！"<<endl;
            }
            else{
                cout<<"你没有击败恶龙，请重新开始游戏。"<<endl;
            }
    return 0;}
