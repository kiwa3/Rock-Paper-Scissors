#include <iostream>
#include <ctime>
#include <string>
using namespace std;
enum enchoic{rock=1,paper=2,scissors=3};
enum enwinner{player=1,computer=2,draw=3};
struct stRoundResult
{
    short roundnumber=0;
    enchoic playerchoic;
    enchoic computerchoic;
    enwinner thwwinner;
    string winnername="";
};
struct stgameresult
{
    short roundnumber=0;
    short playerwintimes=0;
    short computerwintime=0;
    short drawtime=0;
    enwinner winnerofthegame;
    string nameofthewinnerofthegam="";
};
short getnumberofrounds(){
    short roundsnumber=0;
do
{
cout<<"enter how many games you want to play from 1 to 10 \n";
cin>>roundsnumber;

} while (roundsnumber<=0||roundsnumber>10);

return roundsnumber;

}

int randomnumber(short last,short first){

return rand()%(last-first+1)+first;
}
enchoic computerchoic(){

return (enchoic)randomnumber(3,1);

}
enchoic playerchoic(){
    short number=0;
    do
    {
        cout<<"enter your choic rock[1],paper[2],scissors[3]\n";
        cin>>number;
    
    } while (number<1 || number>3);
    
return (enchoic)number;


}
enwinner checkwinner(stRoundResult roundinfo){
    if (roundinfo.playerchoic==roundinfo.computerchoic)
    {
        return enwinner::draw;
    }
    switch (roundinfo.playerchoic)
    {
    case enchoic::rock:
    if (roundinfo.computerchoic==enchoic::scissors)
    {
        return enwinner::player;
    }
        break;
        case enchoic::paper:
        if (roundinfo.computerchoic==enchoic::rock)
    {
        return enwinner::player;
    }
        break;
        case enchoic::scissors:
        if (roundinfo.computerchoic==enchoic::paper)
    {
        return enwinner::player;
    }

        break;
}
return enwinner::computer;




}
string winnername(enwinner winner){

string arry[3]={"player","computer","draw"};
return arry[winner-1];

}
string choicename(enchoic choic){
string arry[3]={"rock","paper","scissors"};
return arry[choic-1];
}
void printroundresult(stRoundResult roundinfo){
    cout<<"__________round["<<roundinfo.roundnumber<<"]______\n";
    cout<<"player choice:  "<<choicename(roundinfo.playerchoic)<<endl;
    cout<<"computer choice:  "<<choicename(roundinfo.computerchoic)<<endl;
    cout<<"round winner:    "<<roundinfo.winnername<<endl;
    

}
enwinner winnerofthegame(short playerwins,short computerwins){
    if (playerwins>computerwins)
    {
        return enwinner::player;
    }
    else if (computerwins>playerwins)
    {
        return enwinner::computer;
    }
    else return enwinner::draw;
    
    


}
stgameresult playgame(short numberofrounds){
    stRoundResult roundresult;
    short playerwinstime=0;short computerwinstime=0;short drawtime=0;
for (int i = 0; i < numberofrounds; i++)
{
    roundresult.roundnumber=i+1;
    roundresult.computerchoic=computerchoic();
    roundresult.playerchoic=playerchoic();
    roundresult.thwwinner=checkwinner(roundresult);
    roundresult.winnername=winnername(roundresult.thwwinner);
    if (roundresult.thwwinner==enwinner::player)
    {
        playerwinstime++;
    }
    else if(roundresult.thwwinner==enwinner::computer){
        computerwinstime++;
    }
    else{
        drawtime++;
    }
    printroundresult(roundresult);

}

return {roundresult.roundnumber,playerwinstime,computerwinstime,drawtime,winnerofthegame(playerwinstime,computerwinstime),winnername(winnerofthegame(playerwinstime,computerwinstime))};

}
void gameover(){
cout<<"______________________________________\n";
cout<<"_______________game over_____________\n";
cout<<"______________________________________\n\n";


}
void printgameresult(stgameresult gameinfo){
    cout<<"_______gamre Result_________\n";
    cout<<"game rounds     :"<<gameinfo.roundnumber<<endl;
    cout<<"player win times     :"<<gameinfo.playerwintimes<<endl;
    cout<<"COMPUTER win times     :"<<gameinfo.computerwintime<<endl;
    cout<<"DRAW times     :"<<gameinfo.drawtime<<endl;
    cout<<"final winner     :"<<gameinfo.nameofthewinnerofthegam<<endl;




}

void startgame(){
char playagain='Y';
do
{

    stgameresult gameresult=playgame(getnumberofrounds());
    gameover();
    printgameresult(gameresult);
    cout<<"want to play again press 'Y'\n";
    cin>>playagain;

} while (playagain == 'y' || playagain =='Y');




}

int main() {
    srand((unsigned)time(NULL));
   startgame();
    return 0;
}