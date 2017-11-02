#include <iostream>
using namespace std;

#include "Mano.h"


//functions
void deal(Deck &deckJuego, Mano &ManoD, Mano &ManoJ)
{
    deckJuego.shuffle();
    ManoJ = *new Mano (deckJuego);
    ManoD = *new Mano (deckJuego);
    
    cout<<"Dealer's hand: "<<endl<<endl;
    ManoD.printD();
    cout<<endl<<endl<<"Your hand: "<<endl<<endl;
    ManoJ.printJ();
    
}

void hit(Mano &ManoJ,Mano ManoD, Deck &deckJuego, bool &disableOptions, int &score)
{
    cout<<endl<<"Dealer's hand: "<<endl<<endl;
    ManoD.printD();
    
    cout<<endl<<"Your hand: "<<endl<<endl;
    ManoJ.getCarta(deckJuego);
    ManoJ.printJ();
    
    if (ManoJ.getscore() > 21)
    {
        cout<<"Busted, your hand is above 21."<<endl;
        score--;
        cout<<endl<<"Your score is: "<<score<<endl;
        disableOptions = true;
    }
}

void hitCardsD(Mano &ManoD, Mano ManoJ, Deck &deckJuego)
{
    while(
          (ManoD.getMinSumaGanadora() < 17 || ManoD.getMaxSumaGanadora() < 17) &&
          ManoD.getMinSumaGanadora() < ManoJ.getscore() &&
          ManoD.getMaxSumaGanadora() < ManoJ.getscore()
          )
        
    {
        ManoD.getCarta(deckJuego);
    }
}

void declareWinner(Mano &ManoD, Mano ManoJ, bool &disableOptions, int &score)
{
    if (ManoJ.getscore() > 21)
    {
        cout<<"Busted, dealer's hand is: "<<endl;
        ManoD.printJ();
        score--;
        
    }
    else if (ManoD.getscore() >= ManoJ.getscore() && ManoD.getscore() <= 21)
    {
        cout<<"Busted, dealer's hand is:"<<endl;
        ManoD.printJ();
        score--;
    }
    else
    {
        cout<<"You won, dealer's hand is:"<<endl;
        ManoD.printJ();
        score++;
    }
    cout<<endl<<"Your score is: "<<score<<endl;
    disableOptions = true;
    
}

void stand(Mano &ManoD, Mano ManoJ, Deck &deckJuego, bool &disableOptions, int &score)
{
    hitCardsD(ManoD, ManoJ, deckJuego);
    declareWinner(ManoD, ManoJ, disableOptions, score);
}

int main()
{
    Deck deckJuego;
    Mano manoJ(deckJuego);
    Mano manoD(deckJuego);
    bool disableOptions = false;
    int score = 0;
    
    cout<<"BlackJack:"<<endl<<endl;
    
    cout<<"============================================"<<endl<<endl;
    deal(deckJuego, manoD, manoJ);
    
    char controller = 'r';
    cout<<endl<<"============================================"<<endl<<endl;
    cout<<"Next move:  Hit (h), Deal (d), Stand (s), Exit (e) "<<endl;
    cin>>controller;
    
    while(controller != 'e')
    {
        switch (controller)
        {
            case 'h':
                if (!disableOptions)
                {
                    hit(manoJ, manoD, deckJuego, disableOptions, score);
                }
                break;
            case 'd':
                disableOptions = false;
                deal(deckJuego, manoD, manoJ);
                break;
            case 's':
                if (!disableOptions)
                {
                    stand(manoD, manoJ, deckJuego, disableOptions, score);
                }
                break;
        }
        if (!disableOptions)
        {
            cout<<endl<<"============================================"<<endl<<endl;
            cout<<"Next move: Hit (h), Deal (d), Stand (s), Exit (e) "<<endl;
        }
        else
        {
            cout<<endl<<"============================================"<<endl<<endl;
            cout<<"Next move: Deal (d), Exit (e) "<<endl;
        }
        cin>>controller;
    }
    
    return 0;
}

